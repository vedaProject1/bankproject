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
    loadFile(admin.user_list, "./memo1.txt");


    QApplication a(argc, argv);
    Widget w;
    w.show();

    return a.exec();

}
