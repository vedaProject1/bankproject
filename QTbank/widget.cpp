#include "widget.h"
#include "./ui_widget.h"
#include "User.h"
#include "useraccountdisplay.h"
#include "userregister.h"

#include"Admin.h"
#include"func.h"




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
void Widget::login() {
    saveFile(admin.user_list, "./memo.txt");
    qDebug() << "userLogin";
    UserAccountDisplay* userAccountDisPlay =new UserAccountDisplay();
    userAccountDisPlay->show();
}

void Widget::showRegisterWindow() {

    userRegister * regi = new userRegister();
    regi->show();
    qDebug() << "register";
}






