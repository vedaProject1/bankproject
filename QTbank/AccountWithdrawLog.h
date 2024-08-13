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
    long long balance;
public:
    std::string show_log() override;
    User* get_loged_user() override;
    void save(std::ofstream & outFile) override;
    AccountWithdrawLog(User * user , shared_ptr<Account> account ,long long withDrawAmount);
};



#endif //ACCOUNTWITHDRAWLOG_H
