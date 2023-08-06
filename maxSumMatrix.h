#ifndef __SUM__
#define __SUM__


#define MIN_NUMBER  -17 //for random numbers
#define MAX_NUMBER  45


void findMaxSubMatrix();
int doFindMaxSubMatrix(const int* mat, int rows, int cols, int smallRows, int smallCols,int* pStartR, int* pStartC);
int sumSubMatrix(const int* mat, int startR, int startC, int rows, int cols, int smallRows, int smallCols);
void printSubMatrix(const int* mat, int startR, int startC, int rows, int cols, int smallRows, int smallCols);

#endif