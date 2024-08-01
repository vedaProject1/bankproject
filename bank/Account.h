#pragma once
#include<iostream>
#include<string>
using namespace std;

class Account {
	long long  account_num;
	double  balance;

public:
	Account() {};
	Account(long long account_num, double balance);
	~Account();
	Account(long long account_num);
	long long get_account_num() const;
	double get_balance() const;
	void plus(double amount);
	void minus(double amount);

};