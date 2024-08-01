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

double Account::get_balance() const {
	return this->balance;
}

void Account::plus(double amount) {
	this->balance += amount;
}

void Account::minus(double amount) {
	this-> balance -= amount;
}

