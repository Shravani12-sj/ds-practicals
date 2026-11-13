#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

class BST
{
    Node *root;

public:

    BST()
    {
        root = NULL;
    }

    Node* insert(Node *temp, int value)
    {
        if(temp == NULL)
        {
            Node *nn = new Node;
            nn->data = value;
            nn->left = NULL;
            nn->right = NULL;
            return nn;
        }

        if(value < temp->data)
            temp->left = insert(temp->left, value);
        else
            temp->right = insert(temp->right, value);

        return temp;
    }

    void create()
    {
        int n, value;

        cout << "Enter number of nodes: ";
        cin >> n;

        for(int i = 0; i < n; i++)
        {
            cout << "Enter value: ";
            cin >> value;
            root = insert(root, value);
        }
    }

    void search(int key)
    {
        Node *temp = root;

        while(temp != NULL)
        {
            if(temp->data == key)
            {
                cout << "Element found";
                return;
            }
            else if(key < temp->data)
            {
                temp = temp->left;
            }
            else
            {
                temp = temp->right;
            }
        }

        cout << "Element not found";
    }

    void minimum()
    {
        if(root == NULL)
        {
            cout << "Tree is empty";
            return;
        }

        Node *temp = root;

        while(temp->left != NULL)
        {
            temp = temp->left;
        }

        cout << "\nMinimum value: " << temp->data;
    }
};

int main()
{
    BST b;
    int key;

    b.create();

    cout << "\nEnter value to search: ";
    cin >> key;

    b.search(key);
    b.minimum();

    return 0;
}
