#include <stdio.h>
#include <stdlib.h>

typedef struct process
{
    int pid;
    int arrival_time;
    int burst_time;
    int completion_time;
} process;

// Comparator for qsort: sort by arrival_time first, then by pid as tie-breaker
int compare_processes(const void *a, const void *b)
{
    process *p1 = (process *)a;
    process *p2 = (process *)b;

    if (p1->arrival_time != p2->arrival_time)
        return p1->arrival_time - p2->arrival_time;

    return p1->pid - p2->pid;
}

process *get_input(int *total)
{
    printf("Enter number of processes: ");
    scanf("%d", total);

    process *plist = malloc((*total) * sizeof(process));

    for (int i = 0; i < *total; i++)
    {
        printf("\nProcess %d\n", i + 1);

        printf("PID: ");
        scanf("%d", &plist[i].pid);

        printf("Arrival Time: ");
        scanf("%d", &plist[i].arrival_time);

        printf("Burst Time: ");
        scanf("%d", &plist[i].burst_time);
    }

    return plist;
}

void run_fcfs(process *plist, int total)
{
    int clock = 0;

    for (int i = 0; i < total; i++)
    {
        // If CPU is idle waiting for this process to arrive, jump clock forward
        if (clock < plist[i].arrival_time)
            clock = plist[i].arrival_time;

        clock += plist[i].burst_time;
        plist[i].completion_time = clock;
    }
}

void print_results(process *plist, int total)
{
    printf("\nPID\tArrival\tBurst\tCompletion\n");

    for (int i = 0; i < total; i++)
    {
        printf("%d\t%d\t%d\t%d\n",
               plist[i].pid,
               plist[i].arrival_time,
               plist[i].burst_time,
               plist[i].completion_time);
    }
}

int main()
{
    int total;
    process *plist = get_input(&total);

    qsort(plist, total, sizeof(process), compare_processes);

    run_fcfs(plist, total);

    print_results(plist, total);

    free(plist);
    return 0;
}