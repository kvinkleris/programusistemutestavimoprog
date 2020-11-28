#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "sudoku.h"
#define N 9

 int main()
{
    int potentialnumbers[10]={0};;
    int board[N][N];
    readSudoku(board);
    solve(board,potentialnumbers);
    return 0;
}



