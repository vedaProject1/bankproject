#include<iostream>
#include<vector>
#include<string>
#include"Person.h"
#include"func.h"

using namespace std;
int main() {
	vector<Person*> user_list;
	
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
			join(user_list);
			
			break;
		case 2: {//�α���

			string a;
			string b ;
			cout << "�α����ϼ���" << endl;
			cout << "id:";
			cin >> a;
			cout << "pw:";
			cin >> b;

			string login_value = login(a,b,user_list);
			if (login_value == "admin")
				cout << "������"<<endl;
			else if (login_value == "�α��μ���")
				cout << "�α��μ���" << endl;
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