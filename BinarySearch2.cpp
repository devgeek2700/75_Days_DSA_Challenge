#include <bits/stdc++.h>
using namespace std;

// Binary search on Answers

//  Square Root of a number
// linear search method

// int floorSqrt(int n) {  // TC --> O(n)
//     int ans = 1;
//     for (int i = 1; i <= n; i++) {
//         if (i * i <= n) {
//             ans = i;
//         } else {
//             break;
//         }
//     }
//     return ans;
// }

// binary search method
int floorSqrt(int n) // TC --> O(logn)
{

    int low = 1;
    int high = n;
    int ans = 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (mid * mid <= n)
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

//  Find Nth Root Of M

int func(int mid, int n, int m)
{
    long long ans = 1;
    for (int i = 1; i <= n; i++)
    {
        ans = ans * mid;
        if (ans > m)
            return 2;
    }
    if (ans == m)
        return 1;
    return 0;
}

int NthRoot(int n, int m)
{
    // Use Binary search on the answer space:
    int low = 1, high = m;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int midN = func(mid, n, m);
        if (midN == 1)
        {
            return mid;
        }
        else if (midN == 0)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

//  Koko Eating Bananas
// totalhours = ceil(arr[i]/hourly)

int countperHour(vector<int> v, int mid, int h)
{
    int totalHours = 0;

    for (int i = 0; i < v.size(); i++)
    {
        totalHours += ceil(double(v[i]) / mid);
    }
    return totalHours;
}

int minimumRateToEatBananas(vector<int> v, int h)
{
    int low = 1;
    int high = *max_element(v.begin(), v.end());
    int ans = high;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        int requiredAns = countperHour(v, mid, h);

        if (requiredAns <= h)
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

//  Rose Garden

bool possibleBloomDay(vector<int> arr, int k, int m, int day)
{
    int count = 0;
    int noofBouquets = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] <= day)
        {
            count++;
        }
        else
        {
            noofBouquets += (count / k);
            count = 0;
        }
    }

    noofBouquets += (count / k);

    if (noofBouquets >= m)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int roseGarden(vector<int> arr, int k, int m)
{
    // m -->  no of Bouquets
    // k -->  adjacent flowers required

    int low = *min_element(arr.begin(), arr.end());
    int high = *max_element(arr.begin(), arr.end());
    int ans = -1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        int requiredAns = possibleBloomDay(arr, k, m, mid);

        if (requiredAns == true)
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

//  Smallest divisor

int allpossibleDivisor(vector<int> arr, int mid)
{
    int totalDivisor = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        totalDivisor += ceil(double(arr[i]) / mid);
    }
    return totalDivisor;
}

int smallestDivisor(vector<int> &arr, int limit)
{
    int low = 1;
    int high = *max_element(arr.begin(), arr.end());
    int n = arr.size();
    int ans = -1;

    if (n > limit)
    {
        return ans;
    }

    while (low <= high)
    {
        int mid = (low + high) / 2;
        int requiredAns = allpossibleDivisor(arr, mid);

        if (requiredAns <= limit)
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

//  Capacity To Ship Packages Within D Days

int allpossibleDays(vector<int> weights, int Capacity)
{
    int noofDays = 1;
    int load = 0;

    for (int i = 0; i < weights.size(); i++)
    {
        if (load + weights[i] > Capacity)
        {
            noofDays += 1;
            load = weights[i];
        }
        else
        {
            load += weights[i];
        }
    }
    return noofDays;
}

int leastWeightCapacity(vector<int> &weights, int d)
{
    // low has to be maximum of the capacity so that each & every weights is transfered
    // high has to be maximum of the capacity so that each & every weights is transfered

    int n = weights.size();
    int low = *max_element(weights.begin(), weights.end());
    int high = accumulate(weights.begin(), weights.end(), 0);
    int ans = -1;
    

    while (low <= high)
    {
        int mid = (low + high) / 2;
        int requiredAns = allpossibleDays(weights, mid);

        if (requiredAns <= d)
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

int main()
{
    // int n = 4;
    // int h = 7;
    // int k = 1;
    // int m = 1;
    // int limit = 11;

    vector<int> arr = {86 ,45, 74, 64, 14 ,68, 44 ,11, 43, 33, 8, 20};
    int n = arr.size();
    int d = 12;

    cout << "Display Arrays: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // int result = minimumRateToEatBananas(arr, h);
    // cout << "Koko Eating Bananas: " << result << endl;

    // int result = roseGarden(arr, k, m);
    // cout << "Rose Garden: " << result << endl;

    // int result = smallestDivisor(arr, limit);
    // cout << "Smallest Divisor Given a limit: " << result << endl;

    int result = leastWeightCapacity(arr, d);
    cout << "Capacity To Ship Packages Within D Days: " << result << endl;

    return 0;
}