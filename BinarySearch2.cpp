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


int func(int mid, int n, int m) {
    long long ans = 1;
    for (int i = 1; i <= n; i++) {
        ans = ans * mid;
        if (ans > m) return 2;
    }
    if (ans == m) return 1;
    return 0;
}

int NthRoot(int n, int m) {
    //Use Binary search on the answer space:
    int low = 1, high = m;
    while (low <= high) {
        int mid = (low + high) / 2;
        int midN = func(mid, n, m);
        if (midN == 1) {
            return mid;
        }
        else if (midN == 0) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}



int main()
{
    int n = 4;
    int m = 69;

    int result = NthRoot(n,m);
    cout << "Find Nth Root Of M: " << result << endl;

    return 0;
}