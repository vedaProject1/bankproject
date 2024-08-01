#pragma once
#include<iostream>
#include<string>
using namespace std;

class Person {
	string id;
	string pw;
	string name;
public:
	string get_id();
	string get_pw();
	string get_name();
	Person(string id, string pw, string name);
	~Person();
};