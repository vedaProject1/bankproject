#include<iostream>
#include<vector>
#include"Person.h"
#include"User.h"
#include"Admin.h"
#include"Account.h"
using namespace std;
int main() {

	unique_ptr<User> p = make_unique<User>("id","pw","name");

	User * p2 = new User("hello","test","name");
	p2->deposit(-1,100);

	Account * account1 = p->add_account();
	Account * account2 = p->add_account();

	cout << "account 1ÀÔ±Ý"<< endl;
	p->deposit(account1->get_account_num(),300);
	cout << "account ÀÜ°í" <<endl;
	cout << p->getBalance(account1->get_account_num()) << endl;

	cout << "ÀÔ±ÝÀü ÀÜ°í" <<endl;
	cout << p->getBalance(account2->get_account_num());
	cout << "account 2 ÀÔ±Ý " << endl;
	p->deposit(account2->get_account_num(),500);
	cout << "ÀÜ°í :" << p->get_user_account(account2->get_account_num())->get_balance()<<endl;
	p->withDraw(account2->get_account_num(),500);

	cout << "ÀÜ°í :" << p->get_user_account(account2->get_account_num())->get_balance()<<endl;
	cout << p->getBalance(account2->get_account_num())<<endl;






}
