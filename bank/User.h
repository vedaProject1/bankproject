#pragma once
#include <vector>

#include"Person.h"
#include"Account.h"

class User :public Person
{
	vector<unique_ptr<Account>> user_account;

public:
	vector<Account>& get_user_account();
	User (string id, string pw, string name);
	~User ();
};

