
#include <iostream>
using namespace std;

// Linear Search
int linearSearch(int a[], int n, int key, int &c)
{
    c = 0;

    for(int i = 0; i < n; i++)
    {
        c++;

        if(a[i] == key)
            return i;
    }

    return -1;
}

// Sort array for Binary Search
void sortArray(int a[], int n)
{
    for(int i = 0; i < n-1; i++)
    {
        for(int j = 0; j < n-i-1; j++)
        {
            if(a[j] > a[j+1])
            {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

// Binary Search
int binarySearch(int a[], int n, int key, int &c)
{
    int low = 0, high = n-1;
    c = 0;

    while(low <= high)
    {
        int mid = (low + high) / 2;
        c++;

        if(a[mid] == key)
            return mid;

        else if(key > a[mid])
            low = mid + 1;

        else
            high = mid - 1;
    }

    return -1;
}

int main()
{
    int a[100], n, key, choice, result, c;

    cout << "Enter number of students: ";
    cin >> n;

    cout << "Enter roll numbers: ";
    for(int i = 0; i < n; i++)
        cin >> a[i];

    do
    {
        cout << "\n1. Linear Search";
        cout << "\n2. Binary Search";
        cout << "\n3. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        if(choice == 1)
        {
            cout << "Enter roll number to search: ";
            cin >> key;

            result = linearSearch(a, n, key, c);
        }

        else if(choice == 2)
        {
            sortArray(a, n);

            cout << "Enter roll number to search: ";
            cin >> key;

            result = binarySearch(a, n, key, c);
        }

        else if(choice == 3)
        {
            cout << "Program ended.";
            continue;
        }

        else
        {
            cout << "Invalid choice!";
            continue;
        }

        if(result == -1)
            cout << "\nStudent did not attend the session.";

        else
            cout << "\nStudent attended the session.";

        cout << "\nTotal comparisons: " << c << endl;

    } while(choice != 3);

    return 0;
}

