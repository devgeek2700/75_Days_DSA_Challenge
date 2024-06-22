#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

// Pow(x, n)
// bructe force
double myPow1(double x, int n) // TC --> O(logn) SC --> O(1)
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

double myPow(double x, int n) // TC --> O(logn) SC --> O(n)
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

int recursionmyAtoi(string str, int i, int sign, int ans) // TC --> O(n) SC --> O(1)
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

int myAtoi(string str) // TC --> O(n) SC --> O(1)

{
    int n = str.length();
    int i = 0;
    vector<int> digitpassing;

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

// Count Good Numbers

// power function using recursin
long long modExp(long long base, long long exp, long long mod)

{
    long long result = 1;
    while (exp > 0)
    {
        if (exp % 2 == 1)
        {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

int countGoodNumbers(long long n) // TC --> O(log n) SC --> O(log n)
{

    long long EvenIdx = (n + 1) / 2;
    long long OddIdx = (n / 2);

    long long evenCombinations = modExp(5, EvenIdx, MOD);
    long long oddCombinations = modExp(4, OddIdx, MOD);

    long long TotalCombinations = (evenCombinations * oddCombinations) % MOD;
    return TotalCombinations;
}

// Sort a stack

void insertSortedOrder(stack<int> &sortedstack, int topVal)
{
    // if stack is empty or top element is smaller or equal to value

    if (sortedstack.empty() || sortedstack.top() <= topVal)
    {
        sortedstack.push(topVal);
        return;
    }

    // pop elements greater than value and insert value
    int top = sortedstack.top();
    sortedstack.pop();
    insertSortedOrder(sortedstack, topVal);
    sortedstack.push(top);
}

stack<int> SortedStack(stack<int> &st) // TC --> O(N^2) SC --> O(N)
{
    stack<int> sortedstack;

    while (!st.empty())
    {
        int temp = st.top();
        st.pop();

        insertSortedOrder(sortedstack, temp);
    }

    return sortedstack;
}

// Reverse a stack using recursion

void swapStackValues(stack<int> &st, int top) // TC --> O(N)
{
    if (st.empty())
    {
        st.push(top);
    }
    else
    {
        int temptop = st.top();
        st.pop();
        swapStackValues(st, top);
        st.push(temptop);
    }
}

void Reverse(stack<int> &st) // TC --> O(N)
{

    if (!st.empty())
    {
        int top = st.top();
        st.pop();
        Reverse(st);
        swapStackValues(st, top);
    }
}

void Reversestack(stack<int> &st) // TC --> O(N^2) SC --> O(1)
{
    if (st.empty())
    {
        return;
    }

    Reverse(st);
}

int main()
{
    // double x = 2.00000;
    // int n = 80;
    // string str = "1337c0d3";
    stack<int> st;
    st.push(6);
    st.push(7);
    st.push(1);
    st.push(2);
    st.push(3);

    cout << "Original stack numbers are: ";
    stack<int> stCopy = st;
    while (!stCopy.empty())
    {
        cout << stCopy.top() << " ";
        stCopy.pop();
    }
    cout << endl;

    // cout << "x: " << x << " and n: " << n << endl;
    // cout << "str: " << str << endl;
    // cout << "N: " << n << endl;

    // auto result = myPow(x, n);
    // cout << "Pow(x, n): " << result << endl;

    // auto result = myAtoi(str);
    // cout << "String to Integer (atoi): " << result << endl;

    // auto result = countGoodNumbers(n);
    // cout << "Count Good Numbers: " << result << endl;

    // stack<int> sortedSt = SortedStack(st);
    // cout << "Sorted numbers are: ";

    // while (!sortedSt.empty())
    // {
    //     cout << sortedSt.top() << " ";
    //     sortedSt.pop();
    // }
    // cout << endl;

    Reversestack(st);
    cout << "Reverse a stack using recursion: ";

    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;

    return 0;
}