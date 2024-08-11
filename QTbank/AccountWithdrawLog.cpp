//
// Created by lee on 2024. 8. 11..
//

#include "AccountWithdrawLog.h"
#include "User.h"

std::string AccountWithdrawLog::show_log() {

    return "user :" +user->get_name()+ ", accountNumber: " + std::to_string(account->get_account_num())+ ", deposit: "  +  std::to_string(withDrawAmount)+ " " + ", balance: " + std::to_string(account->get_balance());
}

AccountWithdrawLog::AccountWithdrawLog(User *user, shared_ptr<Account> account, long long withDrawAmount): user(user),account(account),withDrawAmount(withDrawAmount) {
}
