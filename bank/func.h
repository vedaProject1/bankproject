#pragma once
#include<iostream>
#include<vector>
#include"Person.h"
#include"User.h"
#include"Admin.h"
#include"Account.h"
#include<fstream>

using namespace std;

void join(vector<Person*>& ulist) {//&�� �����ؼ� ���� 
	cout << "ȸ������ ����\n";
	string i, p, n;
	vector<Person*>::iterator it;
	while (1) {
		cout << "id:";
		cin >> i;
		bool check = true;
		for (it = ulist.begin(); it != ulist.end(); it++)
		{
			if (i == (*it)->get_id() || i == "admin") {
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
			return "�α��μ���";
		}

	}
	return "�α��ν���";
}


void loadFile(std::vector<Person*>& user_list, const std::string& filename) {
	ifstream inFile(filename);
	if (!inFile) {
		std::cerr << "������ �� �� �����ϴ�." << std::endl;
		return;
	}
	string id, pw, name, account_num,bank_name;
	string balance;
	while (getline(inFile, id) &&
		getline(inFile, pw) &&
		getline(inFile, name) &&
		getline(inFile, account_num) &&
		getline(inFile, bank_name) &&
		inFile >> balance) {
		inFile.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // �ٹٲ� ���� �б�

		User* user = new User(id,pw, name, account_num,balance,bank_name);


		user_list.push_back(user);
	}

	inFile.close();
	std::cout << "���Ϸε�Ϸ�" << std::endl;
}


void saveFile(vector<Person*>user_list, string filename) {
	
	ofstream outFile(filename);
	if (!outFile) {
		cerr << "������ �� �� �����ϴ�." << std::endl;
		return;
	}

	vector<Person*>::iterator it;
	for (it =user_list.begin(); it != user_list.end(); it++)
	{
		outFile << (*it)->get_id() << "\n";
		outFile << (*it)->get_pw() << "\n";
		outFile << (*it)->get_name() << "\n";
		outFile << (*it)->get_user_account().get_account_num() << "\n";
		outFile << (*it)->get_user_account().get_bank_name() << "\n";
		outFile << (*it)->get_user_account().get_balance() << "\n";
	}
	outFile.close();
	cout << "��������Ϸ�" << endl;
}

