#include "widget.h"
#include "./ui_widget.h"
#include "User.h"
#include "useraccountdisplay.h"
#include "userregister.h"


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

void Widget::login() {
    qDebug() << "userLogin";
    UserAccountDisplay* userAccountDisPlay =new UserAccountDisplay();
    userAccountDisPlay->show();
}

void Widget::showRegisterWindow() {

    userRegister * regi = new userRegister();
    regi->show();
    qDebug() << "register";
}

