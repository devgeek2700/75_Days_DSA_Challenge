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

// Power of n Recursion

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

// String to Integer (atoi)

int recursionmyAtoi(string str, int i, int sign, int ans)
{
    if (i >= str.length() || !isdigit(str[i]))
    {
        return ans;
    }

    // Get the current digit and update the answer
    int digit = str[i] - '0';

    // Check for overflow before updating ans
    if (ans > (INT_MAX - digit) / 10)
    {
        return sign == 1 ? INT_MAX : INT_MIN;
    }

    ans = ans * 10 + digit;

    return recursionmyAtoi(str, i + 1, sign, ans);
}

int myAtoi(string str)
{
    int n = str.length();
    int i = 0;

    // Check leading whitespace.
    while (i <= n && str[i] == ' ')
    {
        i++;
    }

    // Check sign character.
    int sign = 1;
    if (i < n && (str[i] == '-' || str[i] == '+'))
    {
        if (str[i] == '-')
        {
            sign = -1;
        }
        else
        {
            sign = 1;
        }
        // sign = (str[i] = '-') ? -1 : +1;
        i++;
    }

    if (i < n && isdigit(str[i]))
    {
        long long result = recursionmyAtoi(str, i, sign, 0);
        return sign * result;
    }

    return 0;
}

int main()
{
    // double x = 2.00000;
    // int n = -2;
    string str = "words and 987";
    // cout << "x: " << x << " and n: " << n << endl;
    cout << "str: " << str << endl;

    // auto result = myPow(x, n);
    // cout << "Pow(x, n): " << result << endl;

    auto result = myAtoi(str);
    cout << "String to Integer (atoi): " << result << endl;

    return 0;
}