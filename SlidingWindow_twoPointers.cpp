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

// Fruit Into Baskets
// bructe force solution

int totalFruit1(vector<int> &fruits) // TC --> O(N^2)  SC --> O(1)
{
    int maxLen = INT_MIN;
    int n = fruits.size();
    for (int i = 0; i < n; i++)
    {
        set<int> set;
        for (int j = i; j < n; j++)
        {
            set.insert(fruits[j]);

            if (set.size() <= 2)
            {
                maxLen = max(maxLen, j - i + 1);
            }
            else
            {
                break;
            }
        }
    }
    return maxLen;
}

// better solution

int totalFruit2(vector<int> &fruits) // TC --> O(2N)  SC --> O(1)
{
    int maxLen = INT_MIN;
    int n = fruits.size();
    int left = 0;
    int right = 0;
    unordered_map<int, int> mpp;

    while (right < n)
    {
        mpp[fruits[right]]++;
        while (mpp.size() > 2)
        {
            mpp[fruits[left]]--;
            if (mpp[fruits[left]] == 0)
            {
                mpp.erase(fruits[left]);
            }
            left++;
        }
        maxLen = max(maxLen, right - left + 1);
        right++;
    }

    return maxLen;
}

// Optimal solution

int totalFruit(vector<int> &fruits) // TC --> O(N)  SC --> O(1)
{
    int maxLen = INT_MIN;
    int n = fruits.size();
    int left = 0;
    int right = 0;
    unordered_map<int, int> mpp;

    while (right < n)
    {
        mpp[fruits[right]]++;
        if (mpp.size() > 2)
        {
            mpp[fruits[left]]--;
            if (mpp[fruits[left]] == 0)
            {
                mpp.erase(fruits[left]);
            }
            left++;
        }
        maxLen = max(maxLen, right - left + 1);
        right++;
    }

    return maxLen;
}

// Longest Repeating Character Replacement
// bructe force solution
int characterReplacement1(string str, int k) // TC --> O(N^2)  SC --> O(n,256)
{
    int maxLen = INT_MIN;
    int maxFreq = INT_MIN;
    int n = str.length();
    for (int i = 0; i < n; i++)
    {
        map<int, int> mpp;
        for (int j = i; j < n; j++)
        {
            mpp[str[j]]++;

            maxFreq = max(maxFreq, mpp[str[j]]);
            int changes = (j - i + 1) - maxFreq;

            if (changes <= k)
            {
                maxLen = max(maxLen, j - i + 1);
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
int characterReplacement(string str, int k) // TC --> O(N)  SC --> O(n,256)
{
    int maxLen = INT_MIN;
    int maxFreq = INT_MIN;
    int n = str.length();
    int left = 0;
    int right = 0;
    unordered_map<char, int> umpp;

    while (right < n)
    {
        umpp[str[right]]++;
        maxFreq = max(maxFreq, umpp[str[right]]);

        while ((right - left + 1) - maxFreq > k)
        {
            umpp[str[left]]--;
            left++;
        }
        maxLen = max(maxLen, right - left + 1);
        right++;
    }
    return maxLen;
}

// Binary Subarrays With Sum
int Calculateforgoal(vector<int> &nums, int goal) // TC --> O(2*(2N)) SC --> O(1)
{
    int n = nums.size();
    int sum = 0;
    int left = 0;
    int right = 0;
    int count = 0;

    if (goal < 0)
    {
        return 0;
    }

    while (right < n)
    {
        sum += nums[right];

        while (sum > goal)
        {
            sum -= nums[left];
            left++;
        }
        count += right - left + 1;
        right++;
    }

    return count;
}

int numSubarraysWithSum(vector<int> &nums, int goal)
{
    int ans = Calculateforgoal(nums, goal) - Calculateforgoal(nums, goal - 1);
    return ans;
}

// Count Number of Nice Subarrays

int CalculateforkOdds(vector<int> &nums, int k) // TC --> O(2*(2N)) SC --> O(1)
{
    int n = nums.size();
    int sum = 0;
    int left = 0;
    int right = 0;
    int count = 0;

    if (k < 0)
    {
        return 0;
    }

    while (right < n)
    {
        sum += (nums[right]) % 2;

        while (sum > k)
        {
            sum -= (nums[left]) % 2;
            left++;
        }
        count += right - left + 1;
        right++;
    }

    return count;
}

int numberOfSubarrays(vector<int> &nums, int k)
{
    int ans = CalculateforkOdds(nums, k) - CalculateforkOdds(nums, k - 1);
    return ans;
}

// Number of Substrings Containing All Three Characters
// bructe force solution
int numberOfSubstrings1(string s) // TC --> O(N^2)  SC --> O(1)
{
    int n = s.size();
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        map<char, int> mpp;
        for (int j = i; j < n; j++)
        {
            mpp[s[j] - 'a'] = 1;
            if (mpp[0] + mpp[1] + mpp[2] == 3)
            {
                count++;
            }
        }
    }
    return count;
}

// better force solution
int numberOfSubstrings2(string s) // TC --> O(N^2)  SC --> O(1)
{
    int n = s.size();
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        map<char, int> mpp;
        for (int j = i; j < n; j++)
        {
            mpp[s[j] - 'a'] = 1;
            if (mpp[0] + mpp[1] + mpp[2] == 3)
            {
                count += (n - j);
                break;
            }
        }
    }
    return count;
}

// Optimal force solution
int numberOfSubstrings(string s) // TC --> O(N)  SC --> O(1)
{
    int n = s.size();
    vector<int> last_seen(3, -1);
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        last_seen[s[i] - 'a'] = i;
        if (last_seen[0] != -1 && last_seen[1] != -1 && last_seen[2] != -1)
        {
            count += 1 + min({last_seen[0], last_seen[1], last_seen[2]});
        }
    }

    return count;
}

//  Maximum Points You Can Obtain from Cards
int maximumPoints(int n, vector<vector<int>> &grid)
{
    int totalPoints = 0;

    for (int i = 0; i < n; ++i)
    {
        totalPoints += grid[i][i];

        if (i != n - 1 - i)
        {
            totalPoints += grid[i][n - 1 - i];
        }
    }

    return totalPoints;
}

int main()
{
    string str = "abcabc";
    vector<int> varr = {2, 4, 6};
    int k = 1;

    cout << "string is: " << str << endl;

    // cout << "Display Element: ";
    // for (int i = 0; i < varr.size(); i++)
    // {
    //     cout << varr[i] << " ";
    // }
    // cout << endl;

    // int result = lengthOfLongestSubstring(str);
    // cout << "Longest Substring Without Repeating Characters: " << result << endl;

    // int result = consecutiveOnes(varr, k);
    // cout << "Max Consecutive Ones III: " << result << endl;

    // int result = totalFruit(varr);
    // cout << "Fruit Into Baskets: " << result << endl;

    // int result = characterReplacement(str, k);
    // cout << "Longest Repeating Character Replacement: " << result << endl;

    // int result = numSubarraysWithSum(varr, k);
    // cout << "Binary Subarrays With Sum: " << result << endl;

    // int result = numberOfSubarrays(varr, k);
    // cout << " Count Number of Nice Subarrays: " << result << endl;

    int result = numberOfSubstrings(str);
    cout << "No of Substrings Containing All Three Characters: " << result << endl;

    return 0;
}