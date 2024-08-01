#include"Account.h"

Account::Account(long long  account_num, double balance) {
	this->account_num = account_num;
	this->balance = balance;
}
Account::~Account() {

}

Account::Account(long long  account_num) {
	this->account_num = account_num;
	balance = 0;

}

long long Account::get_account_num() const {
	return this->account_num;
}
double Account::get_balance() {
	return this->balance;
}
