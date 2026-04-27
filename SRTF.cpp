#include<iostream.h>
#include<conio.h>

void main()
{
    clrscr();

    int n, i;
    int at[10], bt[10], rt[10];
    int ct[10], tat[10], wt[10];

    int time = 0, completed = 0;
    int min, idx;

    cout<<"Enter number of processes: ";
    cin>>n;

    cout<<"\nEnter Arrival Time and Burst Time:\n";
    for(i=0; i<n; i++)
    {
        cout<<"Process "<<i+1<<": ";
        cin>>at[i]>>bt[i];
        rt[i] = bt[i];   // remaining time
    }

    while(completed < n)
    {
        min = 9999;
        idx = -1;

        // Find process with smallest remaining time
        for(i=0; i<n; i++)
        {
            if(at[i] <= time && rt[i] > 0)
            {
                if(rt[i] < min)
                {
                    min = rt[i];
                    idx = i;
                }
            }
        }

        if(idx != -1)
        {
            rt[idx]--;   // execute for 1 unit
            time++;

            if(rt[idx] == 0)
            {
                ct[idx] = time;
                completed++;
            }
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

    cout<<"\nP\tAT\tBT\tCT\tTAT\tWT\n";
    for(i=0; i<n; i++)
    {
        cout<<"P"<<i+1<<"\t"<<at[i]<<"\t"<<bt[i]
            <<"\t"<<ct[i]<<"\t"<<tat[i]<<"\t"<<wt[i]<<endl;
    }

    getch();
}


