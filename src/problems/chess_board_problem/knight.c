#include<stdio.h>
#include<stdbool.h>

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

void pos_row_col(int pos, int *row, int *col)
{
    *row = pos / 8;
    *col = pos % 8;
}

bool check_knight_safe(int board[8][8], int pos)
{
    int row, col;

    pos_row_col(pos, &row, &col);


    int row_move[8] = 
    {
        -2, -2,
        -1, -1,
         1,  1,
         2,  2
    };


    int col_move[8] =
    {
        -1,  1,
        -2,  2,
        -2,  2,
        -1,  1
    };


    for(int i = 0; i < 8; i++)
    {
        int new_row = row + row_move[i];
        int new_col = col + col_move[i];


        // check board boundary
        if(new_row >= 0 && new_row < 8 &&
           new_col >= 0 && new_col < 8)
        {
            if(board[new_row][new_col] == 1)
            {
                return false;
            }
        }
    }


    return true;
}
void place_knight(int board[8][8], int pos)
{
    int row, col;
    int *p=&row;
    int *q=&col;
    pos_row_col(pos, p, q);
    board[row][col] =1;
}

void remove_knight(int board[8][8], int pos)
{
    int row, col;
    int *p = &row;
    int *q = &col;
    pos_row_col(pos, p,q);

    board[row][col]=0;

}

bool solve_knight(int board[8][8], int pos, int number_of_knight)
{
    // if(number_of_knight == 8)
    // {
    //     return true;
    // }

    if(pos == 63)
    {
        return true;
    }

    for(int i = pos; i < 64; i++)
    {
        if(check_knight_safe(board, i))
        {
            place_knight(board, i);

            if(solve_knight(board , i+1, number_of_knight+1))
            {
                return true;
            }

            remove_knight(board, i);
        }   
    }
    return false;
}
int main()
{
    int board[8][8]={0};

    if(solve_knight(board,0,0))
    {
        display_board(board);
    }
    else{
        printf("No solution found\n");
    }

    return 0;

}