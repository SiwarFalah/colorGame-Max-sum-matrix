#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "colorGame.h"
#include "general.h"


#define ROWS 15
#define COLS 10
#define COLORS	3


void colorGame()
{
	int M[ROWS][COLS] = { 0 };
	int startValues[COLORS][2];// = { {5,3},{3,2},{5,3} }; //[i][j] for each color


	setStartValues((int*)startValues, COLORS,ROWS,COLS);
	
	printf("ROWS = %d COLS = %d\n", ROWS, COLS);
	printStartValues((int*)startValues, COLORS);


	colorTheBoard((int*)M, ROWS, COLS, COLORS, (int*)startValues);
}

void colorTheBoard(int* board,int rows, int cols, int colors, int* startValues)
{
	int bDone = 0;
	int roundNum = 0;
	int count;
	int totalCount = 0;

	while (!bDone)
	{
		for (int i = 0; i < colors && !bDone; i++)
		{
			count = expandColor(board, rows, cols, *(startValues+i*2), *(startValues+i*2+1), i + 1, roundNum);
			printf("\n---------------------\n");	
			totalCount += count;
			if (totalCount == rows * cols)
				bDone = 1;
		}
		printMat(board, rows, cols);
		roundNum++;
	}
	
}


int expandColor(int* board, int rows,int cols, int initRow, int initCol,  int colorNum, int roundNum)
{
	int boxCount;
	int i, j, start_row, start_col;
	int end_row, end_col;
	if (roundNum < 0)
		return -1;

	start_row = initRow - roundNum;
	if (start_row < 0)
		start_row = 0;

	start_col = initCol - roundNum;
	if (start_col < 0)
		start_col = 0;

	end_row = initRow + roundNum;
	if (end_row > rows - 1)
		end_row = rows - 1;

	end_col = initCol + roundNum;
	if (end_col > cols - 1)
		end_col = cols - 1;

	boxCount = 0;
	for (i = start_row; i <= end_row; i++)
	{
		for (j = start_col; j <= end_col; j++)
		{
			if ( *(board+i*cols +j) == 0)	//empty
			{
				boxCount++;
				*(board + i * cols + j) = colorNum;
			}
		}
	}
	
	return boxCount;
}



int isBoardFull(const int* board, int rows, int cols)
{
	int i, j;

	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			if (*board == 0)
				return 0;
			board++;
		}
	}
	return 1;
}

void setStartValues(int* startValues, int colors, int rows, int cols)
{
	for (int i = 0; i < colors; i++) //fill row index
	{
		*(startValues+i*2) = getRandomNum(0, rows - 1);
		*(startValues+i*2 +1) = getRandomNum(0, cols - 1);
		if (!checkUnique((int*)startValues, i))
			i--; //last point , exist
	}


}

int checkUnique(const int* arr, int lastIndex)
{
	for (int i = 0; i < lastIndex; i++)
	{
		if ((*(arr + i * 2) == *(arr + lastIndex * 2)) && (*(arr + i * 2 + 1) == *(arr + lastIndex * 2 + 1)))
			return 0;
	}
	return 1;
}

void printStartValues(const int* startValues, int colors)
{
	printf("The color start locations\n");
	for (int i = 0; i < colors; i++) //fill row index
		printf("%d: [%d,%d] \n", (i + 1), *(startValues+i*2), *(startValues+i*2+1));
	printf("\n");
}