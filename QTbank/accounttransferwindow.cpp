//
// Created by lee on 2024. 8. 13..
//

// You may need to build the project (run Qt uic code generator) to get "ui_AccountTransferWindow.h" resolved

#include "accounttransferwindow.h"

#include <QMessageBox>

#include "Admin.h"
#include "ui_AccountTransferWindow.h"

extern Admin admin;

AccountTransferWindow::AccountTransferWindow(QWidget *parent) :
    QWidget(parent), ui(new Ui::AccountTransferWindow) {
    setAttribute(Qt::WA_DeleteOnClose);
    ui->setupUi(this);
}

AccountTransferWindow::~AccountTransferWindow() {
    delete ui;
}

void AccountTransferWindow::setUser(User *user, QString account_number) {
 this->user = user;
    current_account_number = account_number.toLongLong();
}

void AccountTransferWindow::transfer() {

    vector<Person*>personVector = admin.user_list;
    QString userName = ui->userName->text();
    double amount = ui->amount->text().toDouble();
    long long transfer_account_num = ui->AccountNumber->text().toLongLong();
    auto found_user =find_if(personVector.begin(),personVector.end(),[=](Person * p) {
        return userName.toStdString() == p->get_name();
    });
    if(found_user != personVector.end()) {

        User * transferUser = static_cast<User*>(*found_user);
        std::vector<std::shared_ptr<Account>>  tranferUser_accounts = transferUser->get_all_accounts();

        auto found_user_account =find_if(tranferUser_accounts.begin(),tranferUser_accounts.end(),[=](std::shared_ptr<Account> account)  {
            return account->get_account_num() == transfer_account_num;
        });

        if(found_user_account != tranferUser_accounts.end()) {
            if(amount <= user->get_user_account_shared(current_account_number)->get_balance()) {
                user->get_user_account_shared(current_account_number)->minus(amount);
                (*found_user_account)->plus(amount);

                qDebug() << "transfer success";
                QMessageBox msgBox;
                msgBox.setText("transfer success");
                msgBox.exec();
                close();
                return;
            }else {
                QMessageBox msgBox;
                msgBox.setText("Userbalance is lower than transfer amount");
                msgBox.exec();
                return;
            }

        }
    }

    QMessageBox msgBox;
    msgBox.setText("check User information. transger failed");
    msgBox.exec();

}
