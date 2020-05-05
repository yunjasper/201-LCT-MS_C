/*  Math for Computer Science - Rewrite in C
	Assignments 1 - Guessing Game

	The goal of this program is to implement the Quotient 
	Remainder Theorem from Modular Arithmetic.

	Author:		Jasper Yun
	Date:		2020-05-05
	Version:	1.0
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

void Quotient(int a, int d, int* q, int* r);
void RecursiveQuotient(int a, int d, int* q, int* r);
void chooseNums(int* a, int* d);

int main() 
{
	printf("Welcome to the QRT Implementor. \n");
	printf("This program implements the Quotient Remainder Theorem.\n");
	
	while (1) 
	{
		printf("Press 1 to divide two integers a and d using the standard quotient.\n");
		printf("Press 2 to divide two integers a and d using the recursive quotient.\n");
		printf("Press 3 to reduce an integer a modulo n.\n");
		printf("Press 4 to exit.\n");
		printf("Please choose an option now: ");
		
		int userInput;
		scanf("%d", &userInput);

		switch (userInput) 
		{
			case 1:
			{
				int a, d, q, r;	// initialize memory, wait for user input from next function
				int* pa = &a;	// pointers to a, d, q, r
				int* pd = &d;
				int* pq = &q;
				int* pr = &r;
				chooseNums(pa, pd);

				Quotient(a, d, pq, pr);

				printf("The (quotient, remainder) is (%d, %d).\n\n", q, r);
				break;
			}
			case 2:
			{
				int a, d, q = 0, r;
				int* pa = &a;
				int* pd = &d;
				int* pq = &q;
				int* pr = &r;

				chooseNums(pa, pd);
				RecursiveQuotient(a, d, pq, pr);
				printf("The (quotient, remainder) is (%d, %d).\n", q, r);
				break;
			}
			case 3:
			{
				int a, d, q = 0, r;
				int* pa = &a;
				int* pd = &d;
				int* pq = &q;
				int* pr = &r;

				chooseNums(pa, pd);
				RecursiveQuotient(a, d, pq, pr);
				printf("The result of %d reduced modulo %d is %d.\n", a, d, r);
				break;
			}
			case 4:
				return 0;

			default:
				printf("Invalid input, please try again.\n");
				break;
		}
	}
}


void Quotient(int a, int d, int* q, int* r) 
{
	*r = a;	// initial remainder is the entire a
	*q = 0;	// initial quotient is 0

	while (*r >= d)
	{
		*r -= d;
		*q += 1;
	}
	while (*r < 0)
	{
		*r += d;
		*q -= 1;
	}
}

void RecursiveQuotient(int a, int d, int* q, int* r)
{
	if (a > 0)
	{
		if (a < d)
		{
			*r = a;	// remainder is what is left
		}
		else
		{
			*q += 1;

			return RecursiveQuotient(a - d, d, q, r);	// recursive step
		}
	}
	else if (a < 0)
	{
		if (a > 0)
		{
			*r = a;
		}
		else
		{
			*q -= 1;
			return RecursiveQuotient(a + d, d, q, r);
		}
	}
}

void chooseNums(int* a, int* d)
{
	printf("Please choose an integer a to be reduced modulo d: ");
	scanf("%d", a);

	printf("Please choose a modulo base d: ");
	scanf("%d", d);

	printf("You have chosen a = %d, and d = %d.\n", *a, *d);
}