//
// Created by lee on 2024. 8. 1..
//

#include "AccountManager.h"

#include <random>
#include <__random/random_device.h>

long long generateAccountNumber() {
    long long accountNumber = 0;
    std::random_device rd;  // ���� ������ �ϵ���� ����
    std::mt19937 gen(rd()); // Mersenne Twister ���� �ʱ�ȭ
    std::uniform_int_distribution<> dis(0, 9); // 0���� 9������ �յ� ����

    // 13�ڸ� ���ڸ� ����
    for (int i = 0; i < 13; ++i) {
        int digit = dis(gen); // �յ� �������� ���� ����
        accountNumber = accountNumber * 10 + digit; // �� �ڸ��� ���ڸ� �߰�
    }

    return accountNumber;
}





Account* findAccountByNumber(vector<Account>& accounts, long long account_num) {
    // std::find_if�� ����Ͽ� ���¹�ȣ�� ��ġ�ϴ� ��ü�� ã���ϴ�.
    auto it = std::find_if(accounts.begin(), accounts.end(), [account_num](const Account& account) {
        return account.get_account_num() == account_num;
    });
    // ã�� ��� �����͸� ��ȯ�ϰ�, ã�� ���� ��� nullptr�� ��ȯ�մϴ�.
    if (it != accounts.end()) {
        return &(*it); // iterator���� ��ü ������ ��ȯ �� �ּ� ��ȯ
    }
    return nullptr; // ���¹�ȣ�� ã�� ���� ���
}


Account& AccountManager::create_account(User& user) {

    long long random_account_number = generateAccountNumber();
    Account account(random_account_number);
    //Todo: ���� �ߺ� ó��

    vector<Account> user_accounts = user.get_user_account();
    user_accounts.push_back(account);
    return account;
}

void AccountManager::validate_parameter(Account *find_account_by_number,long amount ) {
    if(find_account_by_number == nullptr) {
        cout << "���¹�ȣ�� �ùٸ��� �ʽ��ϴ�";
        return;
    }
    if(amount <=0) {
        cout << "�Աݾ��� �ùٸ��� �ʽ��ϴ�";
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
        cout<< "���°� �ùٸ��� �ʽ��ϴ�." << endl;
        return -1;
    }
    return find_account_by_number->get_balance();

}



