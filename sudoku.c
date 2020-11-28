#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "sudoku.h"
#define N 9
void readSudoku(int board [N][N])
{
    FILE *fp;
    int temp;
    fp=fopen("sudoku.txt","r");
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            fscanf(fp,"%d",&temp);
            board[i][j]=temp;
        }
    }
}
 bool isFull(int board[N][N])
{
    for(int x=0;x<9;x++)
    {

      for(int y=0;y<9;y++)
      {
          if(board[x][y]==0)
          {
              return false;
          }
      }
    }
    return true;
}
void Possiblenumbers(int board[N][N],int i,int j,int potentialnumbers[])
{
    for(int i=1;i<10;i++)
    {
        potentialnumbers[i]=0;
    }
   for(int y=0;y<9;y++)
   {

       if(board[i][y]!=0)
       {
           potentialnumbers[board[i][y]]=1;


       }
   }
   for(int x=0;x<9;x++)
   {
       if(board[x][j]!=0)
       {
           potentialnumbers[board[x][j]]=1;
       }

   }


int   k=0;
  int  l=0;
  k=(i/3)*3;
  l=(j/3)*3;
   for(int x=k;x<k+3;x++)
   {
       for(int y=l;y<l+3;y++)
       {
           if(board[x][y]!=0)
           {
               potentialnumbers[board[x][y]]=1;
           }
       }

    }


       for(int i=1;i<=10;i++)
       {

           if(potentialnumbers[i]==0)
           {
               potentialnumbers[i]=i;
           }
           else
           {
               potentialnumbers[i]=0;
           }
       }

       return;

}


void solve(int board [N][N],int potentialnumbers[])
{
    int  i=0;
    int  j=0;
    int potentialentries[10]={0};
    int goodcol=0;
    int value=0;
    int maxcol=0;
    if(isFull(board)==true)
    {

        printf("Sudoku has been solved.");
        printboard(board);
        return;
    }
    else
    {
        for(int x=0;x<9;x++)
        {
            for(int y=0;y<9;y++)
            {
                if(board[x][y]!=0)
                {
                    value=value+1;
                }

            }
            if(value==9)
            {
                value=0;
            }
            if(maxcol<value)
                {
                    maxcol=value;
                    goodcol=x;
                }
                value=0;
       }
i=goodcol;

           for(int y=0;y<9;y++ )
           {
               if(board[goodcol][y]==0)
               {
                 j=y;
                 break;
               }
           }
           //printf(" %d %d ",goodcol,j);

        Possiblenumbers(board,i,j,potentialnumbers);
        for(int i=1;i<10;i++)
        {
            //printf(" %d ",potentialnumbers[i]);
            potentialentries[i]=potentialnumbers[i];
        }
        for(int x=1;x<10;x++)
        {
         //Possiblenumbers(board,i,j,potentialnumbers);
            if(potentialentries[x]!=0)
            {
//printboard(board);
                board[i][j]=potentialentries[x];
                solve(board,potentialnumbers);

            }
         board[i][j]=0;
        }
 return;
}
}




void printboard(int board[N][N])
{
    printf("\n");
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            printf(" %d ",board[i][j]);
        }
        printf("\n");
    }

}
