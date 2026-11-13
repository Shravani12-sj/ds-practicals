
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

        if(head == NULL)
        {
            cout << "List is empty";
            return;
        }

        while(temp != NULL)
        {
            cout << "PRN: " << temp->PRN
                 << "  Name: " << temp->name << endl;

            temp = temp->next;
        }
    }

    void concatenate(Pinnacle &p2)
    {
        if(head == NULL)
        {
            head = p2.head;
            return;
        }

        Node *temp = head;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = p2.head;
    }
};

int main()
{
    Pinnacle divA, divB;

    int n;

    cout << "Enter number of members in Division A: ";
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cout << "\nEnter Division A member details:\n";
        divA.addMember();
    }

    cout << "\nEnter number of members in Division B: ";
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cout << "\nEnter Division B member details:\n";
        divB.addMember();
    }

    cout << "\nDivision A Members:\n";
    divA.display();

    cout << "\nDivision B Members:\n";
    divB.display();

    divA.concatenate(divB);

    cout << "\nConcatenated List:\n";
    divA.display();

    cout << "\nTotal members after concatenation:";
    divA.countMembers();

    return 0;
}

