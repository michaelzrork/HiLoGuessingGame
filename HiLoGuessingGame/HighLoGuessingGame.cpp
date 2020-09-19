/*********************************
This game will prompt a user to guess a number with hints about
whether their guess is higher or lower than the number
//by Michael Rork
*********************************/


#include <iomanip>
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	srand(time(NULL)); //calls for a random number each time the program is run
	int randNum = rand() % 100 + 1; //sets random number to 1-100
	int guess = 0; //declare and initialize variable for the user's guess
	int tries = 5; //declare and initialize the variable for how many tries the user has

	cout << "Welcome to the Hi-Lo Game!\nHow many tries would you like? ";
	cin >> tries; //sets the number of tries the user has

	int triesCount = tries - 1; //used for calculating how many tries the user has left

	for (int i = 0;i < tries; i++) //loop for as many tries as the user inputs
	{
		cout << "\nWhat number am I thinking of?\nPlease enter 1 - 100 (enter 0 to end): ";
		cin >> guess;
		if (guess > 100 || guess < 0) //first check to see if the value is within the expected range
		{
			cout << "\nThat's outside the range of 1-100";
			if (i != triesCount) //if there are tries left...
			{
				cout << ". Let's try again! You have " << triesCount - i << " more tries!\n"; //calculate how many are left
			}
			else
			{
				cout << ", and you are out of tries!\n"; //if not, tell the user they are out of tries
			}
		}	
		else if (guess == 0) // check if the user wants to end
		{
			break;
		}
		else if (guess == randNum) //check if the guess is correct
		{
			cout << "\nWow! You guessed correctly!\n\nYou guessed: " << guess;
			break; //if they guessed correctly, end the loop
		}
		else if (guess > randNum) //check if the guess is too high
		{
			cout << "\nHmm. That's a bit too high";
			if (i != triesCount)
			{
				cout << ". Let's try again! You have " << triesCount - i << " more tries!\n";
			}
			else
			{
				cout << ", and you are out of tries!\n";
			}
		}
		else if (guess < randNum) //check if the guess is too low
		{
			cout << "\nHmm. That's a bit too low";
			if (i != triesCount)
			{
				cout << ". Let's try again! You have " << triesCount - i << " more tries!\n";
			}
			else
			{
				cout << ", and you are out of tries!\n";
			}
		}
		else //in case something doesn't work right, say something went wrong
		{
			cout << "\nHuh. Something went wrong... please try again! (You have " << triesCount - i << " more tries!)\n";
		}
	}

	cout << "\nThe random number is: " << randNum << endl;
}
