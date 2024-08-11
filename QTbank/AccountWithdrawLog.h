//
// Created by lee on 2024. 8. 11..
//

#ifndef ACCOUNTWITHDRAWLOG_H
#define ACCOUNTWITHDRAWLOG_H
#include "AccountLog.h"
#include "User.h"


class AccountWithdrawLog : AccountLog {

    User * user;
    Account * account;
    long long withDrawAmount;
public:
    std::string show_log() override;
    AccountWithdrawLog(User * user , Account * account ,long long withDrawAmount);
};



#endif //ACCOUNTWITHDRAWLOG_H
