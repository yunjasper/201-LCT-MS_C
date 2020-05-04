/*  Math for Computer Science - Rewrite in C
	Assignments 1 - Guessing Game
	
	The goal of this program is to create a computer game
	that guesses what number you are thinking, or for you
	to guess the number that the computer is thinking.
	
	Author: Jasper Yun
	Date:	2020-05-04
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

void ComputerGuesses(int min, int max);
void UserGuesses(int chosen);
void responseGuess(int chosen, int guess, bool* correctGuess);

int main() {
	while (1) {
		printf("Welcome to the Guessing Game.\n");
		printf("You can guess what number I am thinking of, ");
		printf("or I can guess what number you are thinking of.\n");
		printf("Press 3 to exit the game.\n");
		printf("Press 1 to guess my number, or 2 to let me guess: ");

		int input;
		scanf("%d", &input);

		if (input == 1) UserGuesses(rand() % 100); // random number from 0, 100
		else if (input == 2) {
			bool guessCorrect = false;
			while (!guessCorrect) {
				ComputerGuesses(INT_MIN, INT_MAX);	// set limits to MIN and MAX of int type
													// then recursively call until correct answer
			}
		}
		else if (input == 3) return 0;
		else {
			printf("invalid input, exiting program...\n");
			printf("program terminated.");
			return -1;
		}
	}
}

void ComputerGuesses(int min, int max) {
	bool correct = false;
	bool* correctGuess = &correct;
	int computerGuess;
	while (!correct) {
		computerGuess = (min + max) / 2;
		printf("Computer guess is: %d", computerGuess);
		printf("Your response: ");
	}
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