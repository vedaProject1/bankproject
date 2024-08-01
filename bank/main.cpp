#include<iostream>
#include<vector>
#include"Person.h"
#include"User.h"
#include"Admin.h"
#include"Account.h"
using namespace std;

void join(vector<Person> &ulist) {//&로 접근해서 수정 
	cout << "회원가입 시작\n";
	string i, p, n;
	vector<Person>::iterator it;
	while (1) {
		cout << "id:";
		cin >> i;
		bool check = true;
		for (it = ulist.begin(); it != ulist.end(); it++)
		{
			if (i == (*it).get_id() || i == "admin") {
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
	Person temp(i, p, n);
	ulist.push_back(temp);
}
string login(string id, string pw, vector<Person>ulist) {
	vector<Person>::iterator it;
	for (it = ulist.begin(); it != ulist.end(); it++)
	{
		if (id == "admin" && pw == "1234")
			return "admin";
		if (id == it->get_id() && pw == it->get_pw())
		{
			return "로그인성공";
		}
		else return "로그인실패";
	}
}


int main() {

	vector<Person> user_list;

	join(user_list);
	string a;
	string b;
	cout << "로그인하세요"<< endl;
	cout << "id:";
	cin >> a;
	cout << "pw:";
	cin>> b;
	string login_value = login(a, b, user_list);
	if(login_value=="admin")
		cout << "관리자";
	else if (login_value == "로그인성공")
		cout << "로그인성공";
	else if (login_value == "로그인실패")
		cout << "로그인실패";






	return 0;

}