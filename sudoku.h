#define N 9
 bool isFull(int board[N][N]);
 void readSudoku(int board [N][N]);
 void Possiblenumbers(int board[N][N],int i,int j,int potentialnumbers[]);
 void solve(int board [N][N],int potentialnumbers[]);
 void printboard(int board[N][N]);
