#include "BankAccount.h"
#include <string>
#include <iomanip>

using std::fixed;
using std::setprecision;

// Constructor
BankAccount::BankAccount(string &name, int &accountNum, double &balance) {
	createAccount(name, accountNum, balance);
}

void BankAccount::createAccount(string& name, int& accountNum, double& balance) {
	// Data validation for name, accountNumber, and balance is done in getName(), getAccountNumber(), and getbalance()
	accountName = getName();
	accountNumber = getNum();
	accountBalance = getDepositAmount();
}

string BankAccount::getName() {
	string name = "";
	bool isvalidName = false;
	// Loop until valid name
	while (!isvalidName) {
		cout << "Enter your name: ";
		getline(cin, name);
		// Data validation
		if (!name.empty()) {
			isvalidName = true;
			// Loop through name and checks for numbers and special charecters (invalid input for a name). Spaces and "-" are allowed
			for (char c : name) {
				if (!isalpha(c) && c != ' ' && c != '-') {			// If the current character is not a letter and not a "-" and not a space
					isvalidName = false;
					cout << "Invalid name. Please do not use special characters or numbers." << endl;
					break;				// Exit loop
				}
			}
		}
	}
	return name;
}

int BankAccount::getNum() {
	int num = 0;
	string userInput = "";
	bool isValidNum = false;
	// Loop until valid number
	while (!isValidNum) {
		bool consistsOfOnlyNumbers = true;
		cout << "Enter your account number: ";
		getline(cin, userInput);
		// Used to ensure that the number entered only consists of numbers
		for (char c : userInput) {
			if (!isdigit(c)) {
				consistsOfOnlyNumbers = false;
				break;
			}
		}
		if (consistsOfOnlyNumbers && !userInput.empty()) {
			num = stoi(userInput);		// Convert from string to int
			if (num > 0) {
				isValidNum = true;
			}
			else {
				cout << "Account number must be positive." << endl;
			}
		}
		else {
			cout << "Invalid input. Please enter only numbers." << endl;
		}
	}
	return num;
}

double BankAccount::getDepositAmount() {
	double bal = 0.0;
	string userInput = "";
	bool isValidBal = false;

	while (!isValidBal) {
		bool isValidDouble = true;
		int decimalPoints = 0;			// Used to keep track of the number of "." in the string (only 1 allowed for a double)
		cout << "Enter your deposit amount (must be greater than 0): ";
		getline(cin, userInput);
		cout << endl;
		// Check for valid characters (digits and one decimal point only)
		for (char c : userInput) {
			if (c == '.') {
				decimalPoints++;
				if (decimalPoints > 1) {
					isValidDouble = false;
					break;
				}
			}
			else if (!isdigit(c)) {
				isValidDouble = false;
				break;
			}
		}
		// If the user's input is a valid double and not empty
		if (isValidDouble && !userInput.empty()) {
			bal = stod(userInput);
			if (bal > 0) {
				isValidBal = true;
			}
			else {
				cout << "Deposit must be greater than 0." << endl;
				cout << endl;
			}
		}
		else {
			cout << "Invalid input. Please enter a valid number. Use the '.' as a decimal point." << endl;
			cout << endl;
		}
	}
	return bal;
}

void BankAccount::depositMoney(double &balance) {
	accountBalance += balance;
}

void BankAccount::withdrawMoney(double &balance) {
	string userInput = "";
	bool isValidAmount = false;

	while (!isValidAmount) {
		bool validFormat = true;
		int decimalPoints = 0;
		cout << "Enter withdrawal amount: ";
		getline(cin, userInput);
		cout << endl;

		// Check for valid characters (digits and one decimal point only)
		for (char c : userInput) {
			if (c == '.') {
				decimalPoints++;
				if (decimalPoints > 1) {
					validFormat = false;
					break;
				}
			}
			else if (!isdigit(c)) {
				validFormat = false;
				break;
			}
		}

		if (validFormat && !userInput.empty()) {
			balance = stod(userInput);
			// Check if withdrawal amount is valid (positive and not more than account balance)
			if (balance > 0) {
				if (balance <= accountBalance) {
					isValidAmount = true;
				}
				else {
					cout << "Insufficient funds." << endl;
					cout << endl;
				}
			}
			else {
				cout << "Withdrawal amount must be greater than 0." << endl;
				cout << endl;
			}
		}
		else {
			cout << "Invalid input. Please enter a valid number." << endl;
			cout << endl;
		}
	}
	accountBalance -= balance;
}

void BankAccount::checkBalance(const double &balance) {
	cout << "Your current balance: R" << accountBalance << fixed << setprecision(2) << endl;
	cout << endl;
}

void BankAccount::displayAccountDetails(const string &name, const int &accountNum, const double &balance) {
	cout << "--- Account Details ---" << endl;
	cout << "Account Holder: " << accountName << endl;
	cout << "Account Number: " << accountNumber << endl;
	cout << "Account Balance: R" << accountBalance << fixed << setprecision(2) << endl;
	cout << endl;
}