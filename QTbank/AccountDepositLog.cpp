//
// Created by lee on 2024. 8. 10..
//

#include "AccountDepositLog.h"
#include "User.h"

AccountDepositLog::AccountDepositLog(User *user, std::shared_ptr<Account> account, long long deposit_amount): user(user), deposit_amount(deposit_amount) ,account (account) ,balance(account->get_balance()) {
}

User * AccountDepositLog::get_loged_user() {
    return this->user;
}

std::string AccountDepositLog::show_log() {
    return "user :" +user->get_name()+ ", accountNumber: " + std::to_string(account->get_account_num())+ ", deposit: "  +  std::to_string(deposit_amount)+ " " + ", balance: " + std::to_string(balance);
}

void AccountDepositLog::save(std::ofstream &outFile) {

    outFile << "D" << '\n';
    outFile << user->get_id() << '\n';
    outFile << account->get_account_num() << '\n';
    outFile << deposit_amount << '\n';
    outFile << balance << '\n';
}

