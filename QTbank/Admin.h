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
    void search_user(string id);
    int search_user_return_idx(string id);
    Account get_user_account();

    //void change_id();
    //User change_pw(User &temp);

};



