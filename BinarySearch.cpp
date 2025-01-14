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
            ceil = arr[mid]; // 4 > 2  --> 3
            high = mid - 1;
        }
    }

    return {floor, ceil};
}

//  First and Last Position of an Element In Sorted Array

// pair<int, int> firstAndLastPosition(vector<int> &arr, int n, int k) // TC --> O(n)  SC --> O(1)
// {
//     int first = -1;
//     int last = -1;

//     for (int i = 0; i < n; i++)
//     {
//         if (arr[i] == k)
//         {
//             if (first == -1)
//             {
//                 first = i;
//             }
//             else
//             {
//                 last = i;
//             }
//         }
//         if (last == -1)
//         {
//             last = first;
//         }
//     }

//     return {first, last};
// }

// Optimal soln --> using libraies
// pair<int, int> firstAndLastPosition(vector<int> &arr, int n, int k) { // TC --> O(n)  SC --> O(1)
//     int first = lower_bound(arr.begin(), arr.end(), k) - arr.begin();
//     int last = (upper_bound(arr.begin(), arr.end(), k) - arr.begin()) - 1;

//     if (first == n || arr[first] != k) {
//         first = last = -1;
//     }

//     return {first, last};
// }

// Optimal soln --> using first and last function call

int firstPosition(vector<int> &arr, int n, int k)
{
    int low = 0;
    int first = -1;
    int high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == k)
        {
            first = mid;
            high = mid - 1;
        }
        else if (arr[mid] > k)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return first;
}

int lastPosition(vector<int> &arr, int n, int k)
{
    int low = 0;
    int last = -1;
    int high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == k)
        {
            last = mid;
            low = mid + 1;
        }
        else if (arr[mid] > k)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return last;
}

pair<int, int> firstAndLastPosition(vector<int> &arr, int n, int k) // TC --> O(n)  SC --> O(1)
{
    int first = firstPosition(arr, n, k);
    if (first == -1)
    {
        return {-1, -1};
    }
    int last = lastPosition(arr, n, k);

    return {first, last};
}

//  Number of occurrence  --> using libraies

// int countofoccurrence(vector<int> &arr, int n, int x) // TC --> O(n)  SC --> O(1)
// {
//     int first = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
//     int last = (upper_bound(arr.begin(), arr.end(), x) - arr.begin()) - 1;

//     int count = last - first + 1;

//     return count;
// }

// Optimal soln --> using first and last function call

int countofoccurrence(vector<int> &arr, int n, int x) // TC --> O(n)  SC --> O(1)
{
    int first = firstPosition(arr, n, x);
    if (first == -1)
    {
        return 0;
    }
    int last = lastPosition(arr, n, x);

    return last - first + 1;
}

//  Search In Rotated Sorted Array (I) --> all values are unique

int RotatedArrayI(vector<int> &arr, int n, int k) // TC --> O(n)  SC --> O(1)
{
    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == k)
        {
            return mid;
        }
        // left part sorted
        if (arr[low] <= arr[mid])
        {
            if (arr[low] <= k && k <= arr[mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        // right part sorted
        else
        {
            if (arr[mid] <= arr[high])
            {
                if (arr[mid] <= k && k <= arr[high])
                {
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }
        }
    }
    return -1;
}

//  Search In Rotated Sorted Array (II) --> dulpicates

bool searchInARotatedSortedArrayII(vector<int> &arr, int k) // TC --> O(n)  SC --> O(1)
{
    int n = arr.size();
    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == k)
        {
            return true;
        }

        if (arr[low] == arr[mid] && arr[mid] == arr[high])
        {
            low = low + 1;
            high = high - 1;
            continue;
        }
        // left part sorted
        if (arr[low] <= arr[mid])
        {
            if (arr[low] <= k && k <= arr[mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        // right part sorted
        else
        {
            if (arr[mid] <= arr[high])
            {
                if (arr[mid] <= k && k <= arr[high])
                {
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }
        }
    }
    return false;
}

//  Minimum no of times Rotated

int findMin(vector<int> &arr) // TC --> O(logn)  SC --> O(1)
{
    int n = arr.size();
    int low = 0;
    int high = n - 1;
    int minVal = INT_MAX;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[low] <= arr[high])
        {
            minVal = min(minVal, arr[low]);
            break;
        }

        // left half is sorted if low < mid
        if (arr[low] <= arr[mid])
        {
            minVal = min(minVal, arr[low]);
            low = mid + 1;
        }
        else
        {
            minVal = min(minVal, arr[mid]);
            high = mid - 1;
        }
    }

    return minVal;
}

// minimum number of times Rotation
int findKRotation(vector<int> &arr) // TC --> O(logn)  SC --> O(1)
{
    int n = arr.size();
    int low = 0;
    int high = n - 1;
    int minVal = INT_MAX;
    int minIdx = 0;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[low] <= arr[high])
        {
            if (arr[low] < minVal)
            {
                minVal = arr[low];
                minIdx = low;
            }

            break;
        }

        // left half is sorted if low < mid
        if (arr[low] <= arr[mid])
        {
            if (arr[low] < minVal)
            {
                minVal = arr[low];
                minIdx = low;
            }

            low = mid + 1;
        }
        else
        {
            if (arr[mid] < minVal)
            {
                minVal = arr[mid];
                minIdx = mid;
            }

            high = mid - 1;
        }
    }

    return minIdx;
}

//  Single Element in a Sorted Array
// Bructe force
// int singleNonDuplicate(vector<int>& arr)
// {
//     int n = arr.size();
//     int singleVal;

//     if(n == 1){
//         return n;
//     }

//     for(int i = 0; i < n; i++){
//         if( i == 0){
//             if(arr[i] != arr[i+1]){
//                 return arr[i];
//             }
//         }else if(i == n-1){
//             if(arr[i] != arr[i-1]){
//                 return arr[i];
//             }
//         }else{
//             if(arr[i] != arr[i+1] && arr[i-1] != arr[i]){
//                 return arr[i];
//             }
//         }
//     }
//   }

// eliminate only that part where element is not present
// (even , odd) --> element is on right half
// (odd  , even) --> element is on left half

int singleNonDuplicate(vector<int> &arr) // TC --> O(logn)  SC --> O(1)
{
    int n = arr.size();
    int low = 1;
    int high = n - 2;

    if (n == 1)
    {
        return arr[0];
    }

    if (arr[0] != arr[1])
    {
        return arr[0];
    }

    if (arr[n - 1] != arr[n - 2])
    {
        return arr[n - 1];
    }

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] != arr[mid + 1] && arr[mid] != arr[mid - 1])
        {
            return arr[mid];
        }

        // left half --> go to right half of element
        if (mid % 2 == 1 && arr[mid] == arr[mid - 1] || mid % 2 == 0 && arr[mid] == arr[mid + 1])
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}


//  Find Peak Element
int findPeakElement(vector<int> &arr) {
    int n = arr.size();
    int low = 1;
    int high = n - 2;

     if (n == 1)
    {
        return 0;
    }

     if (arr[0] > arr[1])
    {
        return 0;
    }

     if (arr[n-1] >  arr[n-2])
    {
        return n-1;
    }


    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] > arr[mid + 1] && arr[mid] > arr[mid-1])
        {
            return mid;
            // maxPeak = max(maxPeak, arr[mid]);
        }

        if (arr[mid - 1] < arr[mid])
        {
            low = mid + 1;
        }
        else if(arr[mid] > arr[mid+1])
        {
            high = mid - 1;
        }
        else{
            low = mid+1;
        }
    }
    return -1;
}




int main()
{
    vector<int> arr = {1, 2, 1 };

    int n = arr.size();
    int target = 47;

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

    // pair<int, int> result = getFloorAndCeil(arr, n, target);
    // cout << "Search Insert Position: " << result.first << " " << result.second << endl;

    // pair<int, int> result = firstAndLastPosition(arr, n, target);
    // cout << "First and Last Position of an Element In Sorted Array: " << result.first << " " << result.second << endl;

    // int result = countofoccurrence(arr, n, target);
    // cout << "Number of occurrence: " << result << endl;

    // int result = RotatedArrayI(arr, n, target);
    // cout << "Search In Rotated Sorted Array (I): " << result << endl;

    // bool result = searchInARotatedSortedArrayII(arr, target);
    // cout << "Search In Rotated Sorted Array (II): " << result << endl;

    // int result = findMin(arr);
    // cout << "Find Minimum in Rotated Sorted Array: " << result << endl;

    // int result = findKRotation(arr);
    // cout << "Find Minimum no of times Rotated: " << result << endl;

    // int result = singleNonDuplicate(arr);
    // cout << "Single Element in a Sorted Array: " << result << endl;

    int result = findPeakElement(arr);
    cout <<"Find Peak Element at index: " << result << endl;

    return 0;
}