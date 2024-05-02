#include <bits/stdc++.h>
using namespace std;

//  Count Primes

// Mtd - 1 Bructe force
// vector<int> countPrimes(int n) // TC --> O(n * sqrt(N))  SC --> O(n)
// {
//     vector<int> list;
//     vector<bool> isPrime(n, true);

//     for (int i = 0; i < n; i++)
//     {
//         if (n % 2 == 0)
//         {
//             if (isPrime(i))
//             {
//                 list.push_back(i);
//             }
//         }
//     }
// }

// Mtd - 2 Better soln

// vector<int> countPrimesbetter(int n) // TC --> nearly O(2 * sqrt(N))  SC --> O(n)
// {
//     vector<int> list;
//     vector<bool> isPrime(n, true);

//     for (int i = 0; i < n; i++)
//     {
//         if (n % 2 == 0)
//         {
//             if (isPrime(i))
//             {
//                 list.push_back(i);
//             }
//             if (n / i != i)
//             {

//                 list.push_back(i);
//             }
//         }
//     }
// }

// Mtd - 3 optimal soln

vector<int> countPrimesdivide(int n) // TC --> nearly O(2 * sqrt(N))  SC --> O(n)
{
    vector<int> list;
    for (int i = 2; i <= n; i++)
    {
        if (n % i == 0)
        {
            list.push_back(i);

            while (n % i == 0)
            {
                n = n / i;
            }
        }
    }
    return list;
}

// Mtd - 4 advance optimal soln

vector<int> countPrimesdivideadvance(int n) // TC --> nearly O(sqrt(N)*logn)  SC --> O(n)
{
    vector<int> list;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            list.push_back(i);

            while (n % i == 0)
            {
                n = n / i;
            }
        }
    }

    if (n != 1)
    {
        list.push_back(n);
    }

    return list;
}

//  Print all Divisors of a number
// Mtd - 1 Bructe force

int *printDivisors(int n, int &size) // Tc --> O(n)  SC --> O(answer)
{
    int *arr = new int[size];
    for (int i = 0; i < n; i++)
    {
        if (n % i == 0)
        {
            arr[i] = i;
        }
    }
}

// Mtd - 2 optimal soln

int *printDivisorssqrt(int n, int &size) // Tc --> O(sqrt(n))  SC --> O(answer)
{
    size = 0;
    int *arr = new int[2 * int(sqrt(n))];
    // for (int i = 1; i <= sqrt(n); i++)
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            arr[size++] = i;
            if (n / i != i)
            {
                arr[size++] = n / i;
            }
        }
    }

    sort(arr, arr + size);

    return arr;
}

// Sieve of Eratosthenes print all prime till n
// Mtd - 1
vector<int> SieveofEratosthenes(int n) // TC -->  O(3*n)  SC --> O(n)
{
    vector<int> primearr(n + 1, 1);
    vector<int> ans;
    for (int i = 2; i <= n; i++)
    {
        primearr[i] = 1;
    }

    for (int i = 2; i <= n; i++)
    {
        if (primearr[i] == 1)
        {
            for (int j = 2 * i; j <= n; j += i)
            {
                primearr[j] = 0;
            }
        }
    }

    for (int i = 2; i <= n; i++)
    {
        if (primearr[i] == 1)
        {
            ans.push_back(i);
        }
    }
    return ans;
}

// Mtd - 2
vector<int> SieveofEratosthenes2(int n) // TC -->  O(2*n*nlog(logn))  SC --> O(n)
{
    vector<int> primearr(n + 1, 1);
    vector<int> ans;
    for (int i = 2; i <= n; i++)
    {
        primearr[i] = 1;
    }

    for (int i = 2; i * i <= n; i++)
    {
        if (primearr[i] == 1)
        {
            for (int j = i * i; j <= n; j += i)
            {
                primearr[j] = 0;
            }
        }
    }

    for (int i = 2; i <= n; i++)
    {
        if (primearr[i] == 1)
        {
            ans.push_back(i);
        }
    }
    return ans;
}

// Prime Factorisation
// Mtd - 1
// vector<int> getPrimeFactorisation(int n) // TC --> nearly O(sqrt(N)*logn)  SC --> O(n)
// {
//     vector<int> list;
//     for (int i = 2; i * i <= n; i++) // Changed i <= sqrt(n) to i * i <= n
//     {
//         if (n % i == 0)
//         {
//             while (n % i == 0)
//             {
//                 list.push_back(i);
//                 n = n / i;
//             }
//         }
//     }

//     if (n != 1)
//     {
//         list.push_back(n);
//     }

//     return list;
// }

// vector<vector<int>> PrimesFactorisation(vector<int> Queries) // TC --> nearly O(Queries * sqrt(n))  SC --> O(n)
// {
//     vector<vector<int>> result;

//     for (int i = 0; i < Queries.size(); i++)
//     {
//         result.push_back(getPrimeFactorisation(Queries[i]));
//     }

//     return result;
// }

// void printVector(vector<int> vec)
// {
//     for (int i = 0; i < vec.size(); i++)
//     {
//         cout << vec[i] << " ";
//     }
//     cout << endl;
// }

// Mtd - 2 using Smallest Prime Factor (SPF)
vector<vector<int>> PrimesFactorisation(vector<int> Queries) // TC --> nearly O(Queries * sqrt(n))  SC --> O(n)
{
    int n = *max_element(Queries.begin(), Queries.end());
    vector<vector<int>> result(n + 1);
    vector<int> spf(n + 1, 1);

    for (int i = 1; i <= n; i++)
    {
        spf[i] = i;
    }

    for (int i = 2; i * i <= n; i++)
    {
        if (spf[i] == i)
        {
            for (int j = i * i; j <= n; j += i)
            {
                if (spf[j] == j)
                {
                    spf[j] = i;
                }
            }
        }
    }

    for (int i = 0; i < Queries.size(); i++)
    {
        int num = Queries[i];
        while (num != 1)
        {
            result[Queries[i]].push_back(spf[num]);
            num = num / spf[num];
        }
    }

    return result;
}

void printVector(vector<int> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
}

void printFactorisation(vector<vector<int>> factors)
{
    for (int i = 0; i < factors.size(); i++)
    {
        cout << "Prime factorisation of " << i + 1 << ": ";
        printVector(factors[i]);
    }
}

// Power Exponentiation
int power(int N, int R) // TC --> O(log2N)  SC --> O()
{
    int m = N;
    // int ans = 1;
    double ans = 1;
    while (N > 0)
    {
        if (N % 2 == 1)
        {
            ans = ans * R;
            N--;
        }
        else
        {
            N = N / 2;
            R = R * R;
        }
    }

    if (m < 0)
    {
        // ans = 1/ans; //for -Ve
        ans = 1.0 / ans; // for double
    }
    return ans;
}


// Mtd - 2 using modulo advance
int power(int N, int R) // TC --> O(log2N)  SC --> O(1)
{
    long long ans = 1;
    const int MOD = 1e9 + 7; 
    while (R > 0)
    {
        if (R % 2 == 1)
        {
            ans = (ans * N) % MOD;
        }
        R = R / 2;
        N = (1LL * N * N) % MOD;
    }
    return ans;
}

int main()
{
    // int n = 780;
    // vector<int> result = countPrimesdivideadvance(n);
    // cout << "Count Primes: ";
    // for (auto &i : result)
    // {
    //     cout << i << " ";
    // }

    // int n;
    // cout << "Enter a number: ";
    // cin >> n;

    // int size;
    // int *result = printDivisorssqrt(n, size);

    // cout << "Print all Divisors of " << n << ": ";
    // for (int i = 0; i < size; i++)
    // {
    //     cout << result[i] << " ";
    // }
    // cout << endl;

    // vector<int> result = SieveofEratosthenes(n);
    // vector<int> result = SieveofEratosthenes2(n);
    // cout << "Sieve of Eratosthenes Primes: ";
    // for (auto &i : result)
    // {
    //     cout << i << " ";
    // }

    // vector<int> queries = {10, 15, 21};
    // vector<vector<int>> factors = PrimesFactorisation(queries);
    // printFactorisation(factors);

    int res = power(14, 41);
    cout << "Power Exponentiation: " << res << endl;

    return 0;
}