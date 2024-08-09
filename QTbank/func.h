#pragma once
#include<iostream>
#include<vector>
#include"Person.h"
#include"User.h"
#include"Admin.h"
#include"Account.h"
#include<fstream>

using namespace std;

void join(vector<Person*>& ulist) ;
string login(string id, string pw, vector<Person*>ulist);

void after_login(string id, vector<Person*>ulist) ;

void loadFile(std::vector<Person*>& user_list, const std::string& filename);

void saveFile(vector<Person*>user_list, string filename);

