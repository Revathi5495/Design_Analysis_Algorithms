#include <stdio.h>
#include <stdlib.h>
#define N 9
void print(int arr[N][N])
{
	int i,j;
     for (i = 0; i < N; i++)
      {
         for ( j = 0; j < N; j++)
            printf("%d ",arr[i][j]);
         printf("\n");
       }
}
int isSafe(int grid[N][N], int row,
                       int col, int num)
{
	int x;
    for ( x = 0; x <= 8; x++)
        if (grid[row][x] == num)
            return 0;
    for ( x = 0; x <= 8; x++)
        if (grid[x][col] == num)
            return 0;

    int startRow = row - row % 3,
                 startCol = col - col % 3;
    int i,j;
    for ( i = 0; i < 3; i++)
        for ( j = 0; j < 3; j++)
            if (grid[i + startRow][j +
                          startCol] == num)
                return 0;
 
    return 1;
}
int solveSuduko(int grid[N][N], int row, int col)
{
	int num;
    if (row == N - 1 && col == N)
        return 1;
 
    if (col == N)
    {
        row++;
        col = 0;
    }
   
    if (grid[row][col] > 0)
        return solveSuduko(grid, row, col + 1);
 
    for ( num = 1; num <= N; num++)
    {
        if (isSafe(grid, row, col, num)==1)
        {
            grid[row][col] = num;
            if (solveSuduko(grid, row, col + 1)==1)
                return 1;
    }
        grid[row][col] = 0;
    }
    return 0;
}
 
int main()
{
    int grid[N][N] = {{ 3, 1, 6, 5, 7, 8, 4, 9, 2 },
         { 5, 2, 9, 1, 3, 4, 7, 6, 8 },
         { 4, 8, 7, 6, 2, 9, 5, 3, 1 },
         { 2, 6, 3, 0, 1, 5, 9, 8, 7 },
         { 9, 7, 4, 8, 6, 0, 1, 2, 5 },
         { 8, 5, 1, 7, 9, 2, 6, 4, 3 },
         { 1, 3, 8, 0, 4, 7, 2, 0, 6 },
         { 6, 9, 2, 3, 5, 1, 8, 7, 4 },
         { 7, 4, 5, 0, 8, 6, 3, 1, 0 }};
 
    if (solveSuduko(grid, 0, 0)==1)
        print(grid);
    else
        printf("No solution exists");
 
    return 0;
}
