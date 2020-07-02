#include<stdio.h>
#define ROWS 3
#define COLUMNS 3

int board[ROWS][COLUMNS] = {
    {1,1,1},
    {1,10,1},
    {1,2,1}
};

int minimum_path_sum(int grid[ROWS][COLUMNS])
{
    int dp[ROWS][COLUMNS] = {0};
    for(int row=0; row<ROWS; row++)
    {
        for(int column=0; column<COLUMNS; column++)
        {
            dp[row][column] += grid[row][column];
            if(row > 0 && column > 0)
            {
                int up = dp[row-1][column];
                int left = dp[row][column-1];
                dp[row][column] += up<left? up:left;
            }
            else if(row > 0)
            {
                dp[row][column] += grid[row-1][column];
            }
            else if(column > 0)
            {
                dp[row][column] += grid[row][column-1];
            }
            printf("%d ", dp[row][column]);
        }
        printf("\n");
    }
    return dp[ROWS-1][COLUMNS-1];
}

int main(int argc, char const *argv[])
{
    printf("Minimum path: %d\n", minimum_path_sum(board));
    return 0;
}
