#include "widget.h"
#include "./ui_widget.h"
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
}

void Widget::showRegisterWindow() {

    userRegister * regi = new userRegister();
    regi->show();
    qDebug() << "register";
}

