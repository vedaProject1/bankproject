//
// Created by lee on 2024. 8. 9..
//

// You may need to build the project (run Qt uic code generator) to get "ui_userRegister.h" resolved

#include "userregister.h"
#include "ui_userRegister.h"


userRegister::userRegister(QWidget *parent) :
    QWidget(parent), ui(new Ui::userRegister) {
    ui->setupUi(this);
}

userRegister::~userRegister() {
    delete ui;
}

void userRegister::registerUser() {

    qDebug()<< ui->ID->text();
    qDebug() << ui->PW->text();
    qDebug()<< "user register function";

}
