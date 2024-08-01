#include"Account.h"

Account::Account(long long  account_num, double balance) {
	this->account_num = account_num;
	this->balance = balance;
}
Account::~Account() {

}
long Account::get_account_num() {
	return this->account_num;
}
double Account::get_balance() {
	return this->balance;
}
