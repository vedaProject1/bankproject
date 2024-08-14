//
// Created by lee on 2024. 8. 12..
//

#ifndef ADMINACCOUNTDISPLAY_H
#define ADMINACCOUNTDISPLAY_H

#include <QStringListModel>
#include <QWidget>

#include "User.h"


QT_BEGIN_NAMESPACE
namespace Ui { class AdminAccountDisplay; }
QT_END_NAMESPACE

class AdminAccountDisplay : public QWidget {
Q_OBJECT

public:
    explicit AdminAccountDisplay(QWidget *parent = nullptr);
    User * foundUser;
    QStringListModel* account_list_model;
    ~AdminAccountDisplay() override;


public slots:
    void show_all_transaction_logs();
    void show_all_withdraw_logs();
    void show_all_deposit_logs();
    void show_user_transations();
    void on_item_clicked(const QModelIndex &index);

private:
    Ui::AdminAccountDisplay *ui;
};


#endif //ADMINACCOUNTDISPLAY_H
