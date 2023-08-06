#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "maxSumMatrix.h"
#include "general.h"

	
#define ROWS 20
#define COLS 15


void findMaxSubMatrix()
{

	int mat[ROWS][COLS];
	int maxMatrixSum;
	int startMaxRow, startMaxCol;

	printf("ROWS = %d COLS = %d\n", ROWS, COLS);

	int bigRows = getLegalSize("insert number of rows for big Matrix",ROWS);
	int bigCols = getLegalSize("insert number of columns for big Matrix:",COLS);

	printf("Big Mat Rows = %d Big Mat Cols = %d\n", bigRows, bigCols);
	printf("Random min = %d Random max = %d\n", MIN_NUMBER, MAX_NUMBER);


	setRandomNumbersToMatrix( (int*)mat,MIN_NUMBER,MAX_NUMBER, bigRows, bigCols);

	printMat((int*)mat,bigRows, bigCols);


	int smallRows = getLegalSize("insert number of rows for small Matrix", bigRows);
	int smallCols = getLegalSize("insert number of columns for small Matrix:", bigCols);


	maxMatrixSum = doFindMaxSubMatrix((int*)mat, bigRows,bigCols, smallRows, smallCols,&startMaxRow,&startMaxCol);

	printf("The max of sum of Sub Matrix is: %d\n", maxMatrixSum);
	printf("The max matrix start at %d*%d\n", startMaxRow,startMaxCol);

	printSubMatrix((int*)mat, startMaxRow, startMaxCol, bigRows, bigCols, smallRows, smallCols);
	
}

int doFindMaxSubMatrix(const int* mat, int rows,int cols, int smallRows, int smallCols,int* pStartR, int* pStartC) 
{
	int tmpMatrixSum=0;
	int maxMatrixSum = sumSubMatrix(mat, 0, 0, rows, cols, smallRows, smallCols);

	int maxSubMatrixStartRow =0;
	int maxSubMatrixStartCol =0;

	for (int  i=0 ; i <= (rows - smallRows) ; i++){
		for (int  j=0 ; j <=(cols - smallCols) ; j++) {

			//find sum of small matrix in big matrix
			tmpMatrixSum=sumSubMatrix(mat,i,j, rows, cols, smallRows, smallCols);
			if (tmpMatrixSum>maxMatrixSum){
				maxMatrixSum=tmpMatrixSum;
				maxSubMatrixStartRow =i;
				maxSubMatrixStartCol =j;

			}
		}
	}
	
	*pStartR = maxSubMatrixStartRow;
	*pStartC = maxSubMatrixStartCol;
	return maxMatrixSum;
}

int sumSubMatrix(const int* mat,int startR, int startC, int rows, int cols, int smallRows, int smallCols)
{
	int sum = 0;
	
	//check if all small matrix in bigg matrix, should not happened!!!
	if (startR + smallRows > rows || startC + smallCols > cols)
		return MIN_NUMBER * smallRows* smallCols; //the min possible
	
	const int* startPosMat = (int*)mat + startR*cols + startC;
	for (int i = 0; i < smallRows; i++)
	{
		for (int j = 0; j < smallCols; j++)
		{
			sum += *(startPosMat+ j);
		}
		startPosMat += cols;
	}
	return sum;
}

void printSubMatrix(const int* mat, int startR, int startC, int rows, int cols, int smallRows, int smallCols)
{
	const int* startPosMat = (int*)mat + startR * cols + startC;
	for (int i = 0; i < smallRows; i++)
	{
		for (int j = 0; j < smallCols; j++)
		{
			printf("%5d", *(startPosMat + j));
		}
		printf("\n");
		startPosMat += cols;
	}
}

