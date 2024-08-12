//
// Created by lee on 2024. 8. 11..
//

#include "AccountWithdrawLog.h"
#include "User.h"

std::string AccountWithdrawLog::show_log() {

    return "user :" +user->get_name()+ ", accountNumber: " + std::to_string(account->get_account_num())+ ", withdraw: "  +  std::to_string(withDrawAmount)+ " " + ", balance: " + std::to_string(balance);
}

AccountWithdrawLog::AccountWithdrawLog(User *user, shared_ptr<Account> account, long long withDrawAmount): user(user),account(account),withDrawAmount(withDrawAmount),balance(account->get_balance()) {

}
