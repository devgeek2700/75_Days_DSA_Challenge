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

int consecutiveOnes(vector<int> &arr)
{
    int max_length = 0;
    int current_length = 0;

    for (int i = 0; i < arr.size(); ++i)
    {
        if (arr[i] == 1)
        {
            current_length++;
            max_length = max(max_length, current_length);
        }
        else
        {
            current_length = 0;
        }
    }

    return max_length;
}

int main()
{
    string str = "abcabcbb";

    cout << "string is: " << str << endl;

    int result = lengthOfLongestSubstring(str);
    cout << "Longest Substring Without Repeating Characters: " << result << endl;

    return 0;
}