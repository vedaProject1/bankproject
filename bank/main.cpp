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
			if (i == (*it).get_id() || i == "admin_id") {
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
void login(string id, string pw, vector<Person>ulist) {




}
int main() {
	Account temp = {1231124,100000};

	vector<Person> user_list;
	while (1) {
		join(user_list);
	}


	cout << temp.get_account_num() << endl;
	cout << temp.get_balance() << endl;


	return 0;

}