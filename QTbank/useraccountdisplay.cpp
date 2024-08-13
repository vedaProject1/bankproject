//
// Created by lee on 2024. 8. 9..
//

// You may need to build the project (run Qt uic code generator) to get "ui_UserAccountDisplay.h" resolved

#include "useraccountdisplay.h"

#include <QMessageBox>

#include "accountselectionui.h"
#include "ui_UserAccountDisplay.h"


UserAccountDisplay::UserAccountDisplay(QWidget *parent) : QWidget(parent),ui(new Ui::UserAccountDisplay) {
    ui->setupUi(this);

}

void UserAccountDisplay::set_user(User& user){
    // this->user = &user;

    // // 기존 UI 초기화
    // ui->userName->clear();
    // ui->userBalance->clear();
    // ui->userAccountNumber->clear();
    // ui->listView_2->setModel(nullptr);

    // // 새 사용자 정보로 UI 업데이트
    // ui->userName->setText(QString::fromStdString(user.get_name()));
    // ui->userBalance->setText(QString::number(user.get_user_account().get_balance()));
    // ui->userAccountNumber->setText(QString::number(user.get_user_account().get_account_num()));
    // ui->listView_2->setEditTriggers(QAbstractItemView::NoEditTriggers);
    // vector<shared_ptr<Account>> accountList = user.get_all_accounts();
    // QStringList initialData;

    // for (int i = 0; i < accountList.size(); i++) {
    //     initialData.push_back(QString::number(accountList.at(i)->get_account_num()));
    // }
    // model = new QStringListModel(this);
    // model->setStringList(initialData);

    // ui->listView_2->setModel(model);

    this->user = &user;
    ui->userName->setText(QString::fromStdString(user.get_name()));
    ui->userBalance->setText(QString::number(user.get_user_account().get_balance()));
    ui->userAccountNumber -> setText(QString::number(user.get_user_account().get_account_num()));

    BANK_NAME bank_id = user.get_user_account().get_bank_name();
    ui->accountBank -> setText(QString::fromStdString(user.get_user_account().get_bank_name_str(bank_id)));

    ui->listView_2->setEditTriggers(QAbstractItemView::NoEditTriggers);
    vector<shared_ptr<Account>> accountList = user.get_all_accounts();
    QStringList initialData;

    for(int i =0; i<accountList.size(); i++) {

        initialData.push_back(QString::number(accountList.at(i)->get_account_num()));

    }
    model = new QStringListModel(this);
    model->setStringList(initialData);


    ui->listView_2->setModel(model);
}


UserAccountDisplay::~UserAccountDisplay() {
    delete ui;
}




void UserAccountDisplay::deposit_s() {
    int amount =QInputDialog::getInt (this,"Input Deposit Amount", "Input Deposit Amount", QLineEdit::Normal,0);
    long long account_number = ui->userAccountNumber->text().toLongLong();
    qDebug() << account_number;
    try {
        user->deposit(account_number,amount);
        ui->userBalance->setText(QString::number(user->getBalance(account_number)));
        qDebug() << "deposit success";
    }
    catch (const std::string& exception) {  // std::string 타입으로 받기
        QMessageBox msgBox;
        msgBox.setText(QString::fromStdString(exception));  // 예외 메시지를 보여줌
        msgBox.exec();
    } catch (const std::exception& e) {  // std::exception 타입 예외 처리
        return;
    }




}

void UserAccountDisplay::withdraw_s() {

    int amount =QInputDialog::getInt (this,"Input withDraw Amount", "Input withDraw", QLineEdit::Normal,0);
    long long account_number = ui->userAccountNumber->text().toLongLong();
    try {
        user->withDraw(account_number,amount);
        qDebug() << "withDraw success";
        ui->userBalance->setText(QString::number(user->getBalance(account_number)));
    }catch (const std::string& exception) {
        QMessageBox msgBox;
        msgBox.setText(QString::fromStdString(exception));  // 예외 메시지를 보여줌
        msgBox.exec();
    }

}

void UserAccountDisplay::on_item_clicked(const QModelIndex &index) {
    QString itemText = model->data(index, Qt::DisplayRole).toString();

    long long account_number =itemText.toLongLong();
    shared_ptr<Account> user_account = user->get_user_account_shared(account_number);

    ui->userBalance->setText(QString::number(user_account->get_balance()));
    ui->userAccountNumber -> setText(QString::number(user_account->get_account_num()));
    BANK_NAME bank_id = user_account->get_bank_name();
    ui->accountBank -> setText(QString::fromStdString(user_account->get_bank_name_str(bank_id)));

}


void UserAccountDisplay::closeEvent(QCloseEvent *event) {

    event->accept();  // 기본 동작 수행
}

void UserAccountDisplay::show_generate_account_ui() {

    AccountSelectionUI * ui = new AccountSelectionUI();
    ui->set_user(user);
    ui->show();
    connect(ui,&AccountSelectionUI::destroyed, this,&UserAccountDisplay::refresh_user_account);

}

void UserAccountDisplay::refresh_user_account() {

    qDebug() << " wowowowwow";
    vector<shared_ptr<Account>> accountList = user->get_all_accounts();
    QStringList initialData;

    for(int i =0; i<accountList.size(); i++) {

        initialData.push_back(QString::number(accountList.at(i)->get_account_num()));

    }
    model = new QStringListModel(this);
    model->setStringList(initialData);


    ui->listView_2->setModel(model);
}


