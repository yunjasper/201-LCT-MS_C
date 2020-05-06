/*  Math for Computer Science - Rewrite in C
	Assignment 3 - Euclidean Algorithm

	The goal of this program is to implement the 
	Euclidean Algorithm.

	Author:		Jasper Yun
	Date:		2020-05-05
	Version:	1.0
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

void Euclidean(int a, int b, int* d, int* s, int* t);
void EuclideanFull(int a, int b, int* d, int* s, int* t);
void EuclideanNonRecursive(int a, int b, int* d, int* s, int* t);
void Quotient(int a, int d, int* q, int* r);
void chooseNums(int* a, int* b);

int main()
{
	printf("Welcome to my Euclidean Algorithm implementation.\n");
	while (1)
	{
		printf("Press 1 to find the greatest common factor (GCF) between two integers a and b.\n");
		printf("Press 2 to write the GCF of two integers a and b as a linear combination of a and b.\n");
		printf("Press 3 to give all the steps of the Euclidean Algorithmon two integers a and b.\n");
		printf("Press 4 to find the inverse of an integer a modulo n.\n");
		printf("Press 5 to leave.\n");
		printf("Please choose an option: ");
		
		int userchoice;
		scanf("%d", &userchoice);

		switch (userchoice)
		{
			case 1:
			{
				int a, b, d, s, t;
				
				chooseNums(&a, &b);
				Euclidean(a, b, &d, &s, &t);

				printf("The GCF of %d and %d is %d.\n", a, b, d);
				printf("s: %d, and t: %d", s, t);
			}
			case 2:
			{

			}
			case 3:
			{

			}
			case 4:
			{

			}
			case 5:
				return 0;
			default:
				printf("Invalid input, please try again.\n");
		}

	}
}

void Euclidean(int a, int b, int* d, int* s, int* t)
{
	int q, r, d1, s1, t1;
	Quotient(a, b, &q, &r);
	if (r == 0)
	{
		*d = b;
		*t = 1;
		*s = 0;
		return;
	}
	else
	{
		Euclidean(b, r, &d1, &s1, &t1);
		*d = d1;
		*s = t1;
		*t = s1 - t1 * q;
	}
}

void EuclideanFull(int a, int b, int* d, int* s, int* t)
{

}

void EuclideanNonRecursive(int a, int b, int* d, int* s, int* t)
{

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

void chooseNums(int* a, int* b)
{
	printf("Please choose an integer a: ");
	scanf("%d", a);

	printf("Please choose an integer b: ");
	scanf("%d", b);
}