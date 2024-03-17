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



long long power(long long x, long long y, long long p) {
    long long res = 1; // Initialize result

    x = x % p; // Update x if it is more than or equal to p

    while (y > 0) {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res * x) % p;

        // y must be even now
        y = y >> 1; // y = y/2
        x = (x * x) % p;
    }
    return res;
}

int powerOfPower(int A, int B, int C, int M) {
    // Calculate B^C mod (M-1)
    long long exp = power(B, C, M - 1);

    // Calculate A^(B^C) mod M
    long long result = power(A, exp, M);

    return result;
}


int main()
{
    int n = 4;
    int m = 69;

    int result = NthRoot(n,m);
    cout << "Find Nth Root Of M: " << result << endl;

    return 0;
}