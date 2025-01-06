#include <iostream>
#include <string>
#include "BankAccount.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;

void displayMenu() {
	cout << "-- Bank Account Management System ---" << endl;
	cout << "1. Create Account" << endl;
	cout << "2. Deposit Money" << endl;
	cout << "3. Withdraw Money" << endl;
	cout << "4. Check balance" << endl;
	cout << "5. Display Account Details" << endl;
	cout << "6. Exit" << endl;
	cout << endl;
}

int main() {
	string accName = "";
	int accNum = 0;
	int userChosenMenuCode = 0;
	double accBalance = 0.00;
	double depositAmount = 0.00;
	double withdrawAmount = 0;
	bool isValidDeposit = false;
	bool exitEvoked = false;
	bool accountCreated = false;
	BankAccount *account = nullptr;		// Null pointer to null class. Class is accessible to all switch-case options

    while (!exitEvoked) {    // Menu loop
        displayMenu();
        cout << "Enter your choice (1-6): ";
        cin >> userChosenMenuCode;
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (userChosenMenuCode == 6) {  // If the user chooses option 6 (exit) 
            exitEvoked = true;
            delete account;             // Free up memory and prevent memory leak
            continue;
        }

        if (!accountCreated) {                      // If no account has been created
            if (userChosenMenuCode == 1) {          // But user chooses to create an account
                account = new BankAccount(accName, accNum, accBalance);
                cout << "Account created successfully!" << endl;
                cout << endl;
                accountCreated = true;
            }
            else {                                  // User can't choose any menu items unless they have an account. User can still choose option 1 (create account) and option 6 (exit).
                cout << "Error: Please create an account first (Option 1)." << endl;
                cout << endl;
            }
        }
        else {
            switch (userChosenMenuCode) {
            case 1: {
                cout << "Account has already been created" << endl;
                cout << endl;
                break;
            }
            case 2: {
                double deposit = account->getDepositAmount();
                account->depositMoney(deposit);
                break;
            }
            case 3: {
                account->withdrawMoney(withdrawAmount);
                break;
            }
            case 4: {
                account->checkBalance(accBalance);
                break;
            }
            case 5: {
                account->displayAccountDetails(accName, accNum, accBalance);
                break;
            }
            default: {
                cout << "Invalid option selected. Please select a valid option (1-6)" << endl;
                cout << endl;
                break;
            }
            }
        }
    }
}