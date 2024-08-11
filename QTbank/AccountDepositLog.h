//
// Created by lee on 2024. 8. 10..
//

#ifndef USERDEPOSITLOG_H
#define USERDEPOSITLOG_H
#include "AccountLog.h"
#include "User.h"


class AccountDepositLog : public AccountLog{

    User * user;
    shared_ptr<Account> account;
    long long deposit_amount;
public:
    AccountDepositLog(User* user, shared_ptr<Account> account ,long long deposit_amount);
    std::string show_log() override;
};



#endif //USERDEPOSITLOG_H
