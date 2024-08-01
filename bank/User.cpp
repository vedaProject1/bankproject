#include"User.h"

#include <random>
#include <__random/random_device.h>


Account* User::add_account() {
	long long new_account_number = generateAccountNumber();
	cout << "계좌를 만들 은행 번호를 입력하세요 "<<endl;
	cout<< "KAKAO : 0,KOOMIN : 1,WOORI : 2,HANA : 3" << endl;
	int bank_id;
	cin >> bank_id;
	user_account.push_back(make_unique<Account>(new_account_number,static_cast<BANK_NAME>(bank_id)));
	return user_account.back().get();
}

vector<Account>& User::get_user_account() {
	return user_account;
}
User::User(string id, string pw, string name):Person(id,pw,name){

}
User::~User() {


}