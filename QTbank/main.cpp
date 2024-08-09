#include "widget.h"

#include <QApplication>
#include"Account.h"
#include"Admin.h"
#include"func.h"
#include "Person.h"
#include "User.h"
#include<vector>

Admin admin;

int main(int argc, char *argv[])
{
    loadFile(admin.user_list, "./memo.txt");


    QApplication a(argc, argv);
    Widget w;
    w.show();
    //saveFile(admin.user_list, "./memo.txt");// 여기서 안됨
    return a.exec();

}
