#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

class HashTable
{
    Node *table[10];

public:

    HashTable()
    {
        for(int i = 0; i < 10; i++)
        {
            table[i] = NULL;
        }
    }

    int hashFunction(int key)
    {
        return key % 10;
    }

    void insert(int key)
    {
        int index = hashFunction(key);

        Node *nn = new Node;
        nn->data = key;
        nn->next = NULL;

        if(table[index] == NULL)
        {
            table[index] = nn;
        }
        else
        {
            Node *temp = table[index];

            while(temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = nn;
        }
    }

    void display()
    {
        for(int i = 0; i < 10; i++)
        {
            cout << i << " -> ";

            Node *temp = table[i];

            while(temp != NULL)
            {
                cout << temp->data << " -> ";
                temp = temp->next;
            }

            cout << "NULL" << endl;
        }
    }
};

int main()
{
    HashTable h;
    int n, key;

    cout << "Enter number of elements: ";
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cout << "Enter element: ";
        cin >> key;

        h.insert(key);
    }

    cout << "\nHash Table:\n";
    h.display();

    return 0;
}
