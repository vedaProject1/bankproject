#pragma once
#include<iostream>
#include<string>
#include"Account.h"
using namespace std;

class Person {
	string id;
	string pw;
	string name;
public:
	string get_id();
	string get_pw();
	string get_name();

	virtual Account get_user_account()=0;
    Person();
	Person(string id, string pw, string name);
	~Person();
};
