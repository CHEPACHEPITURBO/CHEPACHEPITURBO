#include<iostream.h>
#include<conio.h>

void main()
{
    clrscr();

    int n, i;
    int at[10], bt[10], rt[10];
    int ct[10], tat[10], wt[10];

    int tq, time = 0, completed = 0;
    int flag;

    cout<<"Enter number of processes: ";
    cin>>n;

    cout<<"Enter Time Quantum: ";
    cin>>tq;

    cout<<"\nEnter Arrival Time and Burst Time:\n";
    for(i=0; i<n; i++)
    {
        cout<<"Process "<<i+1<<": ";
        cin>>at[i]>>bt[i];
        rt[i] = bt[i];   // remaining time
    }

    while(completed < n)
    {
        flag = 0;

        for(i=0; i<n; i++)
        {
            if(at[i] <= time && rt[i] > 0)
            {
                flag = 1;

                if(rt[i] > tq)
                {
                    time = time + tq;
                    rt[i] = rt[i] - tq;
                }
                else
                {
                    time = time + rt[i];
                    rt[i] = 0;
                    ct[i] = time;
                    completed++;
                }
            }
        }

        if(flag == 0)
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



