#ifndef CLINT_H
#define CLINT_H
#include <iostream>

using namespace std;
class client {
	string name, phoneNumber, address;
public:
	client(){

	}
	client(string name,string phoneNumber,string address){
		this-> address = address;
		this-> name = name;
		this-> phoneNumber = phoneNumber;
	}
	void setName(string name) {
		this->name = name;
	}
	string getName() {
		return name;
	}
	void setphnum(string phoneNumber) {
		this->phoneNumber = phoneNumber;
	}
	string getPhNum() {
		return phoneNumber;
	}
	void setAddress(string address) {
		this->address = address;
	}
	string getAddress() {
		return address;
	}

};
#endif