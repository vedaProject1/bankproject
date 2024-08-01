//
// Created by lee on 2024. 8. 1..
//

#include "AccountManager.h"

#include <random>
#include <__random/random_device.h>

long long generateAccountNumber() {
    long long accountNumber = 0;
    std::random_device rd;  // 난수 생성용 하드웨어 엔진
    std::mt19937 gen(rd()); // Mersenne Twister 엔진 초기화
    std::uniform_int_distribution<> dis(0, 9); // 0부터 9까지의 균등 분포

    // 13자리 숫자를 생성
    for (int i = 0; i < 13; ++i) {
        int digit = dis(gen); // 균등 분포에서 난수 추출
        accountNumber = accountNumber * 10 + digit; // 각 자리의 숫자를 추가
    }

    return accountNumber;
}





Account* findAccountByNumber(vector<Account>& accounts, long long account_num) {
    // std::find_if를 사용하여 계좌번호가 일치하는 객체를 찾습니다.
    auto it = std::find_if(accounts.begin(), accounts.end(), [account_num](const Account& account) {
        return account.get_account_num() == account_num;
    });
    // 찾은 경우 포인터를 반환하고, 찾지 못한 경우 nullptr을 반환합니다.
    if (it != accounts.end()) {
        return &(*it); // iterator에서 객체 참조로 변환 후 주소 반환
    }
    return nullptr; // 계좌번호를 찾지 못한 경우
}


Account& AccountManager::create_account(User& user) {

    long long random_account_number = generateAccountNumber();
    Account account(random_account_number);
    //Todo: 계좌 중복 처리

    vector<Account> user_accounts = user.get_user_account();
    user_accounts.push_back(account);
    return account;
}

void AccountManager::validate_parameter(Account *find_account_by_number,long amount ) {
    if(find_account_by_number == nullptr) {
        cout << "계좌번호가 올바르지 않습니다";
        return;
    }
    if(amount <=0) {
        cout << "입금액이 올바르지 않습니다";
    }
}

void AccountManager::deposit(User & user, long long account_num, long amount) {

    vector<Account> user_accounts = user.get_user_account();
    Account * find_account_by_number = findAccountByNumber(user_accounts,account_num);
    validate_parameter(find_account_by_number,amount);
    find_account_by_number->plus(amount);
}

void AccountManager::withDraw(User& user, long long account_num, long amount) {

    vector<Account> user_accounts = user.get_user_account();
    Account * find_account_by_number = findAccountByNumber(user_accounts,account_num);
    validate_parameter(find_account_by_number,amount);
    find_account_by_number->minus(amount);
}

double AccountManager::getBalance(User& user, long long account_num) {
    vector<Account> user_accounts = user.get_user_account();
    Account * find_account_by_number = findAccountByNumber(user_accounts,account_num);
    if(find_account_by_number == nullptr) {
        cout<< "계좌가 올바르지 않습니다." << endl;
        return -1;
    }
    return find_account_by_number->get_balance();

}



