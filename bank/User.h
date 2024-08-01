#pragma once
#include <vector>

#include"Person.h"
#include"Account.h"

class User :public Person
{
	vector<unique_ptr<Account>> user_account;

public:
	Account * add_account();
	User (string id, string pw, string name);
	~User ();
	long long generateAccountNumber();
};

