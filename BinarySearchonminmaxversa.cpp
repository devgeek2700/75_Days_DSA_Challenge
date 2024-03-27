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
int noofGasStationsrequired(vector<int> &arr, long double dist)
{
    int n = arr.size(); // size of the array
    int cnt = 0;
    for (int i = 1; i < n; i++)
    {
        int numberInBetween = ((arr[i] - arr[i - 1]) / dist);
        if ((arr[i] - arr[i - 1]) == (dist * numberInBetween))
        {
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

//  Median of two sorted arrays

double median(vector<int> &a, vector<int> &b)
{
    int n1 = a.size();
    int n2 = b.size();

    // first array to be smaller
    if (n1 > n2)
    {
        return median(b, a);
    }

    int low = 0;
    int high = n1;
    int left = (n1 + n2 + 1) / 2;
    int n = n1 + n2;

    while (low <= high)
    {
        int mid1 = (low + high) >> 1;
        int mid2 = left - mid1;
        int l1 = (mid1 == 0) ? INT_MIN : a[mid1 - 1];
        int l2 = (mid2 == 0) ? INT_MIN : b[mid2 - 1];
        int r1 = (mid1 == n1) ? INT_MAX : a[mid1];
        int r2 = (mid2 == n2) ? INT_MAX : b[mid2];

        if (l1 <= r2 && l2 <= r1)
        {
            if (n % 2 == 1)
            {
                return max(l1, l2);
            }
            return (double)(max(l1, l2) + min(r1, r2)) / 2.0;
        }
        else if (l1 > r2)
        {
            high = mid1 - 1;
        }
        else
        {
            low = mid1 + 1;
        }
    }
    return 0;
}



int main()
{
    vector<int> arr = {1,2,2};
    vector<int> barr = {2,4,4};
    int k = 1;
    // int m = 4;
    int n = arr.size();
    int m = barr.size();

    cout << "Display Arrays arr: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Display Arrays barr: ";
    for (int i = 0; i < m; i++)
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

    // auto result = minimiseMaxDistance(arr, k);
    // cout << " Minimize Max Distance to Gas Station: " << result << endl;

    auto result = median(arr, barr);
    cout << "Median of two sorted arrays: " << result << endl;

    return 0;
}