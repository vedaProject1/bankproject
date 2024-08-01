#pragma once
#include"Person.h"
#include"Account.h"

class User :public Person
{
	Account user_account;

public:
	Account get_user_account();
	User (string id, string pw, string name);
	~User ();
};

