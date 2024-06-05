#ifndef SAVINGBANKACCOUNT_H
#define SAVINGBANKACCOUNT_H
#include <iostream>
#include "bankAccount.cpp"
#include "clint.cpp"


using namespace std;
class savingBankAccount : public bankAccount {
	float minimumBalance;
public:
	savingBankAccount(float minimumBalance,float balance,string type)
	{
		this->minimumBalance = minimumBalance;
		setBalance(balance);
		type = "Saving";
	}
	savingBankAccount(float balance,string type)
	{
		this->minimumBalance = 1000;
		setBalance(balance);
		this->type=type;

	}
	void setMinimummBalance(float minimumBalance) {
		this->minimumBalance = minimumBalance;
	}
	float getMinimummBalance() {
		return minimumBalance;
	}
	void withdraw(float amount) {
		if (amount < 0)
			cout << "Please Enter Valid Value \n";
		else if (amount <= getBalance() - minimumBalance) {
			setBalance(getBalance() - amount);
			cout << "Thank You.Your Balance Is "<<getBalance()<<"\n";
		}
		else
		{
			cout << "This More Than What You Can Withdraw";
		}

	}
	string getType(){
		return type;
	}
};
#endif