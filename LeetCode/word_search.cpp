#include<stdio.h>
#define ROWS 3
#define COLUMNS 3

char crossword[ROWS][COLUMNS] = {
    {'a','c','d'},
    {'p','f','v'},
    {'p','c','d'}
};

int dfs_search(char grid[ROWS][COLUMNS], int row, int col, int count, char* word, int length)
{
    if(count == length)
    {
        return 1;
    }
    if(row < 0 || row >= ROWS || col < 0 || col >= COLUMNS || grid[row][col] != word[count])
    {
        return 0;
    }
    char temp = grid[row][col];
    grid[row][col] = ' ';
    int found = dfs_search(grid, row+1, col, count+1, word, length) ||
                dfs_search(grid, row-1, col, count+1, word, length) ||
                dfs_search(grid, row, col+1, count+1, word, length) ||
                dfs_search(grid, row, col-1, count+1, word, length);
    grid[row][col] = temp;
    return found;
}

int find_word(char grid[ROWS][COLUMNS], char *word, int length)
{
    for (int row = 0; row < ROWS; row++)
    {
        for (int col = 0; col < COLUMNS; col++)
        {
            if(grid[row][col] == word[0] && dfs_search(grid, row, col, 0, word, length))
            {
                return 1;
            }
        }
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    int found = find_word(crossword, (char*)"appcd\0", 3);
    printf("Found: %d\n", found);
    return 0;
}
