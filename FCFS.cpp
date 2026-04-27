#include<iostream.h>
#include<conio.h>

void main()
{
    clrscr();

    int n, i, j;
    int bt[10], at[10], ct[10], tat[10], wt[10];
    int temp;

    cout<<"Enter number of processes: ";
    cin>>n;

    cout<<"\nEnter Arrival Time and Burst Time:\n";
    for(i=0; i<n; i++)
    {
        cout<<"Process "<<i+1<<": ";
        cin>>at[i]>>bt[i];
    }

    // Sorting according to arrival time
    for(i=0; i<n-1; i++)
    {
        for(j=0; j<n-i-1; j++)
        {
            if(at[j] > at[j+1])
            {
                temp = at[j];
                at[j] = at[j+1];
                at[j+1] = temp;

                temp = bt[j];
                bt[j] = bt[j+1];
                bt[j+1] = temp;
            }
        }
    }

    // Completion Time
    ct[0] = at[0] + bt[0];

    for(i=1; i<n; i++)
    {
        if(ct[i-1] < at[i])
            ct[i] = at[i] + bt[i];
        else
            ct[i] = ct[i-1] + bt[i];
    }

    // TAT and WT
    for(i=0; i<n; i++)
    {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }

    cout<<"\nP\tAT\tBT\tCT\tTAT\tWT\n";
    for(i=0; i<n; i++)
    {
        cout<<"P"<<i+1<<"\t"<<at[i]<<"\t"<<bt[i]
            <<"\t"<<ct[i<<"\t"<<tat[i]<<"\t"<<wt[i]<<endl;
    }

    getch();
}

