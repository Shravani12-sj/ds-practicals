
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

    void deleteMember()
    {
        if(head == NULL)
        {
            cout << "Club is empty";
            return;
        }

        int key;

        cout << "Enter PRN to delete: ";
        cin >> key;

        Node *temp = head;
        Node *prev = NULL;

        if(head->PRN == key)
        {
            head = head->next;
            delete temp;
            cout << "Member deleted";
            return;
        }

        while(temp != NULL && temp->PRN != key)
        {
            prev = temp;
            temp = temp->next;
        }

        if(temp == NULL)
        {
            cout << "Member not found";
        }
        else
        {
            prev->next = temp->next;
            delete temp;
            cout << "Member deleted";
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
            cout << "Club is empty";
            return;
        }

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
    int n, choice;

    cout << "Enter number of members: ";
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cout << "\nEnter details of member " << i+1 << endl;
        p.addMember();
    }

    do
    {
        cout << "\n\n1. Delete Member";
        cout << "\n2. Count Members";
        cout << "\n3. Display Members";
        cout << "\n4. Exit";

        cout << "\nEnter choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                p.deleteMember();
                break;

            case 2:
                p.countMembers();
                break;

            case 3:
                p.display();
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

