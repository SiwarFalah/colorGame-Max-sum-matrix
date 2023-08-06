#ifndef __COLOR_GAME__
#define __COLOR_GAME__

void colorGame();
void colorTheBoard(int* board, int rows, int cols, int colors, int* startValues);
int expandColor(int* board, int rows, int cols, int initRow, int initCol, int colorNum, int roundNum);
int isBoardFull(const int* board, int rows, int cols);
int checkUnique(const int* arr, int lastIndex);
void setStartValues(int* startValues, int colors,int rows,int cols);
void printStartValues(const int* startValues, int colors);



#endif