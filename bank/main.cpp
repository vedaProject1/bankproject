#include<iostream>
#include<vector>
#include"Person.h"
#include"User.h"
#include"Admin.h"
#include"Account.h"
using namespace std;

void join(vector<Person> &ulist) {//&�� �����ؼ� ���� 
	cout << "ȸ������ ����\n";
	string i, p, n;
	vector<Person>::iterator it;
	while (1) {
		cout << "id:";
		cin >> i;
		bool check = true;
		for (it = ulist.begin(); it != ulist.end(); it++)
		{
			if (i == (*it).get_id() || i == "admin") {
				cout << "�̹� ������� id�Դϴ�\n";
				check = false;
			}
		}
		if (check == true)break;
	}
	cout << "pw:";
	cin >> p;
	cout << "name:";
	cin >> n;
	cout << "ȸ�������� �Ϸ�Ǿ����ϴ�\n";
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
			return "�α��μ���";
		}
		else return "�α��ν���";
	}
}


int main() {

	vector<Person> user_list;

	join(user_list);
	string a;
	string b;
	cout << "�α����ϼ���"<< endl;
	cout << "id:";
	cin >> a;
	cout << "pw:";
	cin>> b;
	string login_value = login(a, b, user_list);
	if(login_value=="admin")
		cout << "������";
	else if (login_value == "�α��μ���")
		cout << "�α��μ���";
	else if (login_value == "�α��ν���")
		cout << "�α��ν���";






	return 0;

}