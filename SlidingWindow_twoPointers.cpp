#include <bits/stdc++.h>
using namespace std;

// Longest Substring Without Repeating Characters
// bructe force solution
int lengthOfLongestSubstring1(string str) // TC --> O(N^2)  SC --> O(n,256)
{
    int maxLen = INT_MIN;
    int n = str.length();
    for (int i = 0; i < n; i++)
    {
        map<int, int> map;
        for (int j = i; j < n; j++)
        {
            if (map.find(str[j]) != map.end())
            {
                break;
            }
            int currLen = j - i + 1;
            maxLen = max(maxLen, currLen);
            map[str[j]] = 1;
        }
    }
    return maxLen;
}

// Optimal Approach
// for finding maximum substring --> two pointer and Sliding Windows
int lengthOfLongestSubstring(string str) // TC --> O(N)  SC --> O(n,256)
{
    int maxLen = INT_MIN;
    int n = str.length();
    int left = 0;
    int right = 0;
    unordered_map<char, int> charIdx;

    while (right < n)
    {
        if (charIdx.count(str[right]))
        {
            left = max(left, charIdx[str[right]] + 1);
        }

        charIdx[str[right]] = right;
        int currLen = right - left + 1;
        maxLen = max(maxLen, currLen);
        right++;
    }

    return maxLen;
}

// Max Consecutive Ones III
// bructe force solution

int consecutiveOnes1(vector<int> &arr, int k) // TC --> O(N^2)  SC --> O(1)
{
    int maxLen = INT_MIN;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        int currZero = 0;
        for (int j = i; j < n; j++)
        {
            if (arr[j] == 0)
            {
                currZero++;
            }
            if (currZero <= k)
            {
                int currLen = j - i + 1;
                maxLen = max(maxLen, currLen);
            }
            else
            {
                break;
            }
        }
    }
    return maxLen;
}

// Better solution
int consecutiveOnes2(vector<int> &arr, int k) // TC --> O(2N)  SC --> O(1)
{
    int maxLen = INT_MIN;
    int n = arr.size();
    int left = 0;
    int right = 0;
    int currZero = 0;

    while (right < n)
    {
        if (arr[right] == 0)
        {
            currZero++;
        }

        while (currZero > k)
        {
            if (arr[left] == 0)
            {
                currZero--;
            }
            left++;
        }

        if (currZero <= k)
        {
            int currLen = right - left + 1;
            maxLen = max(maxLen, currLen);
            right++;
        }
    }
    return maxLen;
}

// Optimal solution
int consecutiveOnes(vector<int> &arr, int k) // TC --> O(N)  SC --> O(1)
{
    int maxLen = INT_MIN;
    int n = arr.size();
    int left = 0;
    int right = 0;
    int currZero = 0;

    while (right < n)
    {
        if (arr[right] == 0)
        {
            currZero++;
        }

        if (currZero > k)
        {
            if (arr[left] == 0)
            {
                currZero--;
            }
            left++;
        }

        if (currZero <= k)
        {
            int currLen = right - left + 1;
            maxLen = max(maxLen, currLen);
        }
        right++;
    }
    return maxLen;
}

int main()
{
    string str = "abcabcbb";
    vector<int> varr = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    int k = 2;

    // cout << "string is: " << str << endl;

    cout << "Display Element: ";
    for (int i = 0; i < varr.size(); i++)
    {
        cout << varr[i] << " ";
    }
    cout << endl;

    // int result = lengthOfLongestSubstring(str);
    // cout << "Longest Substring Without Repeating Characters: " << result << endl;

    int result = consecutiveOnes(varr, k);
    cout << "Max Consecutive Ones III: " << result << endl;

    return 0;
}