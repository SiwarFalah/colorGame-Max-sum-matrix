#ifndef __GENERAL__
#define __GENERAL

// get the numbers from the user
void	getArray(int* a, int size);
void	initMat(int* mat,int row, int col);
void	printMat(int* mat, int row, int col);

int		getLegalSize(const char* msg, int max);

//General function to set random number in the range of min to max
int		getRandomNum(int min, int max);
void	setRandomNumbersToMatrix(int* mat, int min, int max, int rows, int cols);


#endif
