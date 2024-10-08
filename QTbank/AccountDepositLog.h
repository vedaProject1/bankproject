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
    AccountDepositLog(User* user ,shared_ptr<Account> account ,long long deposit_amount, long long balance);
    User* get_loged_user() override;
    std::string show_log() override;
    void save(std::ofstream& outFile) override;
};



#endif //USERDEPOSITLOG_H
