#pragma once
#include"Person.h"
#include"Account.h"

class User 
{
	Account user_account;

public:
	Account get_user_account();
	User ();
	~User ();
};

