//
// Created by lee on 2024. 8. 12..
//

#ifndef ACCOUNTSELECTIONUI_H
#define ACCOUNTSELECTIONUI_H

#include <QWidget>

#include "User.h"


QT_BEGIN_NAMESPACE
namespace Ui { class AccountSelectionUI; }
QT_END_NAMESPACE

class AccountSelectionUI : public QWidget {
Q_OBJECT

public:
    User * user;
    explicit AccountSelectionUI(QWidget *parent = nullptr);
    void set_user(User * user);
    ~AccountSelectionUI() override;
public slots:
    void add_account_by_number();

private:
    Ui::AccountSelectionUI *ui;
};


#endif //ACCOUNTSELECTIONUI_H
