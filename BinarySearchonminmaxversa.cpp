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



//  Largest Subarray Sum Minimized  // Max on Min

int SubarrayDivide(vector<int> &arr, int mid)
{
    int CurrentSubArr = 1;
    int SubArrnxt = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        if (SubArrnxt + arr[i] <= mid)
        {
            SubArrnxt += arr[i];
        }
        else
        {
            CurrentSubArr += 1;
            SubArrnxt = arr[i];
        }
    }

    return CurrentSubArr;
}

int largestSubarraySumMinimized(vector<int> a, int k) {
    int low = *max_element(a.begin(), a.end());
    int high = accumulate(a.begin(), a.end(), 0);
    int ans = -1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        int requiredAns = SubarrayDivide(a, mid);

        if (requiredAns > k)
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

// Painter's Partition Problem

int canpaintboard(vector<int> &arr, int mid)
{
    int countPainter = 1;
    int currPainter = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        if (currPainter + arr[i] <= mid)
        {
            currPainter += arr[i];
        }
        else
        {
            countPainter += 1;
            currPainter = arr[i];
        }
    }

    return countPainter;
}


int findLargestMinDistance(vector<int> &boards, int k)
{
    int low = *max_element(boards.begin(), boards.end());
    int high = accumulate(boards.begin(), boards.end(), 0);
    int ans = -1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        int requiredAns = canpaintboard(boards, mid);

        if (requiredAns > k)
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
    vector<int> arr = {48, 90};
    int k = 2;
    // int m = 4;
    int n = arr.size();

    cout << "Display Arrays: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // int result = aggressiveCows(arr, k);
    // cout << "Aggressive Cows: " << result << endl;

    // int result = findPages(arr, n, m);
    // cout << "Allocate Books: " << result << endl;

    // int result = largestSubarraySumMinimized(arr, k);
    // cout <<"Largest Subarray Sum Minimized: " << result << endl;

    int result = findLargestMinDistance(arr, k);
    cout <<" Painter's Partition Problem: " << result << endl;

    return 0;
}





int findFirstRepeatingDigit(string digitPattern) {
    unordered_set<char> seen;

    for (char digit : digitPattern) {
        // If the current digit is already in the set, it's repeating, return it
        if (seen.find(digit) != seen.end()) {
            return digit - '0'; // Convert char to int
        } else {
            seen.insert(digit);
        }
    }

    // If no repeating digit is found, return -1
    return -1;
}