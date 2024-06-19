#include <bits/stdc++.h>
using namespace std;

// Pow(x, n)
// bructe force
double myPow1(double x, int n)
{
    double ans = 1.0;
    long long nn = n;
    if (nn < 0)
    {
        nn = -1 * nn;
    }

    while (nn)
    {
        if (nn % 2 == 1)
        {
            ans = ans * x;
            nn = nn - 1;
        }
        else
        {
            x = x * x;
            nn = nn / 2;
        }
    }
    if (n < 0)
    {
        ans = 1.0 / (ans);
    }
    return ans;
}

// Recursion

double myPow(double x, int n)
{
    if (n == 0)
    {
        return 1.0;
    }

    if (n < 0)
    {
        x = 1 / x;
        n = -1 * n;
    }

    if (n % 2 == 0)
    {
        double half = myPow(x, n / 2);
        return half * half;
    }
    else
    {
        return x * myPow(x, n - 1);
    }
}

int main()
{
    double x = 2.00000;
    int n = -2;
    cout << "x: " << x << " and n: " << n << endl;

    auto result = myPow(x, n);
    cout << "Pow(x, n): " << result << endl;

    return 0;
}