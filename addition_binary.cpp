
#include<iostream>
using namespace std;

struct Node
{
    int bit;
    Node *prev;
    Node *next;
};

class Binary
{
    Node *head, *tail;

public:

    Binary()
    {
        head = tail = NULL;
    }

    void create()
    {
        int n, bit;

        cout << "Enter number of bits: ";
        cin >> n;

        for(int i = 0; i < n; i++)
        {
            cout << "Enter bit: ";
            cin >> bit;

            Node *nn = new Node;
            nn->bit = bit;
            nn->next = NULL;
            nn->prev = tail;

            if(head == NULL)
                head = nn;
            else
                tail->next = nn;

            tail = nn;
        }
    }

    void display()
    {
        Node *temp = head;

        while(temp != NULL)
        {
            cout << temp->bit;
            temp = temp->next;
        }
    }

    void addition(Binary b)
    {
        Node *p = tail;
        Node *q = b.tail;

        int carry = 0, sum;
        int result[100], k = 0;

        while(p != NULL || q != NULL || carry != 0)
        {
            sum = carry;

            if(p != NULL)
            {
                sum = sum + p->bit;
                p = p->prev;
            }

            if(q != NULL)
            {
                sum = sum + q->bit;
                q = q->prev;
            }

            result[k] = sum % 2;
            carry = sum / 2;
            k++;
        }

        cout << "\nAddition: ";

        for(int i = k-1; i >= 0; i--)
        {
            cout << result[i];
        }
    }
};

int main()
{
    Binary b1, b2;

    cout << "Enter first binary number:\n";
    b1.create();

    cout << "\nEnter second binary number:\n";
    b2.create();

    cout << "\nFirst number: ";
    b1.display();

    cout << "\nSecond number: ";
    b2.display();

    b1.addition(b2);

    return 0;
}

