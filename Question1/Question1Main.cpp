#include <iostream>
#include <string>
#include <iomanip> 
#include <fstream>

using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::getline;
using std::stoi;
using std::fixed;           // Used to implement 2 decimal places for monetary outputs 
using std::setprecision;    // Sets the number of decimal places (2 for monetary values) adapted from (Ravikiran, 2024b)
using std::ofstream;        // File stream for handling files

const int NUM_MENU_ITEMS = 8;                   // Can be adjusted manually when adding menu items
const double MINIMUM_FOR_DISCOUNT = 100.00;     // Minimum value for discount (R100)
const double DISCOUNT_RATE = 0.9;               // 10% Discount
const double COFFEE_PRICE = 15.00;
const double SANDWICH_PRICE = 30.00;
const double SALAD_PRICE = 25.00;
const double JUICE_PRICE = 10.00;
const double MUFFIN_PRICE = 20.00;
const double PIZZA_PRICE = 35.00;
const double SOUP_PRICE = 18.00;
const double BURGER_PRICE = 40.00;

// Implementation of arrays adapted from (Ravikiran, 2024a)
const string menuItems[NUM_MENU_ITEMS]{
    "Coffee",
    "Sandwich",
    "Salad",
    "Juice",
    "Muffin",
    "Pizza Slice",
    "Soup",
    "Burger"
};

const double menuPrices[NUM_MENU_ITEMS]{
    COFFEE_PRICE,
    SANDWICH_PRICE,
    SALAD_PRICE,
    JUICE_PRICE,
    MUFFIN_PRICE,
    PIZZA_PRICE,
    SOUP_PRICE,
    BURGER_PRICE,
};

// Prints the Menu
void printMenu() {
    cout << "Cafeteria Menu:" << endl;
    for (int i = 0; i < NUM_MENU_ITEMS; i++) {
        cout << (i + 1) << ". " << menuItems[i] << "\t- R" << fixed << setprecision(2) << menuPrices[i] << endl;        // Uses the parallel arrays: menuItems and menuPrices to print the menu
    }
    cout << endl;
}

// Checks if input is valid (Must be a number and must be in the specified range)
bool isValidInput(const string& input, int min, int max) {
    // Try-catch implementation adapted from (Udacity, 2021)
    try {                                       
        int value = stoi(input);                // Check if input is a number
        if (value >= min && value <= max)       // Check if input is within the range
        return true;  
    }
    catch (const std::invalid_argument e) {
        return false;                           // Return false if input is not a valid number
    }
    return false;
}

// Asks user how many items they would like to order
int howManyItems() {
    bool isValid = false;               // Used to check if the number entered by the user is valid. Validated through the isValidInput function.
    string numItemsString = "";
    int numItems = 1;

    // Continues to loop until valid input
    while (!isValid) {
        cout << "How many items would you like to order (1-" << NUM_MENU_ITEMS << ")? ";
        getline(cin, numItemsString);

        // Validate the input
        if (isValidInput(numItemsString, 1, NUM_MENU_ITEMS)) {
            numItems = stoi(numItemsString);
            isValid = true;
        }
        else {
            cout << "Please select a number between 1 and " << NUM_MENU_ITEMS << endl;
        }
    }
    return numItems;
}

// Function to handle the ordering process and calculate the total
double processOrder(int numItems) {
    double runningTotal = 0.00;
    string itemIndexString = "";
    int itemIndex = 0;

    for (int i = 0; i < numItems; i++) {
        bool validItem = false;

        while (!validItem) {
            cout << "Select item " << (i + 1) << " (1-" << NUM_MENU_ITEMS << "): ";
            getline(cin, itemIndexString);

            // Ensure valid item selection
            if (isValidInput(itemIndexString, 1, NUM_MENU_ITEMS)) {
                itemIndex = stoi(itemIndexString);
                validItem = true;
                cout << menuItems[itemIndex - 1] << endl;           // Display the item that the user selected
                runningTotal += menuPrices[itemIndex - 1];          // Add the selected item price to the total
            }
            else {
                cout << "Please select a valid item number between 1 and " << NUM_MENU_ITEMS << "." << endl;
            }
        }
    }
    cout << endl;
    return runningTotal;
}

// Function to apply discount based on the minimum value to qualify for a discount (MINIMUM_FOR_DISCOUNT)
double applyDiscount(double total) {
    if (total > MINIMUM_FOR_DISCOUNT) {            // Apply discount if total exceeds the threshold
        cout << "Discount applied." << endl;
        return total * DISCOUNT_RATE;  
    }
    cout << "No discount applied." << endl;
    return total;
}

void outputBillToFile(string firstName, string lastName, double billTotal) {
    ofstream billFile;
    billFile.open("CafeteriaBill.txt");

    //File handling adapted from (cpluplus.com, 2023)
    // Check if the file opened successfully.
    if (billFile.is_open()) {
        billFile << "Bill for:" << endl;
        billFile << firstName << " " << lastName << endl;
        billFile << "Total: R" << fixed << setprecision(2) << billTotal << endl;
        billFile.close();
        cout << "Bill has successfully been written to the file." << endl;
    }
    else {
        cout << "Error: Could not open file for writing." << endl;
    }
}


int main() {
    string firstName = "";
    string lastName = "";
    int numItems = 0;
    double runningTotal = 0.00;
    double discountedTotal = 0.00;

    // Get name and surname from user
    cout << "Enter your name: ";
    getline(cin, firstName);
    cout << "Enter your surname: ";
    getline(cin, lastName);
    cout << "Welcome " << firstName << " " << lastName << "\n\n";

    printMenu();

    numItems = howManyItems();
    runningTotal = processOrder(numItems);

    // Display pre-discount total
    cout << "Your total: R" << fixed << setprecision(2) << runningTotal << endl;

    // Apply discount if applicable and display final total
    discountedTotal = applyDiscount(runningTotal);
    cout << "Final Bill: R" << fixed << setprecision(2) << discountedTotal << endl;

    // Output bill to text file
    outputBillToFile(firstName, lastName, discountedTotal);

    return 0;
}