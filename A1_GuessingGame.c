/*  Math for Computer Science - Rewrite in C
	Assignments 1 - Guessing Game
	
	The goal of this program is to create a computer game
	that guesses what number you are thinking, or for you
	to guess the number that the computer is thinking.
	
	Author:		Jasper Yun
	Date:		2020-05-04
	Version:	1.0
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

#define GUESS_MIN 0		// minimum user chosen value
#define GUESS_MAX 100	// maximum user chosen value

void ComputerGuesses(int min, int max);
void UserGuesses(int chosen);
void responseGuess(int chosen, int guess, bool* correctGuess);

int main() {
	printf("Welcome to the Guessing Game.\n");
	printf("You can guess what number I am thinking of, ");
	printf("or I can guess what number you are thinking of.\n");
	while (1) {
		printf("Press 1 to guess my number between 0 and %d.\n", GUESS_MAX);
		printf("Press 2 to let me guess your number between %d and %d.\n", GUESS_MIN, GUESS_MAX);
		printf("Press 3 to exit the game.\n");
		printf("Please choose an option (1, 2, or 3): ");

		// take user input to choose an option
		int input;
		scanf("%d", &input);
		
		printf("\n");

		if (input == 1) UserGuesses(rand() % GUESS_MAX); // random number from 0, MAX
		else if (input == 2) ComputerGuesses(GUESS_MIN, GUESS_MAX);
		else if (input == 3) return 0;	// exit program
		else {
			printf("Invalid input, please try again.\n");// loop until valid option chosen
		}
	}
}

void ComputerGuesses(int min, int max) {
	printf("If my guess is too high, please enter 2. If my guess is too low, please enter 0.\n");
	printf("If my guess is correct, please enter 1.\n");

	bool correct = false;
	bool* correctGuess = &correct;
	int computerGuess;
	
	while (!correct) {
		computerGuess = (min + max) / 2;
		printf("My guess is: %d. \n", computerGuess);
		printf("Your response: ");
		int userResponse;
		scanf("%d", &userResponse);
		if (userResponse == 0) min = computerGuess;
		else if (userResponse == 2) max = computerGuess;
		else break;
	}
	printf("Yay! I guessed your number.\n\n");
}

void UserGuesses(int chosen) {
	bool correct = false;
	bool* correctGuess = &correct;
	while (!correct) {
		printf("Please guess a number between 0 and 100: ");
		int guess;
		scanf("%d", &guess);

		responseGuess(chosen, guess, correctGuess);
	}
}

void responseGuess(int chosen, int guess, bool* correctGuess) {
	if (chosen < guess) printf("Your guess is too high.\n");
	else if (chosen == guess) {
		printf("Correct guess!\n\n");
		*correctGuess = true;
	}
	else printf("Your guess is too low.\n");
}