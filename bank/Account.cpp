#include"Account.h"


Account::Account() {
	this->account_num = 1234;
	this->balance = 0;
}


Account::Account(long long account_num, BANK_NAME bank_name) {
	this->account_num = account_num;
	this->balance = 0;
	this->bank_name = bank_name;
}
// Account::Account(long a, double b) {
// 	this->account_num = a;
// 	this->balance = b;
// }

Account::Account(long long  account_num, double balance) {
	this->account_num = account_num;
	this->balance = balance;
}

BANK_NAME Account::get_bank_name() const {
	return bank_name;
}

Account::~Account() {

}

Account::Account(long long  account_num) {
	this->account_num = account_num;
	balance = 0;

}

long long Account::get_account_num() const {
	return account_num;
}

double Account::get_balance() const {
	return this->balance;
}

void Account::plus(double amount) {
	this->balance +=amount;
}

void Account::minus(double amount) {
	this->balance -= amount;
}

string Account::get_bank_name_str(BANK_NAME bank_name) const {
	switch (bank_name) {
		case KAKAO: return "KAKAO";
		case KOOMIN: return "KOOMIN";
		case WOORI: return "WOORI";
		case HANA: return "HANA";
		default: return "UNKNOWN";
	}
}



