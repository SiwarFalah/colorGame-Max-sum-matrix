#include <stdio.h>
#include <stdlib.h>

#include "general.h"


int getRandomNum(int min, int max)
{
	return rand() % (max - min + 1) + min;
}

void getArray(int* a, int size)
{
	int i;
	printf("Please enter %d integers\n", size);
	for (i = 0; i < size; i++)
	{
		scanf("%d", a);
		a++;
	}
}


void initMat(int* mat, int row, int col)
{
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			printf("enter element %d  %d :\t", i, j);
			scanf("%d", mat);
			mat++;
		}
	}
}

void printMat(int* mat,int row, int col)
{

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++)
		{
			printf("%5d", *mat);
			mat++;
		}
		printf("\n");
	}
}

int getLegalSize(const char* msg, int max) {
	int size;
	do {
		printf("%s between 1 and %d\n", msg, max);
		scanf("%d", &size);
	} while (size<1 || size > max);
	return size;
}

void setRandomNumbersToMatrix(int* mat, int min, int max, int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			*mat = getRandomNum(min, max);
			mat++;
		}
	}
}