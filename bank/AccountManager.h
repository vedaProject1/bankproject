//
// Created by lee on 2024. 8. 1..
//

#ifndef ACCOUNTMANAGER_H
#define ACCOUNTMANAGER_H
#include "User.h"

// ���� ����, �����, �ܾ� ��ȸ ���� ��� ����
//
// ���� ������� ���� �����͸� �����ϰ� �ҷ����� ��� ����

class AccountManager {

public:
    Account& create_account(User& user);
    void validate_parameter(Account *find_account_by_number, long amount );
    void deposit(User& user, long long account_num, long amount);
    void withDraw(User& user, long long  account_num , long amount);
    double getBalance(User& user, long long account_num);

};


#endif //ACCOUNTMANAGER_H
