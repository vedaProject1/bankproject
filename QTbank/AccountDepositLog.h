//
// Created by lee on 2024. 8. 10..
//

#ifndef USERDEPOSITLOG_H
#define USERDEPOSITLOG_H
#include "AccountLog.h"
#include "Account.h"

class User;

class AccountDepositLog : public AccountLog{

    User * user;
    std::shared_ptr<Account> account;
    long long deposit_amount;
    long long balance;
public:
    AccountDepositLog(User* user, shared_ptr<Account> account ,long long deposit_amount);
    std::string show_log() override;
};



#endif //USERDEPOSITLOG_H
