#include </home/dinesh-p/C_Practice/src/problems/CPU_task_scheduler/header.h>

int main()
{
    process *input;
    int total_process=0;
    int *p=&total_process;
    input = get_input(p);
    int completed_process=0;
    int clock=0;
    int *clk=&clock;
    while(1){
        if(completed_process == total_process)
        {
            break;
        }
        int capable_process;
        int *avalible_process;
        avalible_process=check_arrival_time(input, &capable_process ,p, clk);
        completed_process=run_process(input, avalible_process, clk, &completed_process, &capable_process);
    }

}
