#include <bits/stdc++.h>
using namespace std;

//  Aggressive Cows  --> min distance between 2 cows is max
// min --> always between adjacent stalls
bool canweplacecows(vector<int> &stalls, int mid, int k)
{
    int countCows = 1;
    int lastplaceCows = stalls[0];

    for (int i = 1; i < stalls.size(); i++)
    {
        if (stalls[i] - lastplaceCows >= mid)
        {
            countCows++;
            lastplaceCows = stalls[i];
        }
    }

    return countCows >= k;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    int n = stalls.size();
    sort(stalls.begin(), stalls.end());   // Sort the stalls for binary search
    int low = 1;                          // Minimum possible distance
    int high = stalls[n - 1] - stalls[0]; // Maximum possible distance
    int ans = -1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (canweplacecows(stalls, mid, k))
        {
            ans = mid; // Try for a larger minimum distance
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return ans;
}

// Allocate Books

int maxminumPagesAllocate(vector<int> &arr, int mid)
{
    int pagesHold = 0;
    int currStudent = 1;

    for (int i = 0; i < arr.size(); i++)
    {
        if (pagesHold + arr[i] <= mid)
        {
            pagesHold += arr[i];
        }
        else
        {
            currStudent++;
            pagesHold = arr[i];
        }
    }
    return currStudent;
}

int findPages(vector<int> &arr, int n, int m)
{
    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    int ans = -1;

    if (m > n)
    {
        return ans;
    }

    while (low <= high)
    {
        int mid = (low + high) / 2;
        int noOfStudents = maxminumPagesAllocate(arr, mid);

        if (noOfStudents > m)
        {
            low = mid + 1;
        }
        else
        {
            ans = mid;
            high = mid - 1;
        }
    }
    return ans;
}

// K-th element of two Arrays
int kthElement(int k, vector<int> &arr1, vector<int> &arr2)
{
    int n1 = arr1.size();
    int n2 = arr2.size();

    if (n1 < n2)
    {
        return kthElement(k, arr1, arr2);
    }

    int low = max(k - n2, 0);
    int high = min(k, n1);
    int n = n1+n2;
}

int main()
{

    vector<int> arr1 = {2, 3, 6, 7, 9};
    vector<int> arr2 = {1, 4, 8, 10};
    int k = 5;
    // int m = 2;
    // cout << "The largest minimum distance is: " << aggressiveCows(nums, k) << endl;
    // cout << "The largest minimum distance is: " << findPages(nums, n, m) << endl;
    cout << "The kthElement is: " << kthElement(k, arr1, arr2) << endl;

    return 0;
}