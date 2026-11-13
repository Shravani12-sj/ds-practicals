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

    void display(Node *temp)
    {
        if(temp != NULL)
        {
            display(temp->left);
            cout << temp->data << " ";
            display(temp->right);
        }
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

    void mirror(Node *temp)
    {
        if(temp == NULL)
            return;

        Node *t = temp->left;
        temp->left = temp->right;
        temp->right = t;

        mirror(temp->left);
        mirror(temp->right);
    }

    void show()
    {
        display(root);
    }

    void makeMirror()
    {
        mirror(root);
    }
};

int main()
{
    BST b;

    b.create();

    cout << "\nOriginal BST: ";
    b.show();

    b.minimum();

    b.makeMirror();

    cout << "\nMirrored BST: ";
    b.show();

    return 0;
}
