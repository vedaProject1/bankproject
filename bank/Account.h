#pragma once
#include<iostream>
#include<string>
using namespace std;

class Account {
	long account_num;
	double  balance;

public:
	long get_account_num();
	double get_balance();
};