#pragma once
#include <vector>

#include"Person.h"
#include"Account.h"
#include "AccountDepositLog.h"
#include "AccountLogger.h"
#include "AccountWithdrawLog.h"

class User :public Person
{

public:
	vector<shared_ptr<Account>> user_account;

	Account * add_account();
    Account * add_account(int bank_id);
	User (string id, string pw, string name);
	User(string id, string pw, string name,string account_num,string balance,string bankname);
	User() {};
	~User ();
  
	void deposit( long long account_num, long amount);
	void withDraw(long long  account_num , long amount);
	double getBalance( long long account_num);
	Account* get_user_account(long long account_num);
	Account get_user_account() override;
	Account get_user_account(int order);
	long long generateAccountNumber();
	void show_all_accounts();
	vector<shared_ptr<Account>> get_all_accounts();
	vector<shared_ptr<Account>> &get_all_accounts_reference();
	shared_ptr<Account> get_user_account_shared(long long account_num);

private:
	Account* findAccountByNumber(vector<shared_ptr<Account>>& accounts, long long account_num);

};

