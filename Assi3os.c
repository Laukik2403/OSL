#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef struct{
    int pid;
    int arrival;
    int burst;
    int remaining;
    int completion;
    int waiting;
    int turnaround;
}process;

void sjfpeemptive(process proc[],int n);
void roundrobin(process proc[],int n,int quantum);

int main()
{
    int i,n,quantum;
    printf("enter the  number of process :");
    scanf("%d",&n);
    process proc[n];
    for(int i=0;i<n;i++)
    {
        proc[i].pid=i+1;
        printf("enter the arrival time and burst time :"i+1);
        scanf("%d%d",proc[i].arrival,proc[i].burst);
        proc[i].remaining=proc[i].burst;
    }
    printf("enter the time quantum for roundrobin :");
    scanf("%d",quantum);
    printf("...SJF PREEMPTIVE...");
    sjfpeemptive(proc,n);
    for(int i=0;i<n;i++)
    {
        proc[i].remaining=proc[i].burst;
    }
    printf("...ROUND ROBIN...");
    roundrobin(proc,n,quantum);
    return 0;
}

void sjfpreemptive(process proc[],int n)
{
    int completed=0,time=0,min=INT_MAX,finish_time,shortest=0;
    int check=0;
    while(completed != n)
    {
        for(int i=0;i<n;i++)
        {
            if(proc[i].arrival<=time && proc[i].remaining>0 && proc[i].remaining<min)
            {
                min=proc[i].remaining;
                check=1;
                shortest=i;
            }
        }
        if(check==0)
            {
                time++;
                continue;
            }
            proc[shortest].remaining--;
            min=proc[shortest].remaining;
            if(min==0)
            {
                min=INT_MAX;
            }

            if(proc[shortest].remaining==0)
            {
                completed++;
                finish_time=time+1;
                check=0;
                proc[shortest].completion=finish_time;
                proc[shortest].turnaround=finish_time-proc[shortest].arrival;
                proc[shortest].waiting=proc[shortest].turnaround-proc[shortest].burst;
            }
            time ++;
    }

    printf("\tpid\tarrival time\tburst time\tcompletion time\tturnaround time\twaiting time");
    for(int i=0;i<n;i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",proc[i].pid,proc[i].arrival,proc[i].burst,proc[i].completion,proc[i].turnaround,proc[i].waiting);
    }
}

void roundrobin(process proc[],int n,int quantum)
{
    int time=0,completed=0;int waiting[n];int turnaround[n];int remaining[n];

    for(int i=0;i<n;i++)
    {
        remaining[i]=proc[i].burst;
    }
    while(completed != n)
    {
        int done=1;
        for(int i=0;i<n;i++)
        {
            if(remaining[i]>0 && proc[i].arrival<time)
            {
                done=0;
                if(remaining[i]>quantum)
                {
                    time += quantum;
                    remaining -=quantum;
                }
                else
                {
                    time += remaining[i];
                    waiting[i]=time-proc[i].arrival-proc[i].burst;
                    remaining[i]=0;
                    completed++;
                    proc[i].completion=time;
                    turnaround[i]=proc[i].completion-proc[i].arrival;
                    proc[i].waiting=waiting[i];
                    proc[i].turnaround=turnaround[i];
                }
            }
        }
        if(done==1)
            time++;
    }
    printf("\tpid\tarrival time\tburst time\tcompletion time\tturnaround time\twaiting time");
    for(int i=0;i<n;i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",proc[i].pid,proc[i].arrival,proc[i].burst,proc[i].completion,proc[i].turnaround,proc[i].waiting);
    }
}


