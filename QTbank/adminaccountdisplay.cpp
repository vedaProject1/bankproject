//
// Created by lee on 2024. 8. 12..
//

// You may need to build the project (run Qt uic code generator) to get "ui_AdminAccountDisplay.h" resolved

#include "adminaccountdisplay.h"

#include "Account.h"
#include "AccountLogger.h"
#include "Admin.h"
#include "ui_AdminAccountDisplay.h"

extern Admin admin;

AdminAccountDisplay::AdminAccountDisplay(QWidget *parent) :
    QWidget(parent), ui(new Ui::AdminAccountDisplay) {
    ui->setupUi(this);
    ui->userAccountList->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->userAccountTransaction ->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->allTransaction->setEditTriggers(QAbstractItemView::NoEditTriggers);
    show_all_transaction_logs();
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

    int idx = admin.search_user_return_idx(ui->idSearch->text().toStdString());
    if(idx == 1000) return;

    ui->userName->setText(QString::fromStdString(admin.user_list[idx]->get_name()));
    ui->userBalance->setText(QString::number(admin.user_list[idx]->get_user_account().get_balance()));
    // ????? ???? ????
    vector<shared_ptr<Account>> accountList = dynamic_cast<User* >(admin.user_list[idx])->get_all_accounts();
    foundUser = static_cast<User*>(admin.user_list[idx]);
    QStringList initialData;

    for(int i =0; i<accountList.size(); i++) {

        initialData.push_back(QString::number(accountList.at(i)->get_account_num()));

    }
    account_list_model = new QStringListModel(this);
    account_list_model->setStringList(initialData);
    ui->userAccountList->setModel(account_list_model);

    //???? ?ес?? ??????? ??????
    User *user = dynamic_cast<User*>(admin.user_list[idx]);

    std::vector<std::string> result = logger.get_all_user_logs(ui->idSearch->text().toStdString());
    QStringList userTransactionalData;
    if(result.size()==0 )return;
    for(string res : result) userTransactionalData.push_back(QString::fromStdString(res));
    QStringListModel* userAccountTransactionModel = new QStringListModel(this);
    userAccountTransactionModel->setStringList(userTransactionalData);
    ui->userAccountTransaction->setModel(userAccountTransactionModel);
}

void AdminAccountDisplay::on_item_clicked(const QModelIndex &index) {
    qDebug() << "cliceked";
    QString itemText =  account_list_model->data(index, Qt::DisplayRole).toString();

    long long account_number =itemText.toLongLong();

    shared_ptr<Account> user_account = foundUser->get_user_account_shared(account_number);
    ui->userBalance->setText(QString::number(user_account->get_balance()));
    // ui->userAccountNumber -> setText(QString::number(user_account->get_account_num()));
    // BANK_NAME bank_id = user_account->get_bank_name();
    // ui->accountBank -> setText(QString::fromStdString(user_account->get_bank_name_str(bank_id)));
}
