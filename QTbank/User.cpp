#include"User.h"

#include <random>
// #include <__random/random_device.h>


Account* User::add_account() {
	long long new_account_number = generateAccountNumber();
    //cout << "계좌를 만들 은행 번호를 입력하세요 "<<endl;
    //cout<< "KAKAO : 0,KOOMIN : 1,WOORI : 2,HANA : 3" << endl;
	int bank_id;
	cin >> bank_id;
	user_account.push_back(make_unique<Account>(new_account_number,static_cast<BANK_NAME>(bank_id)));
	return user_account.back().get();
}

Account * User::get_user_account(long long account_num) {

	auto it = std::find_if(user_account.begin(), user_account.end(),
	   [account_num](const std::unique_ptr<Account>& account) {
		   return account->get_account_num() == account_num;
	   });
	if(it != user_account.end()) {
		return it->get();
	}
	return nullptr;
}



Account User::get_user_account() {
	return *user_account[0];
}

Account User::get_user_account(int order) {

	if(user_account.size() <= order)  return NULL;
	return *user_account.at(order);
}

User::User(string id, string pw, string name):Person(id,pw,name){

}
User::User(string id, string pw, string name, string account_num, string balance, string bankname) :Person(id, pw, name) {
	Account* temp = new Account(stoll(account_num), ((BANK_NAME)stoi(bankname)), stod(balance));

	this->user_account.push_back(make_unique<Account>(*temp));


}
User::~User() {


}

void User::deposit(long long account_num, long amount) {
	Account * user_account = get_user_account(account_num);
	if(user_account == nullptr) {
        //cout << "해당 계좌가 없습니다" << endl;
		return;
	}
	if(amount<=0) {
        //cout << "입금액이 0보다 적습니다"<< endl;
	}
	user_account->plus(amount);
}


void User::withDraw(long long account_num, long amount) {

	Account * user_account = get_user_account(account_num);
	if(user_account == nullptr) {
        // << "해당 사용자가 없습니다" << endl;
		return;
	}
	if(amount<=0) {
        //cout << "출금액이 0보다 적습니다"<< endl;
		return;
	}
	if(user_account->get_balance() - amount <0) {
        //cout << "잔액이 부족합니다" << endl;
		return;
	}

	user_account->minus(amount);

}

double User::getBalance( long long account_num) {

	Account * user_account = get_user_account(account_num);
	if(user_account == nullptr) {
        //cout << "해당 사용자가 없습니다" << endl;
		return -1;
	}
	return user_account->get_balance();

}




Account * User::findAccountByNumber(vector<unique_ptr<Account>>&accounts, long long account_num) {

	for(int i = 0; i<accounts.size();i++) {
		if(accounts[i]->get_account_num() == account_num) return accounts[i].get();
	}
	return nullptr;
}
long long  User::generateAccountNumber() {
	 long long accountNumber = 0;
	 std::random_device rd;  // 난수 생성용 하드웨어 엔진
	 std::mt19937 gen(rd()); // Mersenne Twister 엔진 초기화
	 std::uniform_int_distribution<> dis(0, 9); // 0부터 9까지의 균등 분포
	
	 // 13자리 숫자를 생성
	 for (int i = 0; i < 13; ++i) {
	 	int digit = dis(gen); // 균등 분포에서 난수 추출
	 	accountNumber = accountNumber * 10 + digit; // 각 자리의 숫자를 추가
	 }

	return accountNumber;
}

void User::show_all_accounts() {

	for(int i =0; i<user_account.size(); i++) {
		Account * account = user_account[i].get();
		BANK_NAME bank_name = account->get_bank_name();
        //cout<<"은행명" << account->get_bank_name_str(bank_name) << endl;

	}
}



