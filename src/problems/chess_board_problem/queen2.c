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

bool check_queen_safe(int board[8][8], int pos)
{
    int row, col;
    int *p = &row;
    int *q = &col;

    pos_row_col(pos, p, q);

    // horizontal
    for(int i = 0; i < 8 ;i++)
    {
        if(i==col)
            continue;
        if(board[row][i] == 1)
        {
            return false;
        }
    }

    // vertical
    for(int i = 0; i < 8; i++)
    {
        if(i==row)
            continue;
        if(board[i][col] == 1)
        {
            return false;
        }
    }

    // left upper diagonal
    for(int i = row-1, j = col-1; i >= 0 && j >= 0 ; i--, j--)
    {
        if(board[i][j] == 1)
        {
            return false;
        }
    }

    // right upper diagonal
    for(int i = row-1,j=col+1; i >= 0 && j < 8; i--,j++)
    {
        if(board[i][j] == 1)
        {
            return false;
        }
    }

    // left lower diagonal
    for(int i = row+1, j=col-1; i < 8 && j >= 0; i++,j--)
    {
        if(board[i][j] == 1)
        {
            return false;
        }
    }

    // right lower diagonal
    for(int i = row+1, j = col +1; i < 8 && j < 8; i++,j++)
    {
        if(board[i][j] == 1)
        {
            return false;
        }
    }

    return true;

}

void place_queen(int board[8][8], int pos)
{
    int row, col;
    int *p=&row;
    int *q=&col;
    pos_row_col(pos, p, q);
    board[row][col] =1;
}

void remove_queen(int board[8][8], int pos)
{
    int row, col;
    int *p = &row;
    int *q = &col;
    pos_row_col(pos, p,q);

    board[row][col]=0;

}

bool solve_queen(int board[8][8], int pos, int number_of_queen)
{
    if(number_of_queen == 8)
    {
        return true;
    }

    if(pos == 64)
    {
        return false;
    }

    for(int i = pos; i < 64; i++)
    {
        if(check_queen_safe(board, i))
        {
            place_queen(board, i);

            if(solve_queen(board , i+1, number_of_queen+1))
            {
                return true;
            }

            remove_queen(board, i);
        }   
    }
    return false;
}
int main()
{
    int board[8][8]={0};

    if(solve_queen(board,0,0))
    {
        display_board(board);
    }
    else{
        printf("No solution found\n");
    }

    return 0;

}