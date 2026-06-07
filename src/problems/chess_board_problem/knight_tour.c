#include<stdio.h>
#include<stdbool.h>

typedef struct co
{
    int row;
    int col;
} co;

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

bool move_safe(int board[8][8],int row,int col)
{
    if((board[row][col]) == 0)
    {
        return true;
    }
    return false;
}

void move_knight(int board[8][8],int row,int col, int move_number)
{
    board[row][col]= move_number;
}

void back_to_previous_position(int board[8][8], int row, int col)
{
    board[row][col] = 0;
}

bool solve_knight_path(int board[8][8], int move_number, int row, int col)
{
    if(move_number > 64)
    {
        return true;
    }
    co possible_path[8];
    co *z=possible_path;
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

    int count = 0;

    for(int i = 0; i < 8; i++)
    {
        int new_row = row + row_move[i];
        int new_col = col + col_move[i];

       if(new_row >= 0 && new_row < 8 &&
       new_col >= 0 && new_col < 8)
        {
            possible_path[count].row = new_row;
            possible_path[count].col = new_col;

            count++;
        }
    }

    for(int i = 0; i < count ;i++)
    {
        if(move_safe(board,possible_path[i].row,possible_path[i].col))
        {
            move_knight(board,possible_path[i].row,possible_path[i].col, move_number);

            if(solve_knight_path(board, move_number+1, possible_path[i].row,possible_path[i].col))
            {
                return true;
            }

            back_to_previous_position(board,possible_path[i].row,possible_path[i].col);
        }
    }
    return false;
}
int main()
{
    int board[8][8]={0};
    int pos=1;
    board[0][0]=1;
    if(solve_knight_path(board,pos+1,0,0))
    {
        display_board(board);
    }
    else
    {
        printf("Can't find path");
    }

    return 0;
}