#include <stdio.h>
#include <stdlib.h>

typedef struct process
{
    int pid;
    int arrival_time;
    int burst_time;
    int completion_time;
    int completed;
} process;

int compare_by_arrival(const void *a, const void *b)
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

        plist[i].completed = 0;
    }

    return plist;
}

// Returns the index of the shortest-burst process that has arrived
// and hasn't run yet. Returns -1 if none are available right now.
int find_shortest_available(process *plist, int total, int clock)
{
    int best_index = -1;

    for (int i = 0; i < total; i++)
    {
        if (plist[i].completed == 1)
            continue;

        if (plist[i].arrival_time > clock)
            continue;

        if (best_index == -1)
        {
            best_index = i;
            continue;
        }

        if (plist[i].burst_time < plist[best_index].burst_time)
        {
            best_index = i;
        }
        else if (plist[i].burst_time == plist[best_index].burst_time &&
                 plist[i].pid < plist[best_index].pid)
        {
            best_index = i;
        }
    }

    return best_index;
}

// Returns the smallest arrival_time among processes that haven't run yet.
// Used to jump the clock forward when nobody is currently available.
int find_next_arrival(process *plist, int total)
{
    int next_arrival = -1;

    for (int i = 0; i < total; i++)
    {
        if (plist[i].completed == 1)
            continue;

        if (next_arrival == -1 || plist[i].arrival_time < next_arrival)
        {
            next_arrival = plist[i].arrival_time;
        }
    }

    return next_arrival;
}

void run_sjf(process *plist, int total)
{
    int clock = 0;
    int completed_count = 0;

    while (completed_count < total)
    {
        int idx = find_shortest_available(plist, total, clock);

        if (idx == -1)
        {
            clock = find_next_arrival(plist, total);
            continue;
        }

        clock += plist[idx].burst_time;
        plist[idx].completion_time = clock;
        plist[idx].completed = 1;
        completed_count++;
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

    qsort(plist, total, sizeof(process), compare_by_arrival);

    run_sjf(plist, total);

    print_results(plist, total);

    free(plist);
    return 0;
}