//
// Created by lee on 2024. 8. 11..
//

#ifndef ACCOUNTWITHDRAWLOG_H
#define ACCOUNTWITHDRAWLOG_H
#include "AccountLog.h"
#include "Account.h"
class User;


class AccountWithdrawLog : public AccountLog {

    User * user;
    std::shared_ptr<Account> account;
    long long withDrawAmount;
public:
    std::string show_log() override;
    AccountWithdrawLog(User * user , shared_ptr<Account> account ,long long withDrawAmount);
};



#endif //ACCOUNTWITHDRAWLOG_H
