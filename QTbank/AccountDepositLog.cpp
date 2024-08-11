//
// Created by lee on 2024. 8. 10..
//

#include "AccountDepositLog.h"

#include <QtCore>

AccountDepositLog::AccountDepositLog(User *user, shared_ptr<Account> account, long long deposit_amount): user(user), deposit_amount(deposit_amount) ,account (account) {
}

std::string AccountDepositLog::show_log() {
    return "user :" +user->get_name()+ ", accountNumber: " + std::to_string(account->get_account_num())+ ", deposit: "  +  std::to_string(deposit_amount)+ " " + ", balance: " + std::to_string(account->get_balance());
}

