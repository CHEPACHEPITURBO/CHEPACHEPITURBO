#include<iostream.h>
#include<conio.h>

void main()
{
    clrscr();

    int n, m, i, j, k;

    int alloc[10][10], max[10][10], need[10][10];
    int avail[10], finish[10], safeSeq[10];

    cout<<"Enter number of processes: ";
    cin>>n;

    cout<<"Enter number of resources: ";
    cin>>m;

    cout<<"\nEnter Allocation Matrix:\n";
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            cin>>alloc[i][j];
        }
    }

    cout<<"\nEnter Maximum Matrix:\n";
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            cin>>max[i][j];
        }
    }

    cout<<"\nEnter Available Resources:\n";
    for(i=0; i<m; i++)
    {
        cin>>avail[i];
    }

    // Calculate Need = Max - Allocation
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    // Initialize finish array
    for(i=0; i<n; i++)
    {
        finish[i] = 0;
    }

    int count = 0;

    // Find safe sequence
    while(count < n)
    {
        int found = 0;

        for(i=0; i<n; i++)
        {
            if(finish[i] == 0)
            {
                for(j=0; j<m; j++)
                {
                    if(need[i][j] > avail[j])
                        break;
                }

                if(j == m)
                {
                    for(k=0; k<m; k++)
                    {
                        avail[k] += alloc[i][k];
                    }

                    safeSeq[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }

        if(found == 0)
        {
            cout<<"\nSystem is NOT in safe state!";
            getch();
            return;
        }
    }

    cout<<"\nSystem is in SAFE state.\nSafe Sequence:\n";
    for(i=0; i<n; i++)
    {
        cout<<"P"<<safeSeq[i];
        if(i != n-1)
            cout<<" -> ";
    }

    getch();
}

