#pragma once
#include<iostream>
#include<vector>
#include"Person.h"
#include"User.h"
#include"Admin.h"
#include"Account.h"
using namespace std;

void join(vector<Person*> &ulist) {//&로 접근해서 수정 
	cout << "회원가입 시작\n";
	string i, p, n;
	vector<Person*>::iterator it;
	while (1) {
		cout << "id:";
		cin >> i;
		bool check = true;
		for (it = ulist.begin(); it != ulist.end(); it++)
		{
			if (i == (*it)->get_id() || i == "admin") {
				cout << "이미 사용중인 id입니다\n";
				check = false;
			}
		}
		if (check == true)break;
	}
	cout << "pw:";
	cin >> p;
	cout << "name:";
	cin >> n;
	cout << "회원가입이 완료되었습니다\n";
	//Person temp(i, p, n);
	ulist.push_back(new User(i, p, n));
}
string login(vector<Person*>ulist) {
	string id;
	string pw;
	cout << "로그인하세요" << endl;
	cout << "id:";
	cin >> id;
	cout << "pw:";
	cin >> pw;
	vector<Person*>::iterator it;
	for (it = ulist.begin(); it != ulist.end(); it++)
	{
		if (id == "admin" && pw == "1234")
			return "admin";
		else if (id == (*it)->get_id() && pw == (*it)->get_pw())
		{
			return "로그인성공";
		}
	
	}
	return "로그인실패";
}
