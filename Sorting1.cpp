#include <bits/stdc++.h>
using namespace std;

// Sorting - Part 1
// Selection Sort
// Bubble Sort
// Insertion Sort

// Selection Sort
void printSelectionSort(int n, int arr[]) // TC --> O(n^2)
{
    // outer loop for 0 to n-1  --> { >40, 12, -1, -5, 0 ,6, 33,> -10}
    for (int i = 0; i < n - 1; i++)
    {
        int minval = i;
        // inner loop for i =0 to n   --> { 40, > 12, -1, -5, 0 ,6, 33, -10>}
        for (int j = i; j < n; j++)
        {
            if (arr[j] < arr[minval])
            {
                minval = j;
            }
        }
        swap(arr[i], arr[minval]);
    }
}

// Bubble Sort MTD-1
void printBubbleSort(int n, int arr[]) // TC --> O(n^2)
{
    // outer loop for 0 to n  --> { >40, 12, -1, -5, 0 ,6, 33, -10>}
    for (int i = 0; i < n - 1; i++)
    {
        int didswap = 0;
        // inner loop for 0 to n-i-1   --> {>40, > 12, -1, -5, 0 ,6, 33, -10>}
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]); //   --> {>40, > 12, -1, -5, 0 ,6, 33, -10}
                didswap = 1;
            }
        }
    }
}

// Bubble Sort MTD-2   --> TC --> worst & avg case: O(n^2) and best case: O(n)
// void printBubbleSort(int n, int arr[]) // TC --> O(n^2)
// {
//     // outer loop for 0 to n  --> { >40, 12, -1, -5, 0 ,6, 33, -10>}
//     for (int i = n-1; i >=0; i--)
//     {
//         int didswap = 0;
//         // inner loop for 0 to n-i-1   --> {>40, > 12, -1, -5, 0 ,6, 33, -10>}
//         for (int j = 0; j <= i - 1; j++)
//         {
//             if (arr[j] > arr[j + 1])
//             {
//                 swap(arr[j], arr[j + 1]); //   --> {>40, > 12, -1, -5, 0 ,6, 33, -10}
//                 didswap = 1;
//             }
//         }
//         if (didswap == 0)
//         {
//             break;
//         }
//         cout<<"run is: "<<i<<endl;
//     }
// }

// Insertion Sort
void printInsertionSort(int n, int arr[]) // TC --> O(n^2)
{
    // outer loop for 0 to n  --> { >40, 12, -1, -5, 0 ,6, 33, -10>}
    for (int i = 0; i < n; i++)
    {
        // inner loop for 0 to 0>0   --> {>40, > 12, -1, -5, 0 ,6, 33, -10>}
        for (int j = i; j > 0; j--)
        {
            if (arr[j] < arr[j - 1])
            {
                swap(arr[j], arr[j - 1]);
            }
        }
    }
}




int main()
{
    int n;
    cout << "n: ";
    cin >> n;

    int arr[n];
    cout << "Array Values: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Display Array Values: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
        cout << endl;

    printSelectionSort(n, arr); // takes minimum to the front of arr

    cout << "\nSelection Sorted Array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    printBubbleSort(n, arr); // takes maximum to the back of arr

    cout << "\nBubble Sorted Array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    printInsertionSort(n, arr); // takes an element and places it in its correct place

    cout << "\nInsertion Sorted Array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}