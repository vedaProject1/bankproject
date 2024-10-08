//
// Created by lee on 2024. 8. 9..
//

// You may need to build the project (run Qt uic code generator) to get "ui_UserAccountDisplay.h" resolved

#include "useraccountdisplay.h"

#include <QMessageBox>

#include "accountselectionui.h"
#include "accounttransferwindow.h"
#include "ui_UserAccountDisplay.h"


UserAccountDisplay::UserAccountDisplay(QWidget *parent) : QWidget(parent),ui(new Ui::UserAccountDisplay) {
    ui->setupUi(this);

}

void UserAccountDisplay::set_user(User& user){
    // this->user = &user;

    this->user = &user;
    ui->userName->setText(QString::fromStdString(user.get_name()));
    ui->userBalance->setText(QString::number(user.get_user_account().get_balance()));
    ui->userAccountNumber -> setText(QString::number(user.get_user_account().get_account_num()));

    BANK_NAME bank_id = user.get_user_account().get_bank_name();
    ui->accountBank -> setText(QString::fromStdString(user.get_user_account().get_bank_name_str(bank_id)));

    ui->listView_2->setEditTriggers(QAbstractItemView::NoEditTriggers);
    vector<shared_ptr<Account>> accountList = user.get_all_accounts();
    QStringList initialData;

    for(int i =0; i<accountList.size(); i++) {

        initialData.push_back(QString::number(accountList.at(i)->get_account_num()));

    }
    model = new QStringListModel(this);
    model->setStringList(initialData);


    ui->listView_2->setModel(model);
}


UserAccountDisplay::~UserAccountDisplay() {
    delete ui;
}




void UserAccountDisplay::deposit_s() {
    int amount =QInputDialog::getInt (this,"Input Deposit Amount", "Input Deposit Amount", QLineEdit::Normal,0);
    long long account_number = ui->userAccountNumber->text().toLongLong();
    qDebug() << account_number;
    try {
        user->deposit(account_number,amount);
        ui->userBalance->setText(QString::number(user->getBalance(account_number)));
        qDebug() << "deposit success";
    }
    catch (const std::string& exception) {  // std::string ??????? ???
        QMessageBox msgBox;
        msgBox.setText(QString::fromStdString(exception));  // ???? ??????? ??????
        msgBox.exec();
    } catch (const std::exception& e) {  // std::exception ??? ???? ???
        return;
    }




}

void UserAccountDisplay::withdraw_s() {

    int amount =QInputDialog::getInt (this,"Input withDraw Amount", "Input withDraw", QLineEdit::Normal,0);
    long long account_number = ui->userAccountNumber->text().toLongLong();
    try {
        user->withDraw(account_number,amount);
        qDebug() << "withDraw success";
        ui->userBalance->setText(QString::number(user->getBalance(account_number)));
    }catch (const std::string& exception) {
        QMessageBox msgBox;
        msgBox.setText(QString::fromStdString(exception));  // ???? ??????? ??????
        msgBox.exec();
    }

}

void UserAccountDisplay::on_item_clicked(const QModelIndex &index) {
    QString itemText = model->data(index, Qt::DisplayRole).toString();

    long long account_number =itemText.toLongLong();
    shared_ptr<Account> user_account = user->get_user_account_shared(account_number);

    ui->userBalance->setText(QString::number(user_account->get_balance()));
    ui->userAccountNumber -> setText(QString::number(user_account->get_account_num()));
    BANK_NAME bank_id = user_account->get_bank_name();
    ui->accountBank -> setText(QString::fromStdString(user_account->get_bank_name_str(bank_id)));

}


void UserAccountDisplay::closeEvent(QCloseEvent *event) {

    event->accept();  // ?? ???? ????
}

void UserAccountDisplay::show_generate_account_ui() {

    AccountSelectionUI * ui = new AccountSelectionUI();
    ui->set_user(user);
    ui->show();
    connect(ui,&AccountSelectionUI::destroyed, this,&UserAccountDisplay::refresh_user_account);

}

void UserAccountDisplay::refresh_user_account() {

    qDebug() << " wowowowwow";
    vector<shared_ptr<Account>> accountList = user->get_all_accounts();
    QStringList initialData;

    for(int i =0; i<accountList.size(); i++) {

        initialData.push_back(QString::number(accountList.at(i)->get_account_num()));

    }
    model = new QStringListModel(this);
    model->setStringList(initialData);


    ui->listView_2->setModel(model);
}

void UserAccountDisplay::show_transfer_window() {

    AccountTransferWindow *window = new AccountTransferWindow();
    window->setUser(user,ui->userAccountNumber->text());
    window->show();
    connect(window,&AccountTransferWindow::destroyed,this,&UserAccountDisplay::after_transfer);
}

void UserAccountDisplay::after_transfer() {
    long long account_number =  ui->userAccountNumber->text().toLongLong();

    double balance =user->get_user_account(account_number)->get_balance();
    ui->userBalance->setText(QString::number(balance));

}


