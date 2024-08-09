//
// Created by lee on 2024. 8. 9..
//

// You may need to build the project (run Qt uic code generator) to get "ui_UserAccountDisplay.h" resolved

#include "useraccountdisplay.h"
#include "ui_UserAccountDisplay.h"


UserAccountDisplay::UserAccountDisplay(QWidget *parent) :
    QWidget(parent), ui(new Ui::UserAccountDisplay) {
    ui->setupUi(this);
}

UserAccountDisplay::~UserAccountDisplay() {
    delete ui;
}

void UserAccountDisplay::setUserInfo(User user) {
    this->ui->userName->setText(QString::fromStdString(user.get_name()));
    this->ui->userBalance->setText(QString::number(user.get_user_account().get_balance()));
    this->ui->userAccountNumber -> setText(QString::number(user.get_user_account().get_account_num()));
}
