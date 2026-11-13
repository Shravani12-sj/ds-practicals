
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

// Insert using Quadratic Probing
void insertRecord(string name, long long phone)
{
    int index = hashFunction(name);
    int i = 0;

    while(i < SIZE && occupied[(index + i*i) % SIZE])
    {
        i++;
    }

    if(i == SIZE)
    {
        cout << "Hash Table is Full";
        return;
    }

    int pos = (index + i*i) % SIZE;

    table[pos].name = name;
    table[pos].phone = phone;
    occupied[pos] = true;

    cout << "Record inserted";
}

// Search record
void searchRecord(string name)
{
    int index = hashFunction(name);
    int i = 0;

    while(i < SIZE)
    {
        int pos = (index + i*i) % SIZE;

        if(occupied[pos] == false)
            break;

        if(table[pos].name == name)
        {
            cout << "Phone Number: " << table[pos].phone;
            return;
        }

        i++;
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

