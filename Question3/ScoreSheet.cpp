#include "ScoreSheet.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::setprecision;			// Sets the number of decimal places (2 for monetary values)
using std::fixed;					// Used to implement 2 decimal places for monetary outputs
using std::string;
using std::stof;
using std::to_string;

// Data validation
bool ScoreSheet::isValidScore(float score) {
    // Check that the score is within the range [0, 100]
    if (score >= 0 && score <= 100) {
        return true;
    }
    return false;
}

// Constructor adapted from (Great Learning Editorial Team, 2022)
ScoreSheet::ScoreSheet() {
    cout << "Enter the scores for 5 students: " << endl;
    float num = 0;
    bool isValidInput;

    /*
    Populates the scores array
    Keeps track of the highest and lowest scores
    */
    for (int i = 1; i <= NUM_SCORES; i++) {
        isValidInput = false;

        // Loop until valid input is received
        while (!isValidInput) {
            cout << "Enter the score for student " << i << ": ";
            cin >> num;

            // Check if input failed (non-numeric input) adapted from (GeeksforGeeks, 2024b)
            if (cin.fail()) {       
                cin.clear();        // Clear the buffer's error state
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Ignore invalid input
                cout << "Invalid input. Please enter a valid number." << endl;
            }
            else {
                // Check is score is valid
                if (isValidScore(num)) {
                    isValidInput = true;

                    // Keep track of lowest and highest scores
                    if (num < lowest) {
                        lowest = num;
                    }
                    if (num > highest) {
                        highest = num;
                    }

                    scores[i - 1] = num;  // Store the score in the array
                    scoreSum += num;      // Add to the total sum
                }
                else {
                    cout << "Score must be between 0 and 100." << endl;
                }
            }
        }
    }
    CalculateAverage();  // Calculate the average score after all inputs
    cout << endl;
}

// Displays a summary of the ScoreSheet class and its attributes
void ScoreSheet::ScoreSummary() {
	cout << "Scores entered:" << endl;
	// Displays all the scores in the scores array
	for (int i = 1; i <= NUM_SCORES; i++) {
		cout << "Score " << i << ": " << scores[i - 1] << endl;
	}
	cout << endl;
	DisplayAverage();
	DisplayHighestScore();
	DisplayLowestScore();
}

// Calculates the average of the scores of the ScoreSheet class
void ScoreSheet::CalculateAverage() {
	average = scoreSum / NUM_SCORES;
}

// Displays the average score attribute of the ScoreSheet class
void ScoreSheet::DisplayAverage() {
	cout << "Average score: " << fixed << setprecision(2) << average << endl;
}

// Displays the highest score attribute of the ScoreSheet class
void ScoreSheet::DisplayHighestScore() {
	cout << "Highest score: " << fixed << setprecision(2) << highest << endl;
}

// Displays the lowest score attribute of the ScoreSheet class
void ScoreSheet::DisplayLowestScore() {
	cout << "Lowest score: " << fixed << setprecision(2) << lowest << endl;
}

/*

References:

GeeksforGeeks (2024b). How to Use cin.fail() Method in C++? [online] GeeksforGeeks. Available at: https://www.geeksforgeeks.org/how-to-use-cin-fail-method-in-cpp/ [Accessed 19 Oct. 2024].
Great Learning Editorial Team (2022). Constructor in C++ and Types of Constructors. [online] Great Learning Blog: Free Resources What Matters to Shape Your Career! Available at: https://www.mygreatlearning.com/blog/constructor-in-cpp/ [Accessed 19 Oct. 2024].

*/