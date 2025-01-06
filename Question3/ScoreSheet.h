const int NUM_SCORES = 5;

class ScoreSheet {
public:
	ScoreSheet();						// Constructor
	void ScoreSummary();				// Displays the a summary of the scores (average, highest, lowest)

private:
	float scores[NUM_SCORES];			// Stores all score values in an array
	float scoreSum = 0;
	float average = 0;
	float highest = 0;
	float lowest = 100;
	void CalculateAverage();			// Calculate the average of the scores array
	void DisplayAverage();				// Displays the average of the scores array
	void DisplayHighestScore();			// Displays the highest score of the scores array
	void DisplayLowestScore();			// Displays the lowest score of the scores array
	bool isValidScore(float score);		// Checks whether the score entered by the user is a number in the range 0-100
};