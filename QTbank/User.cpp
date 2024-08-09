#include"User.h"

#include <random>
// #include <__random/random_device.h>


Account* User::add_account() {
	long long new_account_number = generateAccountNumber();
    //cout << "���¸� ���� ���� ��ȣ�� �Է��ϼ��� "<<endl;
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
        //cout << "�ش� ���°� �����ϴ�" << endl;
		return;
	}
	if(amount<=0) {
        //cout << "�Աݾ��� 0���� �����ϴ�"<< endl;
	}
	user_account->plus(amount);
}


void User::withDraw(long long account_num, long amount) {

	Account * user_account = get_user_account(account_num);
	if(user_account == nullptr) {
        // << "�ش� ����ڰ� �����ϴ�" << endl;
		return;
	}
	if(amount<=0) {
        //cout << "��ݾ��� 0���� �����ϴ�"<< endl;
		return;
	}
	if(user_account->get_balance() - amount <0) {
        //cout << "�ܾ��� �����մϴ�" << endl;
		return;
	}

	user_account->minus(amount);

}

double User::getBalance( long long account_num) {

	Account * user_account = get_user_account(account_num);
	if(user_account == nullptr) {
        //cout << "�ش� ����ڰ� �����ϴ�" << endl;
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
	 std::random_device rd;  // ���� ������ �ϵ���� ����
	 std::mt19937 gen(rd()); // Mersenne Twister ���� �ʱ�ȭ
	 std::uniform_int_distribution<> dis(0, 9); // 0���� 9������ �յ� ����
	
	 // 13�ڸ� ���ڸ� ����
	 for (int i = 0; i < 13; ++i) {
	 	int digit = dis(gen); // �յ� �������� ���� ����
	 	accountNumber = accountNumber * 10 + digit; // �� �ڸ��� ���ڸ� �߰�
	 }

	return accountNumber;
}

void User::show_all_accounts() {

	for(int i =0; i<user_account.size(); i++) {
		Account * account = user_account[i].get();
		BANK_NAME bank_name = account->get_bank_name();
        //cout<<"�����" << account->get_bank_name_str(bank_name) << endl;

	}
}



