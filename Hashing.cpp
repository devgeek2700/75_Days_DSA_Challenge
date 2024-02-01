#include <bits/stdc++.h>
using namespace std;

// Hashing is prestoring and fetching
// int arr1[1e7]; // u can decalre upto arr[10^7] --> oustside/global main

vector<int> countFrequency(int n, int x, vector<int> &nums) {
    vector<int> result(x, 0);

    for (int i = 0; i < n; i++) {
        if (nums[i] <= x) {
            result[nums[i] - 1]++;
        }
    }

    return result;
}


vector<int> getFrequencies(vector<int> &v)
{
    unordered_map<int, int> umap;

    // Calculate frequencies into store
    for (auto num : v)
    {
        umap[num]++;
    }

    int highestFreq = 0;
    int lowestFreq = INT_MAX;
    int highElement = -1;
    int lowElement = -1;

    // find MIN and MAX frequency
    for (auto &itr : umap)
    {
        int keyvalue = itr.first;
        int freq = itr.second;

        // for MAX frequency
        if (freq > highestFreq ||(freq == highestFreq && keyvalue < highElement) ){
            highestFreq = freq;
            highElement = keyvalue;
        }

        // for MIN frequency
        if (freq < lowestFreq ||(freq == lowestFreq && keyvalue < lowElement) ){
            lowestFreq = freq;
            lowElement = keyvalue;
        }
    }
    return {highestFreq, lowestFreq};
}

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
    // string str;
    // cout << "str: ";
    // cin >> str;

    // int q;
    // cout << "q: ";
    // cin >> q;

    // int hash[256] = {0};
    // for (int i = 0; i < str.size(); i++)
    // {
    //     hash[str[i]]++;
    // }

    // cout << "Query Elements: ";
    // while (q--)
    // {
    //     char ch;
    //     cin >> ch;
    //     // fetch from hash
    //     cout << hash[ch] << " ";
    // }

    // // for solving the problem of (10^9) --> we use Hash Map
    // cout << "Using Hash Map" << endl;
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
    // map<int, int> hmap;
    // for (int i = 0; i < n; i++)
    // {
    //     hmap[arr[i]]++;
    // }

    // for (auto it : hmap)
    // {
    //     cout << it.first << "->" << it.second << endl;
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
    //     cout << hmap[num] << " ";
    // }

    // for String map using hash map for LOWERCASE
    // string str;
    // cout << "str: ";
    // cin >> str;

    // int q;
    // cout << "q: ";
    // cin >> q;

    // unordered_map<char, int> chmap;

    // for (int i = 0; i < str.size(); i++)
    // {
    //     chmap[str[i]]++;
    // }

    //   for (auto it : chmap)
    // {
    //     cout << it.first << "->" << it.second << endl;
    // }

    // cout << "Query Elements: ";
    // while (q--)
    // {
    //     char ch;
    //     cin >> ch;
    //     // fetch from hash
    //     cout << chmap[ch] << " ";
    // }

    // ****************** in hash map first prefrence shoud be
    // unordered_map O(1) and if it give time limit exceed
    // then switch to map  ********************************

    // Collisions --> if every elements take palce to teh same index then it collison

    // techniques to avoid collisions
    // (a) Division Method using linear chainig
    // (b) Folding Method
    // (c) Mid Square Method




//  Count Frequency in a range

    int n, x;

    cout << "n: ";
    cin >> n;

    cout << "x: ";
    cin >> x;

    cout << "Array: ";
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    vector<int> result = countFrequency(n, x, arr);

    // Print the result
    for (int i = 0; i < n; ++i) {
        cout << result[i] << " ";
    }




    //  Highest / Lowest Frequency Elements
    // int n;
    // cout<<"n: ";
    // cin >> n;

    // cout<<"Array: ";
    // vector<int> v(n);
    // for (int i = 0; i < n; ++i) {
    //     cin >> v[i];
    // }

    // vector<int> result = getFrequencies(v);

    // cout <<"Highest / Lowest Frequency Elements: "<<result[0] << " " << result[1] << endl;



    return 0;
}