#pragma once
#include"Person.h"
#include"User.h"
#include<vector>


class Admin: public Person
{
	
public:
	vector<Person*> user_list;
	Admin();
	~Admin();
	void admin_menu();
	void search_user();
	Account get_user_account();
	
	//void change_id();
	//User change_pw(User &temp);

};



