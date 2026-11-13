
#include<iostream>
using namespace std;

class Queue
{
    int q[50];
    int front, rear;

public:

    Queue()
    {
        front = -1;
        rear = -1;
    }

    void addJob()
    {
        int job;

        if(rear == 49)
        {
            cout << "Queue is full";
            return;
        }

        cout << "Enter job: ";
        cin >> job;

        if(front == -1)
        {
            front = 0;
        }

        rear++;
        q[rear] = job;
    }

    void deleteJob()
    {
        if(front == -1 || front > rear)
        {
            cout << "Queue is empty";
            return;
        }

        cout << "Deleted job: " << q[front];

        front++;
    }

    void display()
    {
        if(front == -1 || front > rear)
        {
            cout << "Queue is empty";
            return;
        }

        cout << "\nJobs in queue: ";

        for(int i = front; i <= rear; i++)
        {
            cout << q[i] << " ";
        }
    }
};

int main()
{
    Queue q;
    int choice;

    do
    {
        cout << "\n\n1. Add Job";
        cout << "\n2. Delete Job";
        cout << "\n3. Display Queue";
        cout << "\n4. Exit";

        cout << "\nEnter choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                q.addJob();
                break;

            case 2:
                q.deleteJob();
                break;

            case 3:
                q.display();
                break;

            case 4:
                cout << "Exiting";
                break;

            default:
                cout << "Invalid choice";
        }

    }while(choice != 4);

    return 0;
}

