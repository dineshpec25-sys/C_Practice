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
void place_rook(int board[8][8], int row, int col)
{
    board[row][col] = 1;
}

void remove_rook(int board[8][8], int row, int col)
{
    board[row][col] = 0;
}
bool check_is_rook_safe(int board[8][8], int row, int col)
{
    // vertical check
    for(int i = row -1 ; i >= 0; i--)
    {
        if(board[i][col] == 1)
        {
            return false;
        }
    }

    return true;
}

bool solve_rook(int board[8][8], int row)
{
    if(row == 8)
    {
        return true;
    }

    for(int i = 0 ; i< 8 ;i++)
    {
        if(check_is_rook_safe(board, row, i))
        {
            place_rook(board, row, i);

            if(solve_rook(board, row+1))
            {
                return true;
            }
            remove_rook(board, row, i);
        }
    }

    return false;
}
int main()
{
    int board[8][8]={0};

    if(solve_rook(board, 0))
    {
        display_board(board);
    }
    else{
        printf("No solution found\n");
    }

    return 0;
}