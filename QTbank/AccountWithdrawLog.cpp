//
// Created by lee on 2024. 8. 11..
//

#include "AccountWithdrawLog.h"

std::string AccountWithdrawLog::show_log() {

    return user->get_name()+ " " + std::to_string(account->get_account_num())+ "���·�" +  std::to_string(withDrawAmount)+ "�� ���� " + "�ܾ� " + std::to_string(account->get_balance());
}

AccountWithdrawLog::AccountWithdrawLog(User *user, Account *account, long long withDrawAmount): user(user),withDrawAmount(withDrawAmount),account(account) {
}
