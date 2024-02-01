#include <bits/stdc++.h>
using namespace std;

// Hashing is prestoring and fetching
// int arr1[1e7]; // u can decalre upto arr[10^7] --> oustside/global main

int main()
{
    // for Numbers to map in hash
    // int n;
    // cout << "n: ";
    // cin >> n;

    // int arr[n];
    // cout << "Enter Array Elements: ";
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> arr[i];
    // }

    // // precompute to store in hash
    // int hash[10000] = {0}; // u can decalre upto arr[10^6] --> inside main
    // for (int i = 0; i < n; i++)
    // {
    //     hash[arr[i]]++;
    // }

    // int q;
    // cout << "q: ";
    // cin >> q;

    // cout << "Query Elements: ";
    // while (q--)
    // {
    //     int num;
    //     cin >> num;
    //     // fetch from hash
    //     cout << hash[num] << " ";
    // }

    // // for String map to number index in hash for LOWERCASE
    // string str;
    // cout << "str: ";
    // cin >> str;

    // int q;
    // cout << "q: ";
    // cin >> q;

    // int hash[26] = {0};
    // for (int i = 0; i < str.size(); i++)
    // {
    //     hash[str[i] - 'a']++;
    // }

    // cout << "Query Elements: ";
    // while (q--)
    // {
    //     char ch;
    //     cin >> ch;
    //     // fetch from hash
    //     cout << hash[ch-'a'] << " ";
    // }

    // for String map to number index in hash for all characters
    string str;
    cout << "str: ";
    cin >> str;

    int q;
    cout << "q: ";
    cin >> q;

    int hash[256] = {0};
    for (int i = 0; i < str.size(); i++)
    {
        hash[str[i]]++;
    }

    cout << "Query Elements: ";
    while (q--)
    {
        char ch;
        cin >> ch;
        // fetch from hash
        cout << hash[ch] << " ";
    }

    // for solving the problem of (10^9) --> we use Hash Map

    return 0;
}