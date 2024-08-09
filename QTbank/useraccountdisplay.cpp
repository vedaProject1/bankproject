//
// Created by lee on 2024. 8. 9..
//

// You may need to build the project (run Qt uic code generator) to get "ui_UserAccountDisplay.h" resolved

#include "useraccountdisplay.h"
#include "ui_UserAccountDisplay.h"


UserAccountDisplay::UserAccountDisplay(QWidget *parent) : QWidget(parent),ui(new Ui::UserAccountDisplay) {
    ui->setupUi(this);
}

void UserAccountDisplay::set_user(User& user){
    this->user = &user;
    ui->userName->setText(QString::fromStdString(user.get_name()));
    ui->userBalance->setText(QString::number(user.get_user_account().get_balance()));
    ui->userAccountNumber -> setText(QString::number(user.get_user_account().get_account_num()));
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
    user->deposit(account_number,amount);
    qDebug() << "deposit success";
    ui->userBalance->setText(QString::number(user->getBalance(account_number)));


}

void UserAccountDisplay::withdraw_s() {

    int amount =QInputDialog::getInt (this,"Input withDraw Amount", "Input withDraw", QLineEdit::Normal,0);
    long long account_number = ui->userAccountNumber->text().toLongLong();
    qDebug() << account_number;
    user->withDraw(account_number,amount);
    qDebug() << "withDraw success";
    ui->userBalance->setText(QString::number(user->getBalance(account_number)));
}

void UserAccountDisplay::on_item_clicked(const QModelIndex &index) {
    QString itemText = model->data(index, Qt::DisplayRole).toString();
        // "Item 2"가 클릭되었을 때 수행할 작업
        qDebug() << itemText;
        // 여기에 원하는 작업을 추가하세요

}
