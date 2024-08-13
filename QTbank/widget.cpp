#include "widget.h"
#include "./ui_widget.h"
#include "User.h"
#include "useraccountdisplay.h"
#include "userregister.h"

#include"Admin.h"
#include"func.h"
#include<QString>

#include "adminaccountdisplay.h"


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
    //saveFile(admin.user_list, "./memo.txt");// 그냥 저장 되나 테스트

    QString id = ui->lineEdit_id->text();   // ID 입력 값
    QString pw = ui->lineEdit_pw->text();   // PW 입력 값
    qDebug()<<id;
    qDebug()<<pw;


    string login_result_s=login(id.toStdString(),pw.toStdString(), admin.user_list);//Qstring에 string을 넣어줘서 문제가 생김
    QString login_result_qs=QString::fromStdString(login_result_s);
    qDebug()<<login_result_qs;

    //admin.search_user(id.toStdString());

    if (login_result_qs == "loginsucces") {
        int idx = admin.search_user_return_idx(id.toStdString());
        qDebug()<<"person idx:"<<idx;
        // 기존에 생성된 UserAccountDisplay 객체가 있으면 삭제
        //todo: 삭제 여부 검토 필요
        if (userAccountDisplay) {
            delete userAccountDisplay;
        }


    //int idx=admin.search_user_return_idx(id.toStdString());

    //유저를 셋팅해서 보여줌

    User *user = dynamic_cast<User*>(admin.user_list[idx]);
        if(user != nullptr) {
        qDebug() << "user Idx" << idx;
        qDebug() << "founcded user Id" << user->get_id();
        UserAccountDisplay* userAccountDisPlay =new UserAccountDisplay();
        userAccountDisPlay->set_user(*user);
        userAccountDisPlay->show();

        }
    }
    else if(login_result_qs == "admin") {

        qDebug()<< "admin User";
        AdminAccountDisplay * adminDisplay = new AdminAccountDisplay();
        adminDisplay ->show();

    }
}

void Widget::showRegisterWindow() {

    userRegister * regi = new userRegister();
    regi->show();
    qDebug() << "register";
}




void Widget::closeEvent(QCloseEvent *event) {
    saveFile(admin.user_list, "./memo1.txt");
    qDebug() << "Data saved";
    event->accept();  // 기본 동작 수행
}




