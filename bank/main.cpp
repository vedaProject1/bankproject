#include<iostream>
#include<vector>
#include"Person.h"
#include"User.h"
#include"Admin.h"
#include"Account.h"
#include "AccountManager.h"
using namespace std;
int main() {

	AccountManager m;
	User user("user","pass","userName");

	 m.create_account(user).get_account_num();

	for(Account s : user.get_user_account()) cout << s.get_account_num() << endl;


	return 0;

}