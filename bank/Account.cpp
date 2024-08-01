#include"Account.h"

Account::Account(long a, double b) {
	this->account_num = a;
	this->balance = b;
}
Account::~Account() {

}
long Account::get_account_num() {
	return this->account_num;
}
double Account::get_balance() {
	return this->balance;
}
