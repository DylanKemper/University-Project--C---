#include <string>
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

class BankAccount {
public:
	BankAccount(string& name, int& accountNumber, double& balance);			// Constructor
	void createAccount(string& name, int& accountNumber, double& balance);
	void depositMoney(double &balance);
	void withdrawMoney(double &balance);
	void checkBalance(const double& balance);
	void displayAccountDetails(const string &name, const int &accountNum, const double &balance);
	double getDepositAmount();

private:
	string accountName;
	int accountNumber;
	double accountBalance;
	string getName();
	int getNum();
};