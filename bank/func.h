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

void after_login(string id, vector<Person*>ulist) {

	auto member =find_if(ulist.begin(),ulist.end(),[id](Person* p) {
		return p->get_id() == id;
	});
	Person *p = *member;
	cout << p->get_name() << "님 환영합니다" << endl;
	User* userPtr = dynamic_cast<User*>(p);
	int number;
	if(userPtr != nullptr) {
		do {

			cout << "입금(1) , 출금(2)" << " 잔액조회(3) 로그아웃(4) " << endl;
			cin >> number;
			if(number == 1) {
				double deposit_number;
				cout << "입금액을 입력 해 주세요";
				cin >> deposit_number;
				Account user_account = userPtr->get_user_account();

				userPtr->deposit(user_account.get_account_num(),deposit_number);
				cout<< "입금에 성공했습니다" << endl;

			}
			else if(number == 2) {
				double withdraw_number;
				cout << "출금액을 입력 해 주세요";
				cin >> withdraw_number;
				Account user_account = userPtr->get_user_account();
				userPtr->withDraw(user_account.get_account_num(),withdraw_number);
				cout<< "출금에 성공했습니다" << endl;
			}
			else if(number == 3) {
				Account user_account = userPtr->get_user_account();
				double balance = userPtr->getBalance(user_account.get_account_num());
				cout << "잔액: " << balance << endl;
			}
			else {
				break;
			}
		}while (number != 4);

	}



}




//void Load() {
//	FILE* fp;
//	fp = fopen("C:Users\DREAM12\Desktop\dongha\bankproject\bank", "rb");
//	if (fp == NULL)
//	{
//		fprintf(stderr, "file not found\n");
//	}
//}