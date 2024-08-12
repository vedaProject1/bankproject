//
// Created by lee on 2024. 8. 9..
//

#ifndef USERACCOUNTDISPLAY_H
#define USERACCOUNTDISPLAY_H

#include <QWidget>
#include "User.h"
#include <QInputDialog>
#include <QStringListModel>
#include<QCloseEvent>


QT_BEGIN_NAMESPACE
namespace Ui { class UserAccountDisplay; }
QT_END_NAMESPACE

class UserAccountDisplay : public QWidget {
Q_OBJECT
    User* user;
    QStringListModel *model;
public:
    explicit UserAccountDisplay(QWidget *parent = nullptr);

void set_user(User& user);


~UserAccountDisplay() override;

public slots:
    void deposit_s();
    void withdraw_s();
    void on_item_clicked(const QModelIndex &index);
    void closeEvent(QCloseEvent *event);


private:
    Ui::UserAccountDisplay *ui;
};


#endif //USERACCOUNTDISPLAY_H
