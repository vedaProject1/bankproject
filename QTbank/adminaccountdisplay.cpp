//
// Created by lee on 2024. 8. 12..
//

// You may need to build the project (run Qt uic code generator) to get "ui_AdminAccountDisplay.h" resolved

#include "adminaccountdisplay.h"

#include "Account.h"
#include "AccountLogger.h"
#include "ui_AdminAccountDisplay.h"


AdminAccountDisplay::AdminAccountDisplay(QWidget *parent) :
    QWidget(parent), ui(new Ui::AdminAccountDisplay) {
    ui->setupUi(this);
}

AdminAccountDisplay::~AdminAccountDisplay() {
    delete ui;
}

void AdminAccountDisplay::show_all_transaction_logs() {
    qDebug() << "button clicked all transaction";
    AccountLogger & logger = AccountLogger::getLogger();
    vector<string> result = logger.get_all_logs();

    QStringList initialData;

    for(string res : result) initialData.push_back(QString::fromStdString(res));

    QStringListModel* model = new QStringListModel(this);
    model->setStringList(initialData);
    ui->allTransaction->setModel(model);


}

void AdminAccountDisplay::show_all_withdraw_logs() {
    qDebug() << "button clicked all withDraw logs";
    AccountLogger &logger = AccountLogger::getLogger();
    std::vector<std::string> result = logger.get_all_withdraw_logs();

    QStringList initialData;

    for(string res : result) initialData.push_back(QString::fromStdString(res));
    QStringListModel* model = new QStringListModel(this);
    model->setStringList(initialData);
    ui->allTransaction->setModel(model);

}

void AdminAccountDisplay::show_all_deposit_logs() {

    qDebug() << "button clicked all deposit";
    AccountLogger &logger = AccountLogger::getLogger();
    std::vector<std::string> result = logger.get_all_deposit_logs();

    QStringList initialData;

    for(string res : result) initialData.push_back(QString::fromStdString(res));
    QStringListModel* model = new QStringListModel(this);
    model->setStringList(initialData);
    ui->allTransaction->setModel(model);
}

void AdminAccountDisplay::show_user_transations() {
    qDebug() << "button clicked user transaction";
    AccountLogger &logger = AccountLogger::getLogger();
    std::vector<std::string> result = logger.get_all_user_logs(ui->idSearch->text().toStdString());
    QStringList initialData;
    if(result.size()==0 )return;
    for(string res : result) initialData.push_back(QString::fromStdString(res));
    QStringListModel* model = new QStringListModel(this);
    model->setStringList(initialData);
    ui->userAccountTransaction->setModel(model);
}
