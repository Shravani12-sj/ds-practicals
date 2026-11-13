
#include<iostream>
using namespace std;

// Bubble Sort
void bubbleSort(float a[], int n, int &c)
{
    c = 0;

    for(int i = 0; i < n-1; i++)
    {
        for(int j = 0; j < n-i-1; j++)
        {
            c++;

            if(a[j] > a[j+1])
            {
                float temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
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
    float a[50];
  int n, c1;
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
}

    // Bubble Sort
    bubbleSort(a, n, c1);

    cout << "\nBubble Sort: ";

    for(int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    cout << "\nBubble Sort comparisons: " << c1;

    displayTopFive(a, n);


    return 0;
}

