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
		cout << "1. ȸ������" << endl;
		cout << "2. �α���" << endl;
		cout << "9. ����" << endl;
		cout<<"����-->";
		cin >> menuNO;
		switch (menuNO)
		{
		case 1://ȸ������
			join(admin.user_list);
			break;
		case 2: {//�α���
			string id;
			string pw;
			cout << "�α����ϼ���" << endl;
			cout << "id:";
			cin >> id;
			cout << "pw:";
			cin >> pw;
			string login_value = login(id,pw,admin.user_list);

			if (login_value == "admin")
				admin.admin_menu();
			else if (login_value == "�α��μ���") {
				cout << "�α��μ���" << endl;
				after_login(id,admin.user_list);
			}
			else if (login_value == "�α��ν���")
				cout << "�α��ν���" << endl;
			break;
		}
		case 9:
			cout << "���� �����ϼ̽��ϴ�." << endl;
			break;
		default:
			cout << "�߸� �����ϼ̽��ϴ�" << endl;
			break;
		}

	} while (menuNO != 9);//9�̸� ����ϱ� 9�� �ݺ��� Ż��
	return 0;
}

