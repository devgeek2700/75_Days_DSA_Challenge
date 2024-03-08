#include <bits/stdc++.h>
using namespace std;

// Iterative Method
int binarysearch(vector<int> &arr, int n, int target) // TC --> O(logn)  SC --> O(1)
{
    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] > target)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;
}

// Recursive Method
int binarysearchRecursive(vector<int> &arr, int low, int high, int target) // TC --> O(logn)  SC --> O(1)
{
    int n = arr.size();

    if (low > high)
    {
        return -1;
    }

    int mid = (low + high) / 2;

    if (arr[mid] == target)
    {
        return mid;
    }
    else if (arr[mid] > target)
    {
        binarysearchRecursive(arr, low, mid - 1, target);
    }
    else
    {
        binarysearchRecursive(arr, mid + 1, high, target);
    }
}

//  Implement Lower Bound  -->smallest index such that arr[idx] >= x
// int lowerBound(vector<int> arr, int n, int x) // TC --> O(logn)  SC --> O(1)
// {
// 	int low = 0;
//     int high = n - 1;
//     int ans = n;

//     while (low <= high)
//     {
//         int mid = (low + high) / 2;

//         if (arr[mid] >= x)
//         {
//             ans =  mid;
//             high = mid - 1;

//         }else{
//             low = mid + 1;
//         }
//     }
//     return ans;
// }

//  Implement Lower Bound  --> using library

int lowerBound(vector<int> arr, int n, int x) // TC --> O(logn)  SC --> O(1)
{
    // // to find from start to end 1 to n
    // auto lowerBound = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
    // return lowerBound;

    // to find in range
    auto lowerBound = lower_bound(arr.begin() + 1, arr.end() + 5, x) - arr.begin();
    return lowerBound;
}

//  Implement Upper Bound  -->smallest index such that arr[idx] > x
// int upperBound(vector<int> &arr, int x, int n) // TC --> O(logn)  SC --> O(1)
// {
//     int low = 0;
//     int high = n - 1;
//     int ans = n;

//     while (low <= high)
//     {
//         int mid = (low + high) / 2;

//         if (arr[mid] > x)
//         {
//             ans = mid;
//             high = mid - 1;
//         }
//         else
//         {
//             low = mid + 1;
//         }
//     }
//     return ans;
// }

//  Implement Upper Bound  --> using library

int upperBound(vector<int> &arr, int x, int n) // TC --> O(logn)  SC --> O(1)
{
    // to find from start to end 1 to n
    auto upperBound = upper_bound(arr.begin(), arr.end(), x) - arr.begin();
    return upperBound;

    // // to find in range
    // auto lowerBound = lower_bound(arr.begin() + 1, arr.end() + 5, x) - arr.begin();
    // return lowerBound;
}

//  Search Insert Position --> just like lower bound

int searchInsert(vector<int> &arr, int m) // TC --> O(logn)  SC --> O(1)
{
    int n = arr.size();
    int low = 0;
    int high = n - 1;
    int ans = n;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] >= m)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

//  Ceil The Floor  --> ceil = lower bound

pair<int, int> getFloorAndCeil(vector<int> &arr, int n, int x)
{
    int low = 0;
    int high = n - 1;
    int ceil = -1;
    int floor = -1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == x)
        {
            floor = ceil = arr[mid];
            break;
        }
        else if (arr[mid] < x) // 4 < 2
        {
            floor = arr[mid];
            low = mid + 1;
        }
        else
        {
            ceil = arr[mid]; //4 > 2  --> 3
            high = mid - 1;
        }
    }

    return {floor, ceil};
}

int main()
{
    vector<int> arr = {3, 4, 4, 7, 8, 10};

    int n = arr.size();
    int target = 2;

    cout << "Display Arrays: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // int result = binarysearch(arr, n, target);
    // cout << "Element Found at: " << result << endl;

    // int result1 = binarysearchRecursive(arr, 0, n - 1, target);
    // cout << "Recursive Mtd Element Found at: " << result1 << endl;

    // int result1 = lowerBound(arr, n, target);
    // cout << "Implement Lower Bound: " << result1 << endl;

    // int result = upperBound(arr, n, target);
    // cout << "Implement Upper Bound: " << result << endl;

    // int result = searchInsert(arr, target);
    // cout << "Search Insert Position: " << result << endl;

    pair<int, int> result = getFloorAndCeil(arr, n, target);
    cout << "Search Insert Position: " << result.first << " " << result.second << endl;

    return 0;
}