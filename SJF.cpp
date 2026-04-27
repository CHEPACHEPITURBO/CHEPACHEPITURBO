#include<iostream.h>
#include<conio.h>

void main()
{
    clrscr();

    int n, i, j;
    int at[10], bt[10], ct[10], tat[10], wt[10];
    int done[10];
    int time = 0, min, idx;

    cout<<"Enter number of processes: ";
    cin>>n;

    cout<<"\nEnter Arrival Time and Burst Time:\n";
    for(i=0; i<n; i++)
    {
        cout<<"Process "<<i+1<<": ";
        cin>>at[i]>>bt[i];
        done[i] = 0;
    }

    int completed = 0;

    while(completed < n)
    {
        min = 9999;
        idx = -1;

        // Find shortest job among arrived processes
        for(i=0; i<n; i++)
        {
            if(at[i] <= time && done[i] == 0)
            {
                if(bt[i] < min)
                {
                    min = bt[i];
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
            time++; // idle CPU
        }
    }

    // Calculate TAT and WT
    for(i=0; i<n; i++)
    {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }

    cout<<"\nP\tAT\tBT\tCT\tTAT\tWT\n";
    for(i=0; i<n; i++)
    {
        cout<<"P"<<i+1<<"\t"<<at[i]<<"\t"<<bt[i]
            <<"\t"<<ct[i]<<"\t"<<tat[i]<<"\t"<<wt[i]<<endl;
    }

    getch();
}
