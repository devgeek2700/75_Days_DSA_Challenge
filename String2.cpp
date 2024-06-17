#include <bits/stdc++.h>
using namespace std;

// Sort Characters By Frequency
string frequencySort(string s) // TC --> O(n+nlogn)  SC --> O(n+m)
{
    int n = s.length();
    unordered_map<char, int> freq;
    for (int i = 0; i < n; i++)
    {
        freq[s[i]]++;
    }

    vector<pair<char, int>> freqlist(freq.begin(), freq.end());

    sort(freqlist.begin(), freqlist.end(), [](const pair<char, int> &a, const pair<char, int> &b)
         { return a.second > b.second; });

    string result;
    for (auto &pair : freqlist)
    {
        //            (3, n) --> "nnn"
        result.append(pair.second, pair.first);
    }

    return result;
}

// Maximum Nesting Depth of the Parentheses
int maxDepth(string s) // TC --> O(N) SC --> O(1)
{
    int n = s.length();
    int maxDepth = INT_MIN;
    int currDepth = 0;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
        {
            currDepth++;
            maxDepth = max(maxDepth, currDepth);
        }
        else if (s[i] == ')')
        {
            currDepth--;
        }
    }
    return maxDepth;
}

// Roman to Integer
int romanToInt(string str) // TC --> O(N) SC --> O(1)
{
    int n = str.length();
    int total = 0;

    unordered_map<char, int> roman{{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};

    for (int i = 0; i < n; i++)
    {
        if (i + 1 < n && roman[str[i]] < roman[str[i + 1]])
        {
            total -= roman[str[i]];
        }
        else
        {
            total += roman[str[i]];
        }
    }
    return total;
}

//  String to Integer (atoi)
int myAtoi(string str) // TC --> O(N) SC --> O(1)
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

    long long ans = 0;

    while (i < n && isdigit(str[i]))
    {
        ans = ans * 10 + (str[i] - '0');

        // Check for overflow and underflow
        if (sign * ans <= INT_MIN)
        {
            return INT_MIN;
        }

        if (sign * ans >= INT_MAX)
        {
            return INT_MAX;
        }
        i++;
    }

    return sign * ans;
}

// Count number of substrings
long long int atMostKDistinct(string s, int k) // TC --> O(N^2) SC --> O(1)
{
    int n = s.length();
    int count = 0;
    map<char, int> mpp;
    for (int i = 0; i < n; i++)
    {
        mpp.clear();
        for (int j = i; j < n; j++)
        {
            mpp[s[j]]++;
            if (mpp.size() <= k)
            {
                count++;
            }
            else
            {
                break;
            }
        }
    }
    return count;
}

long long int substrCount1(string s, int k)
{
    if (k == 0)
    {
        return 0;
    }

    return atMostKDistinct(s, k) - atMostKDistinct(s, k - 1);
}

// optimal solution
long long int atMostKDistinct1(string s, int k) // TC --> O(N) SC --> O(n, 256)
{
    int n = s.size();
    int count = 0;
    int left = 0;
    int right = 0;
    map<char, int> mpp;

    while (right < n)
    {
        mpp[s[right]]++;
        while (mpp.size() > k)
        {
            mpp[s[left]]--;
            if (mpp[s[left]] == 0)
            {
                mpp.erase(s[left]);
            }
            left++;
        }

        // All substrings from left to right end are valid when mpp.size() <= k
        count += (right - left + 1);
        right++;
    }

    return count;
}

long long int substrCount(string s, int k)
{
    if (k == 0)
    {
        return 0;
    }

    return atMostKDistinct1(s, k) - atMostKDistinct1(s, k - 1);
}

// Longest Palindromic Substring

int main()
{
    string str = "aba";
    int k = 2;
    cout << "String: " << str << endl;

    // auto result = frequencySort(str);
    // cout << "Sorted String: " << result << endl;

    // auto result = maxDepth(str);
    // cout << "Maximum Nesting Depth of the Parentheses: " << result << endl;

    // auto result = romanToInt(str);
    // cout << "Roman to Integer: " << result << endl;

    // auto result = myAtoi(str);
    // cout << "String to Integer (atoi): " << result << endl;

    auto result = substrCount(str, k);
    cout << "Count number of substrings: " << result << endl;

    return 0;
}