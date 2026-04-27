#include<iostream.h>
#include<conio.h>

void main()
{
    clrscr();

    int n, i, j;
    int at[10], bt[10], pr[10];
    int ct[10], tat[10], wt[10];
    int done[10];

    int time = 0, completed = 0;
    int min, idx;

    cout<<"Enter number of processes: ";
    cin>>n;

    cout<<"\nEnter Arrival Time, Burst Time and Priority:\n";
    for(i=0; i<n; i++)
    {
        cout<<"Process "<<i+1<<": ";
        cin>>at[i]>>bt[i]>>pr[i];
        done[i] = 0;
    }

    while(completed < n)
    {
        min = 9999;
        idx = -1;

        // Find highest priority process (smallest number)
        for(i=0; i<n; i++)
        {
            if(at[i] <= time && done[i] == 0)
            {
                if(pr[i] < min)
                {
                    min = pr[i];
                    idx = i;
                }
            }
        }

        if(idx != -1)
        {
            time = time + bt[idx];
            ct[idx] = time;
            done[idx] = 1;
            completed++;
        }
        else
        {
            time++; // CPU idle
        }
    }

    // Calculate TAT and WT
    for(i=0; i<n; i++)
    {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }

    cout<<"\nP\tAT\tBT\tPR\tCT\tTAT\tWT\n";
    for(i=0; i<n; i++)
    {
        cout<<"P"<<i+1<<"\t"<<at[i]<<"\t"<<bt[i]
            <<"\t"<<pr[i]<<"\t"<<ct[i]
            <<"\t"<<tat[i]<<"\t"<<wt[i]<<endl;
    }

    getch();
}

