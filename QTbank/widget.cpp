#include "widget.h"
#include "./ui_widget.h"
#include "User.h"
#include "useraccountdisplay.h"
#include "userregister.h"

#include"Admin.h"
#include"func.h"
#include<QString>




Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{


    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


extern Admin admin;
void Widget::login_s() {
    saveFile(admin.user_list, "./memo.txt");// 그냥 저장 되나 테스트

    QString id = ui->lineEdit_id->text();   // ID 입력 값
    QString pw = ui->lineEdit_pw->text();   // PW 입력 값
    qDebug()<<id;
    qDebug()<<pw;

    string login_result_s=login(id.toStdString(),pw.toStdString(), admin.user_list);//Qstring에 string을 넣어줘서 문제가 생김

    QString login_result_qs=QString::fromStdString(login_result_s);
    qDebug()<<login_result_qs;

    //여기에 값을 넣어주면 되고
    UserAccountDisplay* userAccountDisPlay =new UserAccountDisplay();
    userAccountDisPlay->show();
}

void Widget::showRegisterWindow() {

    userRegister * regi = new userRegister();
    regi->show();
    qDebug() << "register";
}






