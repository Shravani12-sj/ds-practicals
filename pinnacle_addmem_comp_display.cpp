
#include<iostream>
using namespace std;

struct Node
{
    int PRN;
    string name;
    Node *next;
};

class Pinnacle
{
    Node *head;

public:

    Pinnacle()
    {
        head = NULL;
    }

    void addMember()
    {
        Node *nn = new Node;

        cout << "Enter PRN: ";
        cin >> nn->PRN;

        cout << "Enter Name: ";
        cin >> nn->name;

        nn->next = NULL;

        if(head == NULL)
        {
            head = nn;
        }
        else
        {
            Node *temp = head;

            while(temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = nn;
        }
    }

    void countMembers()
    {
        int count = 0;
        Node *temp = head;

        while(temp != NULL)
        {
            count++;
            temp = temp->next;
        }

        cout << "\nTotal members: " << count;
    }

    void display()
    {
        Node *temp = head;

        cout << "\nClub Members:\n";

        while(temp != NULL)
        {
            cout << "PRN: " << temp->PRN
                 << "  Name: " << temp->name << endl;

            temp = temp->next;
        }
    }
};

int main()
{
    Pinnacle p;
    int n;

    cout << "Enter number of members: ";
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cout << "\nEnter details of member " << i+1 << endl;
        p.addMember();
    }

    p.countMembers();
    p.display();

    return 0;
}

