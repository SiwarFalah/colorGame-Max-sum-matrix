
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include "maxSumMatrix.h"
#include "colorGame.h"

char showMenu();


int main()
{
	char option;
	int stop = 0;
	srand((unsigned)time(NULL));
	do
	{
		option = showMenu();

		switch (option)
		{
		case 'S':
		case 's':
			findMaxSubMatrix();
			break;

		case 'C':
		case 'c':
			colorGame();
			break;

		case 'E':
		case 'e':
			printf("Bye bye\n");
			stop = 1;
			break;

		default:
			printf("Wrong option\n");
			break;
		}
		getchar(); //clean the enter
	} while (!stop);

	return 1;
}

char showMenu()
{
	char tav;
	printf("\n\n");
	printf("Please choose one of the following options\n");
	printf("S/s - Biggest Matrix Sum\n");
	printf("C/c - Color Game\n");
	printf("E/e - Quit\n");

	scanf("%c", &tav);
	return tav;
}
