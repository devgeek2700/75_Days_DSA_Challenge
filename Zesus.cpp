#include <bits/stdc++.h>
using namespace std;

// Selection Sort

void selectionSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                swap(arr[i], arr[j]);
            }
        }
    }
}

// Bubble Sort

void BubbleSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Insertion Sort

void InsertionSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 1; i < n; i++)
    {
        {
            for (int j = i; j > 0; j--)
            {
                if (arr[j] < arr[j - 1])
                {
                    swap(arr[j], arr[j - 1]);
                }
            }
        }
    }
}

// Merge Sort

void merge(vector<int> &arr, int low, int mid, int high)
{
    int left = low;
    int right = mid + 1;
    vector<int> temp;

    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left++]);
        }
        else
        {
            temp.push_back(arr[right++]);
        }
    }

    while (left <= mid)
    {
        temp.push_back(arr[left++]);
    }

    while (right <= high)
    {
        temp.push_back(arr[right++]);
    }

    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
}

void mergesort(vector<int> &arr, int low, int high)
{
    if (low >= high)
    {
        return;
    }

    int mid = low + (high - low) / 2;
    mergesort(arr, low, mid);
    mergesort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}

// Quick Sort

int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[low];
    int start = low + 1;
    int end = high;
    while (start <= end)
    {
        while (start <= high && arr[start] <= pivot)
        {
            start++;
        }

        while (end >= low && arr[end] > pivot)
        {
            end--;
        }

        if (start < end)
        {
            swap(arr[start], arr[end]);
        }
    }

    // swap the pivot at start and end idx so that pivot is at its correct position
    swap(arr[low], arr[end]);
    return end;
}

void quicksort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pivotIdx = partition(arr, low, high);
        quicksort(arr, low, pivotIdx - 1);
        quicksort(arr, pivotIdx + 1, high);
    }
}

// Recursive Bubble Sort
void RecursiveBubbleSort(vector<int> &arr, int n)
{
    if (n <= 1)
    {
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            swap(arr[i], arr[i + 1]);
        }
    }
    RecursiveBubbleSort(arr, n - 1);
}

// Recursive Insertion Sort
void RecursiveInsertionSort(vector<int> &arr, int n)
{
    if (n <= 1)
    {
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            swap(arr[i], arr[i + 1]);
        }
    }
    RecursiveBubbleSort(arr, n - 1);
}

int main()
{
    vector<int> arr = {2, 1, 6, 10, 4, 1, 3, 9, 7};
    cout << "Before Sorting" << endl;
    for (auto it : arr)
    {
        cout << it << " ";
    }
    cout << endl;

    // selectionSort(arr);
    // cout << "After Sorting" << endl;
    // for (auto it : arr)
    // {
    //     cout << it << " ";
    // }

    // BubbleSort(arr);
    // cout << "After Sorting" << endl;
    // for (auto it : arr)
    // {
    //     cout << it << " ";
    // }

    // InsertionSort(arr);
    // cout << "After Sorting" << endl;
    // for (auto it : arr)
    // {
    //     cout << it << " ";
    // }

    // mergesort(arr, 0, arr.size() - 1);
    // cout << "After Sorting" << endl;
    // for (auto it : arr)
    // {
    //     cout << it << " ";
    // }

    // quicksort(arr, 0, arr.size() - 1);
    // cout << "After Sorting" << endl;
    // for (auto it : arr)
    // {
    //     cout << it << " ";
    // }

    // RecursiveBubbleSort(arr, arr.size());
    // cout << "After Sorting" << endl;
    // for (auto it : arr)
    // {
    //     cout << it << " ";
    // }

    RecursiveInsertionSort(arr, arr.size());
    cout << "After Sorting" << endl;
    for (auto it : arr)
    {
        cout << it << " ";
    }

    return 0;
}