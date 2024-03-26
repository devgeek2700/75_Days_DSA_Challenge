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

    if (m > n)
    {
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

int largestSubarraySumMinimized(vector<int> a, int k)
{
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

//  Minimize Max Distance to Gas Station  --> Min on Max
// place them in equal distances

// better soln
// double minimiseMaxDistance(vector<int> &arr, int k) {
//     int n = arr.size();
//     vector<int> howMany(n - 1, 0);
//     priority_queue<pair<long double, int>> pq;

//     for (int i = 0; i < n - 1; i++) {
//         pq.push({arr[i + 1] - arr[i], i});
//     }

//     for (int gasStn = 1; gasStn <= k; gasStn++) {
//         auto tp = pq.top();
//         pq.pop();
//         int secIdx = tp.second;
//         howMany[secIdx]++;

//         long double initialDiff = arr[secIdx + 1] - arr[secIdx];
//         long double newSection = initialDiff / (long double)(howMany[secIdx] + 1); // Corrected division
//         pq.push({newSection, secIdx});
//     }
//     return pq.top().first;
// }

// optimal soln
int noofGasStationsrequired( vector<int> &arr, long double dist) {
    int n = arr.size(); // size of the array
    int cnt = 0;
    for (int i = 1; i < n; i++) {
        int numberInBetween = ((arr[i] - arr[i - 1]) / dist);
        if ((arr[i] - arr[i - 1]) == (dist * numberInBetween)) {
            numberInBetween--;
        }
        cnt += numberInBetween;
    }
    return cnt;
}

double minimiseMaxDistance(vector<int> &arr, int k)
{
    long double low = 0;
    long double high = *max_element(arr.begin(), arr.end());
    long double ans = -1;

    long double diff = 1e-6;

    while (high - low > diff)
    {
        long double mid = (low + high) / (2.0);
        int countofGasStn = noofGasStationsrequired(arr, mid);

        if (countofGasStn > k)
        {
            low = mid;
        }
        else
        {
            ans = mid;
            high = mid;
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int k = 1;
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

    // int result = findLargestMinDistance(arr, k);
    // cout <<" Painter's Partition Problem: " << result << endl;

    auto result = minimiseMaxDistance(arr, k);
    cout << " Minimize Max Distance to Gas Station: " << result << endl;

    return 0;
}