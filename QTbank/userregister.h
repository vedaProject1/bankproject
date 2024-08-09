//
// Created by lee on 2024. 8. 9..
//

#ifndef USERREGISTER_H
#define USERREGISTER_H

#include <QWidget>
#include "Account.h"
#include "Person.h"



QT_BEGIN_NAMESPACE
namespace Ui { class userRegister; }
QT_END_NAMESPACE

class userRegister : public QWidget {
Q_OBJECT

public:
    explicit userRegister(QWidget *parent = nullptr);
    ~userRegister() override;

public slots:
    void registerUser();


private:
    Ui::userRegister *ui;
};


#endif //USERREGISTER_H
