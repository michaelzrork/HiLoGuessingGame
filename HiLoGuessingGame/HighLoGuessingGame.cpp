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
	// begin by setting the game to loop as long as playAgain is set to 'y'
	char playAgain = 'y';
	while (playAgain == 'y' || playAgain == 'Y')
	{
		/****************************
			SETTING UP THE GAME
		****************************/

		// initializing and declaring all necessary variables
		int triesCount = 0;				// used for calculating how many attempts the user has left
		int guess = 0;					// variable for the user's guess
		int highRange = 0;				// the number range for the game, determined later by the user
		int lowRange = 1;				// initializing lowRange as the low end of the range
		int tries = 0;					// variable for how many attempts the user has
		const int triesMax = 8;			// maximum number of tries user can attempt
		string attempts = "attempts";	// string used to change pluarality of the word when only 1 attempt remains

		std::cout << "\n*********************************************************\n\n\tWELCOME TO THE HI-LO GUESSING GAME!\n"
			<< "\n*********************************************************\n"
			<< "\nGuess the number I'm thinking of before you run out of attempts.\nGood luck!\n";
		
		// User determins the range of the game
		while (highRange < 10)
		{
			cout << "\nChoose a range of numbers to guess from (min of 10): 1 - ";
			cin >> highRange;
			if (highRange < 10) // only allow a range of 10 or higher
			{
				cout << "\nSorry, that's too low. Pleae choose a range of 10 or higher.";
			}
		}
		
		// Call for the random number within the user determined range
		srand(time(NULL));						// calls for a random number each time the program is run
		int randNum = rand() % highRange + 1;	// sets random number range from 1 through the user input
		
		// Determin number of attempts for the game
		while (tries < 1 || tries > triesMax)	// loops until user inputs a number in the correct range
		{
			cout << "How many attempts would you like? (choose between 1 and " << triesMax << "): ";
			cin >> tries;				

			// error message if user chooses outside allowed attempts
			if (tries > triesMax || tries < 1)
			{
				cout << "\nSorry, that is outside the range of 1-" << triesMax <<".\n";
			}

		}

		/****************************
			THE GAME BEGINS
		****************************/

		cout << "\n**************** GREAT! NOW LET'S BEGIN! ****************\n" 
			<< "\nWHAT NUMBER AM I THINKING OF?\n";
		
		// Loop until the user runs out of tries, guesses the correct answer, or stops the program
		triesCount = tries - 1;			// allows for loop to check how many tries are left
		for (int i = 0; i < tries; i++)	// loop for as many tries as the user inputs
		{
			// Check if there is only 1 attempt remaining and change plurality of word
			if (triesCount - i == 1)
			{
				attempts = "attempt";
			}
			
			// Prompt the user to guess the number and display the range the user can guess from
			// lowRange and highRange start as the lower and upper limits, and adjust as the user plays
			cout << "Please enter a number from " << lowRange << " - " << highRange << " (enter 0 to end): ";
			cin >> guess;
			
			// Check if the user wants to stop
			if (guess == 0)
			{
				break;
			}

			// Check to see if the value is within the expected range
			else if (guess > highRange || guess < lowRange)
			{
				cout << "\nThat's outside the range of " << lowRange << " - " << highRange;
				if (i != triesCount)	// if there are tries left calc how many remain
				{
					cout << ". You have " << triesCount - i << " more " << attempts << "!\n";
				}
				else
				{
					cout << ", and you are out of attempts!\n";
				}
			}

			// Check if the user's guess is correct
			else if (guess == randNum)
			{
				cout << "\nWow! You guessed correctly! (with only " << tries - (triesCount - i) << " " << attempts << "!)\n\nYou guessed: " << guess << "\n";
				break;					//if they guessed correctly, end the loop
			}
			
			// Check if the guess is too high
			else if (guess > randNum)
			{
				highRange = guess - 1;	// lowers the top range to 1 below the previous high guess
				cout << "\nThat's a bit too high";
				if (i != triesCount)
				{
					cout << ". You have " << triesCount - i << " more " << attempts << "!\n";
				}
				else
				{
					cout << ", and you are out of attempts!\n";
				}
			}

			// Check if the guess is too low
			else if (guess < randNum)
			{
				lowRange = guess + 1;	// raises the low range to 1 above the previous low guess
				cout << "\nThat's a bit too low";
				if (i != triesCount)
				{
					cout << ". You have " << triesCount - i << " more " << attempts << "!\n";
				}
				else
				{
					cout << ", and you are out of attempts!\n";
				}
			}

			// Error message if something didn't work right
			else
			{
				cout << "\nSomething went wrong. Please try again!\n(You have " << triesCount - i << " more " << attempts << "!)\n";
			}
		}

		cout << "The random number was: " << randNum << endl
			<< "\nWould you like to play again? (please enter 'y' or 'n') ";	// ask if user would like to play again
		cin >> playAgain;														// if answer is anything other than y or Y, program ends
		cout << endl;
	}
	return 0;
}
