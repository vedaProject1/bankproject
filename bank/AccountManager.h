//
// Created by lee on 2024. 8. 1..
//

#ifndef ACCOUNTMANAGER_H
#define ACCOUNTMANAGER_H
#include "User.h"

// 계좌 생성, 입출금, 잔액 조회 등의 기능 구현
//
// 파일 입출력을 통해 데이터를 저장하고 불러오는 기능 구현

class AccountManager {

public:
    Account& create_account(User& user);
    void validate_parameter(Account *find_account_by_number, long amount );
    void deposit(User& user, long long account_num, long amount);
    void withDraw(User& user, long long  account_num , long amount);
    double getBalance(User& user, long long account_num);

};


#endif //ACCOUNTMANAGER_H
