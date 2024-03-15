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
int floorSqrt(int n)  // TC --> O(logn)
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

int main()
{
    int num = 100;

    int result = floorSqrt(num);
    cout << "Square Root of a number: " << result << endl;

    return 0;
}