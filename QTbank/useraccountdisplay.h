//
// Created by lee on 2024. 8. 9..
//

#ifndef USERACCOUNTDISPLAY_H
#define USERACCOUNTDISPLAY_H

#include <QWidget>
#include "User.h"


QT_BEGIN_NAMESPACE
namespace Ui { class UserAccountDisplay; }
QT_END_NAMESPACE

class UserAccountDisplay : public QWidget {
Q_OBJECT

public:
    explicit UserAccountDisplay(QWidget *parent = nullptr);
    ~UserAccountDisplay() override;
    void setUserInfo(User user);

void set_user(User& user);
private:
    Ui::UserAccountDisplay *ui;
};


#endif //USERACCOUNTDISPLAY_H
