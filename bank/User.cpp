#include"User.h"


Account User::get_user_account() {
	return this->user_account;
}
User::User(string id, string pw, string name):Person(id,pw,name){

}
User::~User() {


}