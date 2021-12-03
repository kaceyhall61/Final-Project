#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <fstream>
#include <vector>


using namespace std;

int main() 
{

	string workoutNames[10];
	int workoutData[10][2];
	int choice;


	do 
	{
		cout << "Welcome to Centurion Gym!" << endl << endl;

		cout << "Will we be logging cardio or strength first?" << endl;

		cout << "1. Cardio" << endl;

		cout << "2. Strength" << endl;

		cin >> choice;

	} while (choice > 2 || choice < 1);

		switch (choice)
		{
		case 1:
		{
			cout << "Case 1 works." << endl;
		}
			break;

		case 2:
		{
			cout << "Case 2 works" << endl;
		}
			break;
		}
	
	system("pause");
	return(0);
}