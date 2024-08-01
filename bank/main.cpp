#include<iostream>
#include<vector>
#include"Person.h"
#include"User.h"
#include"Admin.h"
#include"Account.h"
using namespace std;
int main() {
	Account temp = {1231124,100000};



	cout <<" 메인 변경";

	cout << temp.get_account_num() << endl;
	cout << temp.get_balance() << endl;



	return 0;

}