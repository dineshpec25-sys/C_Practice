#include<stdio.h>
#include<stdlib.h>

typedef struct process
{
    int PID;
    int arrival_time;
    int burust_time;
} process;

process *get_input(int total);
int check_arrival_time(process *input,int *count, int *q, int *clk);
int run_process(process *input,int avalible_process[], int *clk, int completed_process, int capable);