#include <bits/stdc++.h>
using namespace std;

// selection sort --> finds smallest in all the array and then swap it with the current position

void selectionSort(vector<int> &varr)
{
    int n = varr.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (varr[i] > varr[j])
            {
                swap(varr[i], varr[j]);
            }
        }
    }
}

// Bubble sort
void BubbleSort(vector<int> &varr)
{
    int n = varr.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (varr[j] > varr[j + 1])
            {
                swap(varr[j], varr[j + 1]);
            }
        }
    }
}

// Insertion Sort
void InsertionSort(vector<int> &varr)
{
    int n = varr.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j > 0; j--)
        {
            if (varr[j] < varr[j - 1])
            {
                swap(varr[j], varr[j - 1]);
            }
        }
    }
}

// Merge Sort

void merge(vector<int> &varr, int low, int mid, int high)
{
    int left = low;
    int right = mid + 1;
    int tmpIdx = 0;
    vector<int> temp(high - low + 1);

    while (left <= mid && right <= high)
    {
        if (varr[left] <= varr[right])
        {
            temp[tmpIdx++] = varr[left++];
        }
        else
        {
            temp[tmpIdx++] = varr[right++];
        }
    }

    while (left <= mid)
    {
        temp[tmpIdx++] = varr[left++];
    }

    while (right <= high)
    {
        temp[tmpIdx++] = varr[right++];
    }

    for (int i = low, j = 0; i <= high; i++, j++)
    {
        varr[i] = temp[j];
    }
}

void mergeSort(vector<int> &varr, int low, int high)
{
    if (low < high)
    {
        int mid = low + (high - low) / 2;
        mergeSort(varr, low, mid);
        mergeSort(varr, mid + 1, high);
        merge(varr, low, mid, high);
    }
}

// Quick Sort
int partition(vector<int> &varr, int low, int high)
{
    int pivot = varr[low];
    int i = low + 1;
    int j = high;

    while (i <= j)
    {
        while (i <= high && varr[i] <= pivot)
        {
            i++;
        }

        while (varr[j] > pivot && j >= low)
        {
            j--;
        }

        if (i < j)
        {
            swap(varr[i], varr[j]);
        }
    }

    swap(varr[low], varr[j]);
    return j;
}

void quicksort(vector<int> &varr, int low, int high)
{
    if (low < high)
    {
        int pivotIndex = partition(varr, low, high);
        quicksort(varr, low, pivotIndex - 1);
        quicksort(varr, pivotIndex + 1, high);
    }
}

int main()
{
    vector<int> varr = {10, 9, -8, 7, 6, 0, 5, 4, -3, 2, 1};

    cout << "Printing the array: ";
    for (int i : varr)
    {
        cout << i << " ";
    }

    cout << endl;

    // selectionSort(varr);

    // cout << "Selection sorted array: ";
    // for (int i : varr)
    // {
    //     cout << i << " ";
    // }

    // BubbleSort(varr);

    // cout << "Bubble sorted array: ";
    // for (int i : varr)
    // {
    //     cout << i << " ";
    // }

    // InsertionSort(varr);

    // cout << "Insertion sorted array: ";
    // for (int i : varr)
    // {
    //     cout << i << " ";
    // }

    // mergeSort(varr, 0, varr.size());

    // cout << "Merge Sort sorted array: ";
    // for (int i : varr)
    // {
    //     cout << i << " ";
    // }

    quicksort(varr, 0, varr.size());

    cout << "quick Sort sorted array: ";
    for (int i : varr)
    {
        cout << i << " ";
    }

    return 0;
}