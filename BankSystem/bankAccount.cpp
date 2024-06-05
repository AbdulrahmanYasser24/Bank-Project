#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <iostream>
#include "clint.cpp"

using namespace std;

class bankAccount {
	float balance;
	client newClient;
	int accountId;
public:
	string type = "(Basic)";
	 static int id;
	bankAccount()
	{
		this->balance = 0;
	}
	bankAccount(float balance) {
		this->balance = balance;
	}
	void setID(int id) {
		this->accountId = id;
	}
	int getID() {
		return accountId;
	}
	void setBalance(float balance) {
		this->balance = balance;
	}
	float getBalance() {
		return balance;
	}
	void setClient(client newClient ){
		this->newClient=newClient;
	}
	client getClient(){
		return this->newClient;
	}
	string getType(){
		return type;
	}
	virtual void withdraw(float amount) {
		if (amount < 0)
			cout << "Please Enter Valid Value";
		else if (amount > balance)
			cout << "You Haven't This Balance ";
		else
			balance = balance - amount;
	}
	virtual void deposit(float amount) {
		if (amount < 0)
			cout << "Please Enter Valid Value";
		else
			balance = balance + amount;
	}
};
#endif