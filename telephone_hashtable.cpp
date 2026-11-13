#include<iostream>
using namespace std;

#define SIZE 10

struct Record
{
    string name;
    long long phone;
};

Record table[SIZE];
bool occupied[SIZE] = {false};

// Hash function
int hashFunction(string name)
{
    int sum = 0;

    for(int i = 0; i < name.length(); i++)
        sum = sum + name[i];

    return sum % SIZE;
}

// Insert record using Linear Probing
void insertRecord(string name, long long phone)
{
    int index = hashFunction(name);
    int start = index;

    while(occupied[index])
    {
        index = (index + 1) % SIZE;

        if(index == start)
        {
            cout << "Hash Table is Full";
            return;
        }
    }

    table[index].name = name;
    table[index].phone = phone;
    occupied[index] = true;

    cout << "Record inserted";
}

// Search record
void searchRecord(string name)
{
    int index = hashFunction(name);
    int start = index;

    while(occupied[index])
    {
        if(table[index].name == name)
        {
            cout << "Phone Number: " << table[index].phone;
            return;
        }

        index = (index + 1) % SIZE;

        if(index == start)
            break;
    }

    cout << "Record not found";
}

// Display records
void display()
{
    for(int i = 0; i < SIZE; i++)
    {
        if(occupied[i])
        {
            cout << "\nIndex " << i;
            cout << " Name: " << table[i].name;
            cout << " Phone: " << table[i].phone;
        }
    }
}

int main()
{
    int choice;
    string name;
    long long phone;

    do
    {
        cout << "\n\n1. Insert Record";
        cout << "\n2. Search Record";
        cout << "\n3. Display Records";
        cout << "\n4. Exit";

        cout << "\nEnter choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                cout << "Enter Name: ";
                cin >> name;

                cout << "Enter Phone Number: ";
                cin >> phone;

                insertRecord(name, phone);
                break;

            case 2:
                cout << "Enter Name to Search: ";
                cin >> name;

                searchRecord(name);
                break;

            case 3:
                display();
                break;

            case 4:
                cout << "Exiting...";
                break;

            default:
                cout << "Invalid choice";
        }

    } while(choice != 4);

    return 0;
}
