#pragma once
#include<iostream>
#include<vector>
#include"Person.h"
#include"User.h"
#include"Admin.h"
#include"Account.h"
#include<stdio.h>
#include<stdlib.h>//메모리 관련라이브러리 
using namespace std;

void join(vector<Person*>& ulist) {//&로 접근해서 수정 
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
	User* user = new User(i, p, n);
	user->add_account();
	//ulist.push_back(new User(i, p, n));
	ulist.push_back(user);

}
string login(string id, string pw, vector<Person*>ulist) {
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


//void Load() {
//	FILE* fp;
//	fp = fopen("C:Users\DREAM12\Desktop\dongha\bankproject\bank", "rb");
//	if (fp == NULL)
//	{
//		fprintf(stderr, "file not found\n");
//	}
//}