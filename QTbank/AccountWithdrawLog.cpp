//
// Created by lee on 2024. 8. 11..
//

#include "AccountWithdrawLog.h"
#include "User.h"

std::string AccountWithdrawLog::show_log() {

    return "user :" +user->get_name()+ ", accountNumber: " + std::to_string(account->get_account_num())+ ", withdraw: "  +  std::to_string(withDrawAmount)+ " " + ", balance: " + std::to_string(balance);
}

User * AccountWithdrawLog::get_loged_user() {
    return this->user;
}

AccountWithdrawLog::AccountWithdrawLog(User *user, shared_ptr<Account> account, long long withDrawAmount): user(user),account(account),withDrawAmount(withDrawAmount),balance(account->get_balance()) {

}

void AccountWithdrawLog::save(std::ofstream &outFile) {
    outFile << "W" << '\n';
    outFile << user->get_id() << '\n';
    outFile << account->get_account_num() << '\n';
    outFile << withDrawAmount << '\n';
    outFile << balance << '\n';

}
