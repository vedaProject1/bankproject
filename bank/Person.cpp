#include"Person.h"
string Person::get_id() {
	return this->id;
}
string Person::get_pw() {
	return this->pw;
}
string Person::get_name() {
	return this->name;
}
Person::Person(string id, string pw, string name) {
	this->id = id;
	this->pw = pw;
	this->name = name;
}
Person::~Person() {
}