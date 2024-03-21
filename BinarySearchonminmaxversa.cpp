#include <bits/stdc++.h>
using namespace std;
// Binary Search --> on MIN on MAX or MIN on MAX

//  Aggressive Cows  --> min distance between 2 cows is max
// min --> always between adjacent stalls

bool canweplacecows(vector<int> &stalls, int dist, int k)
{
    int countCow = 1;
    int lastPlacedCows = stalls[0];

    for (int i = 1; i < stalls.size(); i++)
    {
        if (stalls[i] - lastPlacedCows >= dist)
        {
            countCow++;
            lastPlacedCows = stalls[i];
        }
    }

    if (countCow >= k)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int aggressiveCows(vector<int> &stalls, int k)
{
    sort(stalls.begin(), stalls.end());
    int n = stalls.size();
    int low = 1;
    int high = stalls[n - 1] - stalls[0];
    int ans = -1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        int requiredAns = canweplacecows(stalls, mid, k);

        if (requiredAns == true)
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return ans;
}



//  Allocate Books

int maxminumPagesAllocate(vector<int> &arr, int mid)
{
    int CurrentStudent = 1;
    int pagesHold = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        if (pagesHold + arr[i] <= mid)
        {
            pagesHold += arr[i];
        }
        else
        {
            CurrentStudent += 1;
            pagesHold = arr[i];
        }
    }

    return CurrentStudent;
}

int findPages(vector<int> &arr, int n, int m)
{ // --> max on min
    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    int ans = -1;

    if(m > n){
        return ans;
    }

    while (low <= high)
    {
        int mid = (low + high) / 2;
        int noofStudents = maxminumPagesAllocate(arr, mid);

        if (noofStudents > m)
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

int main()
{
    vector<int> arr = {25, 46, 28, 49, 24};
    // int k = 2;
    int m = 4;
    int n = arr.size();

    cout << "Display Arrays: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // int result = aggressiveCows(arr, k);
    // cout << "Aggressive Cows: " << result << endl;

    int result = findPages(arr, n, m);
    cout << "Allocate Books: " << result << endl;

    return 0;
}