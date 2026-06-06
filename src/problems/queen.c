#include <stdio.h>
#include <stdbool.h>

void setqueen(int board[8][8], int row, int clo)
{
   board[row][clo] = 1;
}
bool is_queen_safe(int board[8][8], int row, int clo)
{
    // horizontal check
    for(int i = 0; i < 8; i++)
    {
        if(!(i == row))
        {
            if(board[i][clo] == 1)
            {
                return false;
            }
        }
    }

    // vertical check
    for(int j = 0; j < 8; j++)
    {
        if(!(j == clo))
        {
            if(board[row][j] == 1)
            {
                return false;
            }
        }
    }

    // diagonal check

}
void reset_queen(int board[8][8], int row, int clo)
{
    board[row][clo] = 0;
}
void show_board(int board[8][8])
{
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            printf("%d \t", board[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int board[8][8] = {0};
    bool status=true;
    int (*c)[8] = board;
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            setqueen(c, j, i);
            status=is_queen_safe(c, j, i);
            if(!status)
            {
                reset_queen(c, j, i);
            }
        }
    }    
    show_board(c);
    return 0;
}