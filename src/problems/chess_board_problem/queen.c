#include <stdio.h>
#include <stdbool.h>

void display_board(int board[8][8])
{ 
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            printf("%d\t", board[i][j]);
        }
        printf("\n");
    }
}

void place_queen(int board[8][8], int row, int col)
{
    board[row][col] = 1;
}

void remove_queen(int board[8][8], int row, int col)
{
    board[row][col] = 0;
}

bool is_queen_safe(int board[8][8], int row, int col)
{
    for(int i = 0; i < row; i++)
    {
        if(board[i][col] == 1)
        {
            return false;
        }
    }

    int j_col=col-1;
    for(int i = row-1; i >= 0 && j_col >= 0; i--)
    {
        if(board[i][j_col--] == 1)
        {
            return false;
        }
    }

    int k_col = col+1;
    for(int i = row-1; i >= 0 && k_col < 8; i--)
    {
        if(board[i][k_col++] == 1)
        {
            return false;
        }
    }

    return true;
}

bool solve_queen(int board[8][8], int row)
{
    if(row == 8)
    {
        return true;
    }

    for(int i = 0; i < 8; i++)
    {
        if(is_queen_safe(board, row, i))
        {
            place_queen(board, row, i);

            if(solve_queen(board, row+1))
            {
                return true;
            }

            remove_queen(board, row, i);
        }
    }

    return false;
}

int main()
{
    int board[8][8] = {0};

    if(solve_queen(board, 0))
    {
        display_board(board);
    }
    else{
        printf("No solution");
    }

    return 0;
}