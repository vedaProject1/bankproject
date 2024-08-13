//
// Created by lee on 2024. 8. 12..
//

// You may need to build the project (run Qt uic code generator) to get "ui_AccountSelectionUI.h" resolved

#include "accountselectionui.h"
#include "ui_AccountSelectionUI.h"


AccountSelectionUI::AccountSelectionUI(QWidget *parent) :
    QWidget(parent), ui(new Ui::AccountSelectionUI) {
    ui->setupUi(this);
}

void AccountSelectionUI::set_user(User *user) {
    setAttribute(Qt::WA_DeleteOnClose);
    this->user = user;
}

AccountSelectionUI::~AccountSelectionUI() {
    qDebug() << "called";
    delete ui;
}

void AccountSelectionUI::add_account_by_number() {
   int index_number = ui->ComboBox_bank->currentIndex();
    user->add_account(index_number);
    close();
}
