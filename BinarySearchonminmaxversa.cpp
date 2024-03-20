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

int main()
{
    vector<int> arr = {4, 2, 1, 3, 6};
    int k = 2;
    int n = arr.size();

    cout << "Display Arrays: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    int result = aggressiveCows(arr, k);
    cout << "Aggressive Cows: " << result << endl;

    return 0;
}