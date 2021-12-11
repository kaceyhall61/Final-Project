// Kacey Hall
// 12.10.2021
// Final Project
// Simple workout/run tracker. 

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <fstream>
#include <vector>

using namespace std;

int strengthInfo(int q);			// Collects strength training info from the user.
int runInfo(double x, double y);		// Collect runing info from the user.
void print(vector<vector<string>> data, int q);		// Prints strength training information to a file.
void print(double x, double y, double z);			// Prints run information to a file.
void intro();				// Where the program begins asking for information.
void readStrengthFile(int q);	// Reads the saved workout file to the user.
void readRunFile();

int main() 
{
		cout << "Welcome to Centurion Gym!" << endl << endl;

		intro();

	system("pause");
	return(0);
}		     // Main throws to Intro function.

int strengthInfo(int q)
{
	string sets;
	string reps;
	string weight;
	string name;
	int choice;

	vector<string> workoutName;
	vector<string> setsV;
	vector<string> weightV;
	vector<string> repsV;
	vector<vector<string>> strengthStat;	// A vector of vectors of type string. We fill up four vectors, one for name, sets, weight, and reps, then throw those vectors into a vector of vectors. Creating a 2d vector.

	cout << "Enter the names of the workouts and press enter after each one (if two words, please connect them with a '-'): ";

	for (int y = 0; y < 1; y++)
	{
		cin.ignore();

		for (int x = 0; x < q; x++)			// Get names of the exercises.
		{
			getline(cin, name);

			workoutName.push_back(name);
		}
	}

	for (int x = 0; x < q; x++)
	{
		cout << "Let's learn more about " << workoutName[x] << "." << endl;		// Get sets, reps, and weight for each exercise.

			cout << "Enter number of sets: ";

			cin >> sets;

			setsV.push_back(sets);

			cout << "Enter number of repititions: ";

			cin >> reps;

			repsV.push_back(reps);

			cout << "Enter weight: ";

			cin >> weight;

			weightV.push_back(weight);
	}

	strengthStat.push_back(workoutName);
	strengthStat.push_back(setsV);
	strengthStat.push_back(repsV);
	strengthStat.push_back(weightV);

	print(strengthStat, q);

	cout << "Would you like to view your last recorded workout?" << endl;

	cout << "1. Yes" << endl;

	cout << "2. No" << endl;

	cin >> choice;

	switch (choice)
	{
	case 1:

		readStrengthFile(q);
		break;

	case 2:
		return(0);
		break;
	}
}			// strengthInfo either throw to readStrengthFile function or closes the program.

int runInfo(double x, double y)
{
	double averageSpeed;
	int choice;
	int choice2;

	averageSpeed = (y / x);

	cout << "You ran " << x << " miles in " << y << " minutes." << endl;

	cout << "That is an average of " << setprecision(3) << averageSpeed << " minutes a mile." << endl;

	do
	{
		cout << "Would you like to save todays run?" << endl;

		cout << "1. Yes" << endl;

		cout << "2. No" << endl;

		cin >> choice;

	} while (choice > 2 || choice < 1);

	switch (choice)
	{
	case 1:

		print(x, y, averageSpeed);

		do
		{ 
			cout << "Saved successfully. Would you like to view your last run?" << endl;

			cout << "1. Yes" << endl;

			cout << "2. No" << endl;

			cin >> choice2;

		} while (choice > 2 || choice < 1);
		
		switch (choice)
		{
		case 1:
			readRunFile();
			break;

		case 2:
			return(0);
			break;
		}

		break;

	case 2:
		return(0);
		break;
	}
}		// runInfo throws to print, readRunFile, or ends program.

void print(vector<vector<string>> data, int q)
{
	ofstream write;

	write.open("report.txt");

	if (write.is_open())
	{
			for (int y = 0; y < q; y++)
			{
				cout << '\n';

				for (int x = 0; x < 4; x++)
				{
					write << data[x][y] << " ";
			}
		}
	}
	else
	{
		cout << "File did not open." << endl;
	}

	write.close();

	cout << "Workout saved!" << endl;
}

void intro()
{
	int choice;
	double distance;
	double time;

	do
	{ 
		cout << "Will we be recording a run or strength training today?" << endl;

		cout << "1. Run" << endl << "2. Strength training" << endl;

		cin >> choice;
	} while (choice > 2 || choice < 1);
	

	if (choice == 1)   // User selects run.
	{
		cout << "Enter distance (miles): ";

		cin >> distance;

		cout << "Enter time (minutes): ";

		cin >> time;

		runInfo(distance, time);
	}
	else   // User selects strength
	{
		int exerciseNum;

		cout << "How many different workouts will we be tracking today?" << endl;

		cin >> exerciseNum;

		strengthInfo(exerciseNum);
	}
}		// Intro function throws to either runInfo or strengthInfo function.

void readStrengthFile(int q)
{
	ifstream reader;

	string words1;
	string words2;
	string words3;
	string words4;

	reader.open("report.txt");

	if (reader.is_open())
	{
		cout << "Workout - Sets - Reps - Weight" << endl;

		for (int x = 0; x < 4; x++)
		{
			while (reader >> words1 >> words2 >> words3 >> words4)
			{
				cout << setw(7) << words1 << " - " << words2 << " - " << words3 << " - " << words4 << endl;
			}
		}
		reader.close();
		
	}
	else
	{
		cout << "Could not open file." << endl;
	}

	reader.close();
}			// End of program.

void print(double x, double y, double z)
{
	ofstream write;

	write.open("report.txt");

	if (write.is_open())
	{
		write << x << " " << y << " " << z << endl;
	}
	else
	{
		cout << "File did not open." << endl;
	}
}

void readRunFile()
{
	ifstream reader;

	string words1;
	string words2;
	string words3;

	reader.open("report.txt");

	if (reader.is_open())
	{
		
		while (reader >> words1 >> words2 >> words3)
		{
			cout << "You ran " << words1 << " miles in " << words2 << " minutes." << " That is an average of " << words3 << " minutes a mile." << endl;
		}

	}
	else
	{
		cout << "Could not open file." << endl;
	}

	reader.close();
}