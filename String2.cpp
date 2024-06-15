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
int maxDepth(string s)
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

int main()
{
    string str = "()(())((()()))";
    cout << "String: " << str << endl;

    // auto result = frequencySort(str);
    // cout << "Sorted String: " << result << endl;

    auto result = maxDepth(str);
    cout << "Maximum Nesting Depth of the Parentheses: " << result << endl;

    return 0;
}