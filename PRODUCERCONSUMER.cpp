#include<iostream.h>
#include<conio.h>

int mutex = 1;
int full = 0;
int empty = 5;   // buffer size = 5
int x = 0;       // item count

void wait(int &s)
{
    while(s <= 0);
    s--;
}

void signal(int &s)
{
    s++;
}

void producer()
{
    wait(empty);
    wait(mutex);

    x++;
    cout<<"\nProducer produces item "<<x;

    signal(mutex);
    signal(full);
}

void consumer()
{
    wait(full);
    wait(mutex);

    cout<<"\nConsumer consumes item "<<x;
    x--;

    signal(mutex);
    signal(empty);
}

void main()
{
    clrscr();

    int choice;

    do
    {
        cout<<"\n\n1. Produce";
        cout<<"\n2. Consume";
        cout<<"\n3. Exit";
        cout<<"\nEnter your choice: ";
        cin>>choice;

        switch(choice)
        {
            case 1:
                if(mutex==1 && empty!=0)
                    producer();
                else
                    cout<<"\nBuffer is full!";
                break;

            case 2:
                if(mutex==1 && full!=0)
                    consumer();
                else
                    cout<<"\nBuffer is empty!";
                break;
        }

    } while(choice != 3);

    getch();
}


