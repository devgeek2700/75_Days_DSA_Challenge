#include <bits/stdc++.h>

using namespace std;

// When a function calls itself until a specified condition is met is Recursion

void print()
{
    cout << "1" << endl;
    print();
}

void printCountName(int i, int n)
{
    // Base case
    if (i > n) //  --> 1 > 5
    {
        return;
    }

    cout << "Neha"
         << " " << i << endl;
    i++;

    printCountName(i, n);
}

void printnto1times(int n)
{
    if (n < 1)
    {
        return;
    }

    cout << n << " ";
    n--;

    printnto1times(n);
}

void print1tontimesbyBacktracking(int i, int n)
{
    if (i <= 0)
    {
        return;
    }
    print1tontimesbyBacktracking(i - 1, n);
    cout << i << " ";
}

void printnto1timesbyBacktracking(int i, int n)
{
    if (i > n)
    {
        return;
    }
    printnto1timesbyBacktracking(i + 1, n);
    cout << i << " ";
}

vector<string> printNTimes(int n)
{
    if (n <= 0)
    {
        return vector<string>();
    }

    vector<string> result = printNTimes(n - 1);

    result.push_back("Coding Ninjas");

    return result;
}

vector<int> printNos1toN(int x)
{
    if (x < 1)
    {
        return vector<int>();
    }

    vector<int> result = printNos1toN(x - 1);
    result.push_back(x);

    return result;
}

vector<int> printNosNto1(int x)
{
    if (x < 1)
    {
        return vector<int>();
    }

    vector<int> result;
    result.push_back(x);

    vector<int> resultCont = printNosNto1(x - 1);

    result.insert(result.end(), resultCont.begin(), resultCont.end());

    return result;
}

int printSum(int n)
{
    if (n < 1) //  --> 5 < 1  --> X
    {
        return 0;
    }

    int sum = n + printSum(n - 1);

    return sum;
}

int printSuminO_N(int n)
{
    return (n * (n + 1)) / 2;
}

int factorial(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }

    return n * factorial(n - 1);
}

long long calculateFactorial(int num)
{

    if (num == 0 || num == 1)
    {
        return 1;
    }
    else
    {
        return num * calculateFactorial(num - 1);
    }
}

vector<long long> factorialNumbersNotGreaterThanN(int n)
{
    vector<long long> result;
    for (int i = 1; calculateFactorial(i) <= n; i++)
    {
        result.push_back(calculateFactorial(i));
    }

    sort(result.begin(), result.end());

    return result;
}

vector<int> reverseArray(int n, vector<int> &nums)
{
    reverse(nums.begin(), nums.end());
    return nums;
}

int main()
{
    int n = 6;

    // print();

    // cout << "Print Names 5 times" << endl;
    // printCountName(1, n);
    // cout << endl;

    // cout << "Print Linearnly n times" << endl;
    // printLinearnly(1, n);
    // cout << endl;

    // cout << "Print n to 1 times" << endl;
    // printnto1times(n);

    // cout << "Print 1 to n times by backtracking" << endl;
    // print1tontimesbyBacktracking(n, n);

    // cout << "Print 1 to n times by backtracking" << endl;
    // printnto1timesbyBacktracking(1, n);

    // cout << "Sum is: " << printSum(n) << endl;
    // cout << "Sum is by O(n): " << printSuminO_N(n) << endl;
    // cout << "Factorial is: " << factorial(n) << endl;

    // vector<long long> answer = factorialNumbersNotGreaterThanN(n);

    // cout << "Factorial numbers less than or equal to " << n << ": ";
    // for (long long it : answer)
    // {
    //     cout << it << " ";
    // }

    vector<int> nums(n);

    cout << "Enter " << n << " elements for the vector:" << endl;
    for (int i = 0; i < n; ++i)
    {
        cin >> nums[i];
    }

    reverseArray(n, nums);

    cout << "Reversed vector: ";
    for (int i = 0; i < n; ++i)
    {
        cout << nums[i] << " ";
    }

    return 0;
}