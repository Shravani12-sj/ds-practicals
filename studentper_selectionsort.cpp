
#include<iostream>
using namespace std;



// Selection Sort
void selectionSort(float a[], int n, int &c)
{
    c = 0;

    for(int i = 0; i < n-1; i++)
    {
        int min = i;

        for(int j = i+1; j < n; j++)
        {
            c++;

            if(a[j] < a[min])
            {
                min = j;
            }
        }

        float temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
}

// Display top five percentages
void displayTopFive(float a[], int n)
{
    cout << "\nTop five percentages: ";

    int count = 0;

    for(int i = n-1; i >= 0 && count < 5; i--)
    {
        cout << a[i] << " ";
        count++;
    }
}

int main()
{
    float a[50], b[50];
    int n, c1, c2;

    cout << "Enter number of students: ";
    cin >> n;

    if(n < 1 || n > 50)
    {
        cout << "Invalid number of students";
        return 0;
    }

    cout << "Enter student percentages: ";

    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        b[i] = a[i];
    }

   
    // Selection Sort
    selectionSort(b, n, c2);

    cout << "\n\nSelection Sort: ";

    for(int i = 0; i < n; i++)
    {
        cout << b[i] << " ";
    }

    cout << "\nSelection Sort comparisons: " << c2;

    displayTopFive(b, n);

    return 0;
}

