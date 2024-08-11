//
// Created by lee on 2024. 8. 10..
//

#include "AccountDepositLog.h"

#include <QtCore>

AccountDepositLog::AccountDepositLog(User *user, Account *account, long long deposit_amount): user(user), deposit_amount(deposit_amount) ,account (account) {
}

std::string AccountDepositLog::show_log() {
    return user->get_name()+ " " + std::to_string(account->get_account_num())+ "°èÁÂ·Î" +  std::to_string(deposit_amount)+ "¿ø ÀÔ±Ý " + "ÀÜ¾× " + std::to_string(account->get_balance());
}

