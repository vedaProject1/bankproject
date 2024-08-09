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

void UserAccountDisplay::setUserInfo(User user) {
    this->ui->userName->setText(QString::fromStdString(user.get_name()));
    this->ui->userBalance->setText(QString::number(user.get_user_account().get_balance()));
    this->ui->userAccountNumber -> setText(QString::number(user.get_user_account().get_account_num()));
}
