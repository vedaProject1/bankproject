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
	long get_account_num();
	double get_balance();
	
	Account(long long account_num);

};