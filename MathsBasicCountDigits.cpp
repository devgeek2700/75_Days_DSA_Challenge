#include <bits/stdc++.h>
#include <cmath>

using namespace std;

void explainExtractionDigits(int n)
{
    while (n != 0)
    {
        int extractdigits = n % 10;
        cout << "Extracted numbers: " << extractdigits << endl;
        n = n / 10;
    }
}

int explainCountDigits(int n)
{
    int count = 0;
    int originalNumber = n;

    while (n > 0)
    {
        int extractedValue = n % 10;
        if (extractedValue != 0 && originalNumber % extractedValue == 0)
        {
            count++;
        }

        n = n / 10;
    }

    // for dividing the time complexity will be O(log10(n))

    return count;
}

int expainReverseNumber(int n)
{
    int storeRevervseNum = 0;

    while (n > 0)
    {
        int extractedValue = n % 10;
        storeRevervseNum = storeRevervseNum * 10 + extractedValue;
        n = n / 10;
    }
    return storeRevervseNum;
}

bool explainPalindromeNumber(int n)
{
    int storeRevervseNumPan = 0;
    int originalValue = n;
    while (n > 0)
    {
        int extractedValue = n % 10;
        storeRevervseNumPan = storeRevervseNumPan * 10 + extractedValue;
        n = n / 10;
    }

    return storeRevervseNumPan == originalValue;
}

int countDigits(int n)
{
    int count = 0;
    while (n > 0)
    {
        n /= 10;
        count++;
    }
    return count;
}

bool explainArmstrongNumber(int n)
{
    int ArmstrongSum = 0;
    int originalNumber = n;
    int numDigits = countDigits(n);
    while (n != 0)
    {
        int extractdigits = n % 10;
        ArmstrongSum += pow(extractdigits, numDigits);
        n = n / 10;
    }
    return ArmstrongSum == originalNumber;
}

// METHOD - 1
// void Printalldivisors(int n)
// {
//     for (int i = 1; i <= sqrt(n); i++)
//     {
//         if (n % i == 0)
//         {
//             cout << i << " ";
//         }
//         if (i != n / i)
//         {
//             cout << i << " ";
//         }
//     }
// }

// METHOD - 2
void Printalldivisors(int n)
{
    vector<int> v;

    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            v.push_back(i);

            if (i != (n / i))
            {
                v.push_back(n / i);
            }
        }
    }

    sort(v.begin(), v.end());

    cout << "All Divisors are: ";
    for (auto it : v)
    {
        cout << it << " ";
    }
}

// METHOD - 1
int sumOfDivisors(int num)
{
    int sum = 0;

    for (int i = 1; i <= num; ++i)
    { // Start from 1 instead of 0
        if (num % i == 0)
        {
            sum += i;
        }
    }
    return sum;
}

// METHOD - 2
// int sumOfDivisors(int num) {
//     int sum = 0;

//     for (int i = 1; i <= sqrt(num); ++i) {  // Iterate up to the square root of num
//         if (num % i == 0) {
//             sum += i;

//             // If i is not the square root, add the other divisor
//             if (i != num / i) {
//                 sum += num / i;
//             }
//         }
//     }

//     return sum;
// }

int sumOfAllDivisors(int n)
{
    int result = 0;
    for (int i = 1; i <= n; ++i)
    {
        result += sumOfDivisors(i);
    }
    return result;
}

// METHOD - 1
// bool CheckPrimeNumber(int n)
// {
//     if (n == 1 || n == 0)
//     {
//         return false;
//     }

//     for (int i = 2; i <= sqrt(n); i++)
//     {
//         if (n % i == 0)
//         {
//             return false;
//         }
//     }
//     return true;
// }

// METHOD - 2
bool CheckPrimeNumber(int n)
{
    int count = 0;
    for (int i = 1; i * i < n; i++)
    {
        if (n % i == 0)
        {
            count++;
            if (n / i != i)
            {
                count++;
            }
        }
    }

    if (count == 2)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// METHOD - 1
// int printGCD(int n1, int n2)
// {
//     int gcdAns = 0;
//     for (int i = 1; i <= min(n1, n2); i++)
//     {
//         if (n1 % i == 0 && n2 % i == 0)
//         {
//             gcdAns = i;
//         }
//     }
//     return gcdAns;
// }

// METHOD - 2
int printGCDusingEuclideanAlgo(int n1, int n2)
{
    // formula
    // Mtd - 1
    // gcd(a, b)  =  gcd(a-b, b)   where a>b  until it one of them became 0

    // Mtd - 2    --> more optimized algorithm
    // gcd(a, b)  =  gcd(a%b, b)   where a>b  until it one of them became 0

    while (n1 > 0 && n2 > 0)
    {
        if (n1 > n2)
        {
            n1 = n1 % n2;
        }
        else
        {
            n2 = n2 % n1;
        }
    }

    if (n1 == 0)
    {
        return n2;
    }
    else
    {
        return n1;
    }
}

int main()
{
    // int n = 13;
    int n1 = 2;
    int n2 = 5;
    // cout << "entered Number is: " << n << endl;
    cout << "entered Number1 is: " << n1 << endl;
    cout << "entered Number2 is: " << n2 << endl;
    // cout << "Count Digits is: " << explainCountDigits(n) << endl;
    // cout << "Reversed Number is: " << expainReverseNumber(n) << endl;
    // cout << "Palindrome number or not?: " << (explainPalindromeNumber(n) ? "Yes" : "No") << endl;
    // cout << "Armstrong number or not?: " << (explainArmstrongNumber(n) ? "Yes" : "No ") << endl;
    // explainExtractionDigits(n);
    // Printalldivisors(n);
    // cout << endl;
    // cout << "sum Of Divisors: " << sumOfAllDivisors(n) << endl;
    // cout << "Prime Number or not?: " << (CheckPrimeNumber(n) ? "Yes" : "No ") << endl;
    cout << "GCD of two numbers: " << printGCDusingEuclideanAlgo(n1, n2) << endl;

    return 0;
}