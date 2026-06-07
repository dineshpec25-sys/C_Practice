#include<stdio.h>
#include<string.h>

void display_maze(int board[8][8])
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

solve_rat(int maze[8][8],int path[8][8], int row, int col)
{
    
}
int main()
{
    int maze[8][8]={
    
        {1, 0, 0, 0, 0, 0, 0, 0},
        {1, 1, 1, 1, 0, 1, 1, 0},
        {0, 0, 0, 1, 0, 1, 0, 0},
        {1, 1, 0, 1, 1, 1, 1, 0},
        {1, 0, 0, 0, 0, 0, 1, 0},
        {1, 1, 1, 1, 1, 0, 1, 0},
        {0, 0, 0, 0, 1, 0, 1, 1},
        {0, 1, 1, 1, 1, 1, 0, 1}
    };

    int path[8][8];

    int row
    if(solve_rat(maze,path,0,0))
    {
        display_maze(maze);
    }
    else
    {
        printf("No path found");
    }

    return 0;
}