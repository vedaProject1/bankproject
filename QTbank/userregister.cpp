//
// Created by lee on 2024. 8. 9..
//

// You may need to build the project (run Qt uic code generator) to get "ui_userRegister.h" resolved

#include "userregister.h"
#include "ui_userRegister.h"
#include"Admin.h"
#include<QMessageBox>
extern Admin admin;

userRegister::userRegister(QWidget *parent) :
    QWidget(parent), ui(new Ui::userRegister) {
    ui->setupUi(this);
}

userRegister::~userRegister() {
    delete ui;
}


#include<QLineEdit>
void userRegister::registerUser() {

    QString id = ui->lineEdit_id->text();   // ID 입력 값
    QString pw = ui->lineEdit_pw->text();   // PW 입력 값
    QString name = ui->lineEdit_name->text();   // name 입력값

    if (id.isEmpty() || pw.isEmpty() || name.isEmpty()) {
        QMessageBox::warning(this, "ERROR", "All fields must be filled out.",
                            QMessageBox::Ok);
        return;
    }

    int bankIndex = ui->ComboBox_bank->currentIndex();
    qDebug() << id;
    qDebug() << pw;
    qDebug() << name;
    qDebug() << bankIndex;

    string i=id.toStdString();
    string p=pw.toStdString();
    string n=name.toStdString();

    vector<Person*>::iterator it;
    bool check = true;
    for (it = admin.user_list.begin(); it != admin.user_list.end(); it++)
    {
        if (i == (*it)->get_id() || i == "admin") {
            QMessageBox::question(this,"ERROR","ID already in use",
                                  QMessageBox::Yes);
            check = false;
        }
    }
    if (check == true){
        User* user = new User(i, p, n);
        user->add_account();
        admin.user_list.push_back(user);
        QMessageBox::question(this,"Complete","join complete",QMessageBox::Yes);
        qDebug() << "join complete\n";
        userRegister::close();

    }
    else {
        ui->lineEdit_id->clear();
        return;
    }
}

