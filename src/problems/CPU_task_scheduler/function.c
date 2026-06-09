#include </home/dinesh-p/C_Practice/src/problems/CPU_task_scheduler/header.h>

process *get_input(int total)
{
    printf("Enter the number of process :");
    scanf("%d", &total);

    process *total_process;
    total_process=malloc(total * sizeof(process));

    for(int i = 0; i < total; i++)
    {
        printf("PID : ");
        scanf("%d", &total_process[i].PID);

        printf("Arrival Time : ");
        scanf("%d", &total_process[i].arrival_time);

        printf("Burst Time : ");
        scanf("%d", &total_process[i].burust_time);
    }

    return total_process;
}

int *check_arrival_time(process *input, int *count ,int *total, int *clk)
{
    int *available = NULL;

    int *count = 0;

    for(int i = 0; i < total; i++)
    {
        if(input[i].arrival_time <= clk)
        {
            (*count)++;

            available = realloc(
                available,
                (*count) * sizeof(int)
            );

            available[*count - 1] = input[i].PID;
        }
    }

    return available;
}

int run_process(process *input,int avalible_process[], int *clk, int completed_process, int capable)
{
    int *pid;
    
    for(int i = 0; i < capable; i++)
    {
        for(int j = i+1; j < capable; j++)
        {
            if(input[i].burust_time > input[j].burust_time)
            {
                
            }
        }
    }
}