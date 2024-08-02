#pragma once
#include<iostream>
#include<string>
using namespace std;

enum BANK_NAME {
	KAKAO,KOOMIN,WOORI,HANA
};
class Account {
	long long  account_num;
	double  balance;
	BANK_NAME  bank_name;

public:
	Account() {};
	Account(long long account_num, BANK_NAME bank_name);
	Account(long long account_num, double balance);
	BANK_NAME get_bank_name() const;
	Account(long a, double b);

	~Account();
	Account(long long account_num);
	long long get_account_num() const;
	double get_balance() const;
	void plus(double amount);
	void minus(double amount);
	string get_bank_name_str(BANK_NAME bank_name) const;
};

};