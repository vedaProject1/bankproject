//
// Created by lee on 2024. 8. 13..
//

#ifndef ACCOUNTTRANSFERWINDOW_H
#define ACCOUNTTRANSFERWINDOW_H

#include <QWidget>

#include "User.h"


QT_BEGIN_NAMESPACE
namespace Ui { class AccountTransferWindow; }
QT_END_NAMESPACE

class AccountTransferWindow : public QWidget {
Q_OBJECT
User * user ;
long long current_account_number;
public:
    explicit AccountTransferWindow(QWidget *parent = nullptr);
    ~AccountTransferWindow() override;

void setUser(User *user, QString account_number);

public slots:
    void transfer();
private:
    Ui::AccountTransferWindow *ui;
};


#endif //ACCOUNTTRANSFERWINDOW_H
