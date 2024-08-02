#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<string>
#include"Person.h"
#include"func.h"

using namespace std;
int main() {

	//vector<Person*> user_list;
	Admin admin;
	admin.user_list.push_back(new User("dong", "1234", "asdasd"));
	
	int menuNO;
	do
	{
		cout << "====================" << endl;
		cout << "1. 회원가입" << endl;
		cout << "2. 로그인" << endl;
		cout << "9. 종료" << endl;
		cout<<"선택-->";
		cin >> menuNO;
		switch (menuNO)
		{
		case 1://회원가입
			join(admin.user_list);
			break;
		case 2: {//로그인
			string id;
			string pw;
			cout << "로그인하세요" << endl;
			cout << "id:";
			cin >> id;
			cout << "pw:";
			cin >> pw;
			string login_value = login(id,pw,admin.user_list);

			if (login_value == "admin")
				admin.admin_menu();
			else if (login_value == "로그인성공") {
				cout << "로그인성공" << endl;
				after_login(id,admin.user_list);
			}
			else if (login_value == "로그인실패")
				cout << "로그인실패" << endl;
			break;
		}
		case 9:
			cout << "종료 선택하셨습니다." << endl;
			break;
		default:
			cout << "잘못 선택하셨습니다" << endl;
			break;
		}

	} while (menuNO != 9);//9이면 종료니깐 9면 반복문 탈출
	return 0;
}

