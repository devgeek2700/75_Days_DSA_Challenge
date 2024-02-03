#include <bits/stdc++.h>
using namespace std;

// Sorting - Part 2
// Merge Sort
// Quick Sort
// Bubble Sort using  Recursion
// Insertion Sort using  Recursion

void mergeSort(int arr[], int low, int mid, int high)
{
    int left = low;
    int right = mid + 1;
    int temp[high - low + 1];
    int indextemp = 0;

    // merge from both arrays
    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp[indextemp] = arr[left];
            left++;
        }
        else
        {
            temp[indextemp] = arr[right];
            right++;
        }
        indextemp++;
    }

    // merge all values remaining from left array
    while (left <= mid)
    {
        temp[indextemp] = arr[left];
        left++;
        indextemp++;
    }

    // merge all values remaining from right array
    while (right <= high)
    {
        temp[indextemp] = arr[right];
        right++;
        indextemp++;
    }

    // Copy the merged elements back to the original array
    for (int i = low, j = 0; i <= high; i++, j++)
    {
        arr[i] = temp[j];
    }
}

void printMergeSort(int arr[], int low, int high) // TC --> O(log2(n))   SC --> O(n)  uses extra space
{
    if (low >= high)
    {
        return;
    }

    int mid = (low + high) / 2;
    printMergeSort(arr, low, mid);
    printMergeSort(arr, mid + 1, high);
    mergeSort(arr, low, mid, high);
}

int quickSort(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low;  // to find greatest than pivot
    int j = high; // to find lowest than pivot

    while (i < j)
    {
        while (arr[i] <= pivot && i <= j)
        {
            i++;
        }
        while (arr[j] > pivot && j >= i)
        {
            j--;
        }

        if (i <= j)
        {
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[low], arr[j]);
    return j;
}

void printQuickSort(int arr[], int low, int high) // TC --> O(log2(n))   SC --> O(1) no extra space used
{
    // smaller elements in left
    // higher elements in right

    if (low < high)
    {
        int partition = quickSort(arr, low, high);
        printQuickSort(arr, low, partition - 1);
        printQuickSort(arr, partition + 1, high);
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

    printMergeSort(arr, 0, n); // Divide and merge the arrays

    cout << "\nMerge Sorted Array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    printQuickSort(arr, 0, n); // Divide and merge the arrays

    cout << "\nQuick Sorted Array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}