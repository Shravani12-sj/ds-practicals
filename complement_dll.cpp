
#include <iostream>
using namespace std;

struct Node
{
    int bit;
    Node *prev;
    Node *next;
};

class Binary
{
public:
    Node *msb, *lsb;

    Binary()
    {
        msb = lsb = NULL;
    }

    void storebin();
    void display();
    void ones();
    void twos();
};

void Binary::storebin()
{
    int n;
    cout << "Enter total number of bits: ";
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        Node *nn = new Node;

        cout << "Enter bit: ";
        cin >> nn->bit;

        nn->prev = NULL;
        nn->next = NULL;

        if(msb == NULL)
        {
            msb = lsb = nn;
        }
        else
        {
            lsb->next = nn;
            nn->prev = lsb;
            lsb = nn;
        }
    }
}

void Binary::display()
{
    Node *temp = msb;

    while(temp != NULL)
    {
        cout << temp->bit;
        temp = temp->next;
    }
}

void Binary::ones()
{
    Node *temp = msb;

    while(temp != NULL)
    {
        if(temp->bit == 1)
            cout << "0";
        else
            cout << "1";

        temp = temp->next;
    }
}

void Binary::twos()
{
    Node *temp = lsb;
    int flag = 0;

    while(temp != NULL)
    {
        if(flag == 0)
        {
            if(temp->bit == 1)
                flag = 1;
        }
        else
        {
            if(temp->bit == 1)
                temp->bit = 0;
            else
                temp->bit = 1;
        }

        temp = temp->prev;
    }
}

int main()
{
    Binary b;

    cout << "Enter binary number:\n";
    b.storebin();

    cout << "\nBinary number: ";
    b.display();

    cout << "\n1's complement: ";
    b.ones();

    b.twos();

    cout << "\n2's complement: ";
    b.display();

    return 0;
}

