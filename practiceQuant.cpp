#include <bits/stdc++.h>
using namespace std;

// ************************* ARRAY EASY ***************************
// Largest Element in Array

int largest(vector<int> &arr)
{
    int n = arr.size();
    int maxVal = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > maxVal)
        {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

// Second Largest
int print2largest(vector<int> &arr)
{
    int n = arr.size();
    int firstMax = INT_MIN;
    int secondMax = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > firstMax)
        {
            secondMax = firstMax;
            firstMax = arr[i];
        }
        else if (firstMax != arr[i] && secondMax < arr[i])
        {
            secondMax = arr[i];
        }
    }

    if (secondMax == INT_MIN)
    {
        return -1;
    }
    return secondMax;
}

// Check if Array Is Sorted

bool arraySortedOrNot(vector<int> &arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            return false;
        }
    }
    return true;
}

// Check if Array Is Sorted and Rotated
bool check(vector<int> &nums)
{
    int n = nums.size();
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        count += nums[i] > nums[(i + 1) % n];
    }
    return count <= 1;
}

// Remove Duplicates from Sorted Array
int removeDuplicates(vector<int> &nums)
{
    set<int> unique_val(nums.begin(), nums.end());
    nums.assign(unique_val.begin(), unique_val.end());
    return unique_val.size();
}

// Rotate Array to right by k times
void rotate(vector<int> &nums, int k)
{
    int n = nums.size();
    k = k % n;

    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end());
}

// Rotate Array to left by k times
void rotateLeft(vector<int> &nums, int k)
{
    int n = nums.size();
    k = k % n;

    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + n - k);
    reverse(nums.begin() + n - k, nums.end());
}

// Move Zeroes at end
void moveZeroes(vector<int> &nums)
{
    int n = nums.size();
    int nonZeroIdx = 0;

    for (int i = 0; i < n; i++)
    {
        if (nums[i] != 0)
        {
            nums[nonZeroIdx++] = nums[i];
        }
    }

    for (int i = nonZeroIdx; i < n; i++)
    {
        nums[i] = 0;
    }
}

// Sorted Array Search
bool searchInSorted(vector<int> arr, int k)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == k)
        {
            return true;
        }
    }
    return false;
}

// Union of Two Sorted Arrays with Duplicate Elements
vector<int> findUnion(vector<int> &a, vector<int> &b)
{
    int n = a.size();
    int m = b.size();
    map<int, int> mpp;
    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
        mpp[a[i++]] = 1;
    }

    for (int i = 0; i < m; i++)
    {
        mpp[b[i]] = 1;
    }

    for (auto it : mpp)
    {
        ans.push_back(it.first);
    }
    return ans;
}

// Missing Number
int missingNumber(vector<int> &nums)
{
    int n = nums.size();
    int total = (n * (n + 1)) / 2;

    for (int i = 0; i < n; i++)
    {
        total -= nums[i];
    }
    return total;
}

// Max Consecutive Ones
int findMaxConsecutiveOnes(vector<int> &nums)
{
    int n = nums.size();
    int maxcount = INT_MIN;
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if (nums[i] == 1)
        {
            count++;
        }
        else
        {
            maxcount = max(maxcount, count);
            count = 0;
        }
    }
    maxcount = max(maxcount, count);
    return maxcount;
}

// Single Number
int singleNumber(vector<int> &nums)
{
    int n = nums.size();
    map<int, int> mpp;

    for (int i = 0; i < n; i++)
    {
        mpp[nums[i]]++;
    }

    for (auto it : mpp)
    {
        if (it.second == 1)
        {
            return it.first;
        }
    }
    return -1;
}

// Longest Sub-Array with Sum K
int lenOfLongestSubarrpos(vector<int> &arr, int k)
{
    int n = arr.size();
    int maxLen = 0;

    for (int i = 0; i < n; i++)
    {
        int sum = 0;

        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            if (sum == k)
            {
                maxLen = max(maxLen, j - i + 1);
            }
        }
    }
    return maxLen;
}

// Longest subarray with sum K (Positives + Negatives)

int lenOfLongestSubarr(vector<int> &arr, int k)
{
    int n = arr.size();
    map<int, int> mpp;
    int maxLen = 0;
    int currSum = 0;

    for (int i = 0; i < n; i++)
    {
        currSum += arr[i];

        if (currSum == k)
        {
            maxLen = i + 1;
        }
        // Check if the difference (currSum - k) exists in the hash map:
        // If it exists, it means there's a subarray with sum k, and its length is i - mp[currSum - k].

        if (mpp.find(currSum - k) != mpp.end())
        {
            maxLen = max(maxLen, i - arr[currSum - k]);
        }

        // If currSum is not in the hash map, store it with the current index.
        if (mpp.find(currSum) == mpp.end())
        {
            mpp[currSum] = i;
        }
    }

    return maxLen;
}

// ************************* ARRAY MEDIUM ***************************
// Two Sum
vector<int> twoSum(vector<int> &nums, int target)
{
    int n = nums.size();
    map<int, int> mpp;
    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
        int comp = target - nums[i];
        if (mpp.find(comp) != mpp.end())
        {
            ans.push_back(mpp[comp]);
            ans.push_back(i);
            return ans;
        }
        mpp[nums[i]] = i;
    }
    return ans;
}

// Sort Colors
void sortColors1(vector<int> &nums)
{
    int n = nums.size();
    int low = 0;
    int high = n - 1;
    int mid = 0;

    while (mid <= high)
    {
        if (nums[mid] == 0)
        {
            swap(nums[mid], nums[low]);
            low++;
            mid++;
        }
        else if (nums[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(nums[mid], nums[high]);
            high--;
        }
    }
}

// Majority Element
int majorityElement(vector<int> &nums)
{
    int n = nums.size();
    map<int, int> mpp;

    for (int i = 0; i < n; i++)
    {
        mpp[nums[i]]++;
    }

    for (auto it : mpp)
    {
        if (it.second > (n / 2))
        {
            return it.first;
        }
    }
    return -1;
}

// Maximum Subarray - Kadane's Algorithm
int maxSubArray(vector<int> &nums)
{
    int n = nums.size();
    int maxSum = INT_MIN;
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += nums[i];
        maxSum = max(maxSum, sum);

        if (sum < 0)
        {
            sum = 0;
        }
    }
    return maxSum;
}

// Maximum Score from Subarray Minimums
int pairWithMaxSum(vector<int> &arr)
{
    int n = arr.size();
    int maxScore = INT_MIN;

    if (n < 2)
    {
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        int currSum = arr[i] + arr[i + 1];
        maxScore = max(maxScore, currSum);
    }
    return maxScore;
}

// Best Time to Buy and Sell Stock
int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    int maxProfit = 0;
    int minPrice = prices[0];

    for (int i = 0; i < n; i++)
    {
        if (prices[i] < minPrice)
        {
            minPrice = prices[i];
        }
        else
        {
            maxProfit = max(maxProfit, prices[i] - minPrice);
        }
    }
    return maxProfit;
}

// Rearrange Array Elements by Sign
vector<int> rearrangeArray(vector<int> &nums)
{
    int n = nums.size();
    vector<int> ans;
    vector<int> positive;
    vector<int> negative;

    for (int i = 0; i < n; i++)
    {
        if (nums[i] < 0)
        {
            positive.push_back(nums[i]);
        }
        else
        {
            negative.push_back(nums[i]);
        }
    }

    for (int i = 0; i < positive.size(); i++)
    {
        ans.push_back(positive[i]);
        ans.push_back(negative[i]);
    }
    return ans;
}

// Next Permutation
void nextPermutation(vector<int> &nums)
{
    int n = nums.size();
    int i = n - 2;

    while (i >= 0 && nums[i] > nums[i + 1])
    {
        i--;
    }

    if (i >= 0)
    {
        int j = n - 1;
        while (j > i && nums[j] <= nums[i])
        {
            j--;
        }
        swap(nums[i], nums[j]);
    }
    reverse(nums.begin() + i + 1, nums.end());
}

// Array Leaders
vector<int> leaders(vector<int> &arr)
{
    vector<int> ans;
    int n = arr.size();
    int maxRight = arr[n - 1];

    for (int i = n - 1; i >= 0; i--)
    {
        if (arr[i] >= maxRight)
        {
            ans.push_back(arr[i]);
            maxRight = arr[i];
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

// Longest Consecutive Sequence
int longestConsecutive(vector<int> &nums)
{
    int n = nums.size();
    unordered_set<int> st(nums.begin(), nums.end());
    int longest = 0;

    for (int i = 0; i < n; i++)
    {
        if (st.find(nums[i] - 1) == st.end())
        {
            int currSum = nums[i];
            int currcount = 1;

            while (st.find(currSum + 1) != st.end())
            {
                currSum++;
                currcount++;
            }
            longest = max(longest, currcount);
        }
    }
    return longest;
}

// Set Matrix Zeroes
void markRow(vector<vector<int>> &matrix, int i, int m, int n)
{
    for (int j = 0; j < m; j++)
    {
        if (matrix[i][j] != 0)
        {
            matrix[i][j] = '*';
        }
    }
}

void markCol(vector<vector<int>> &matrix, int j, int m, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (matrix[i][j] != 0)
        {
            matrix[i][j] = '*';
        }
    }
}

void setZeroes(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                markRow(matrix, i, m, n);
                markCol(matrix, j, m, n);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == '*')
            {
                matrix[i][j] = 0;
            }
        }
    }
}

// Rotate Image
void rotate(vector<vector<int>> &matrix)
{
    int n = matrix.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

// Spiral Matrix
vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    vector<int> ans;
    int top = 0;
    int left = 0;
    int right = m - 1;
    int bottom = n - 1;

    while (top <= bottom && left <= right)
    {
        for (int i = left; i <= right; i++)
        {
            ans.push_back(matrix[top][i]);
        }
        top++;

        for (int i = top; i <= bottom; i++)
        {
            ans.push_back(matrix[i][right]);
        }
        right--;

        if (top <= bottom)
        {
            for (int i = right; i >= left; i--)
            {
                ans.push_back(matrix[bottom][i]);
            }
            bottom--;
        }

        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
            {
                ans.push_back(matrix[i][left]);
            }
            left++;
        }
    }
    return ans;
}

// ************************* ARRAY HARD ***************************

// Pascal's Triangle
vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> ans;

    for (int i = 0; i < numRows; i++)
    {
        vector<int> row(i + 1, 1);

        for (int j = 1; j < i; j++)
        {
            row[j] = ans[i - 1][j - 1] + ans[i - 1][j];
        }
        ans.push_back(row);
    }
    return ans;
}

//  Majority Element greater than floor(N / 3)

vector<int> majorityElement(vector<int> v)
{
    int n = v.size();
    vector<int> answer;
    map<int, int> mpp;

    for (auto it : v)
    {
        mpp[it]++;
    }

    for (auto it : mpp)
    {
        if (it.second > floor(n / 3))
        {
            answer.push_back(it.first);
        }
    }
    return answer;
}

//  Three Sum
vector<vector<int>> triplet(int n, vector<int> &arr)
{
    vector<vector<int>> tripletValues;
    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; i++)
    {
        if (i > 0 && arr[i] == arr[i - 1])
        {
            continue;
        }

        int j = i + 1;
        int k = n - 1;

        while (j < k)
        {
            int sum = arr[i] + arr[j] + arr[k];
            if (sum < 0)
            {
                j++;
            }
            else if (sum > 0)
            {
                k--;
            }
            else
            {
                tripletValues.push_back({arr[i], arr[j], arr[k]});
                j++;
                k--;

                while (j < k && arr[j] == arr[j - 1])
                {
                    j++;
                }
                while (j < k && arr[k] == arr[k + 1])
                {
                    k--;
                }
            }
        }
    }
    return tripletValues;
}

//  Four Sum
vector<vector<int>> fourSum(vector<int> &arr, int target)
{
    int n = arr.size();
    vector<vector<int>> quadruplets;
    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; i++)
    {
        if (i > 0 && arr[i] == arr[i - 1])
        {
            continue;
        }

        for (int j = i + 1; j < n; j++)
        {
            if (j > i + 1 && arr[j] == arr[j - 1])
            {
                continue;
            }

            int k = j + 1;
            int l = n - 1;

            while (k < l)
            {
                int sum = arr[i] + arr[j] + arr[k] + arr[l];
                if (sum < target)
                {
                    k++;
                }
                else if (sum > target)
                {
                    l--;
                }
                else
                {
                    quadruplets.push_back({arr[i] + arr[j] + arr[k] + arr[l]});
                    k++;
                    l--;

                    while (k < l && arr[k] == arr[k - 1])
                    {
                        k++;
                    }
                    while (k < l && arr[l] == arr[l + 1])
                    {
                        l--;
                    }
                }
            }
        }
    }
    return quadruplets;
}

//  Longest Subarray With Zero Sum

int getLongestZeroSumSubarrayLength(vector<int> &arr)
{
    int maxLen = 0;
    int sum = 0;
    int n = arr.size();
    unordered_map<int, int> umap;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];

        if (sum == 0)
        {
            maxLen = i + 1;
        }
        else
        {
            if (umap.find(sum) != umap.end())
            {
                maxLen = max(maxLen, i - umap[sum]);
            }
            else
            {
                umap[sum] = i;
            }
        }
    }
    return maxLen;
}

//  Subarrays with XOR ‘K’
int subarraysWithSumK(vector<int> arr, int b) // TC  --> O(n^2)
{
    int n = arr.size();
    int count = 0;
    int xr = 0;
    map<int, int> mpp;
    mpp[xr]++;

    for (int i = 0; i < n; i++)
    {
        xr = xr ^ arr[i];
        int X = xr ^ b;
        count += mpp[X];
        mpp[xr]++;
    }
    return count;
}

//  Merge All Overlapping Intervals
vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> &arr)
{
    int n = arr.size();
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;

    for (int i = 0; i < n; i++)
    {
        if (ans.empty() || arr[i][0] > ans.back()[1])
        {
            ans.push_back(arr[i]);
        }
        else
        {
            ans.back()[1] = max(ans.back()[1], arr[i][1]);
        }
    }
    return ans;
}

//  Merge Two Sorted Arrays Without Extra Space
void mergeTwoSortedArraysWithoutExtraSpace(vector<long long> &a, vector<long long> &b)
{
    int n = a.size();
    int m = b.size();
    int left = n - 1;
    int right = 0;

    while (left >= 0 && right < m)
    {
        if (a[left] > b[right])
        {
            swap(a[left], b[right]);
            left--;
            right++;
        }
        else
        {
            break;
        }
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
}

//  Missing And Repeating Numbers
vector<int> findMissingRepeatingNumbers(vector<int> a)
{
    int n = a.size();
    long long SN = (n * (n + 1)) / 2;                // X
    long long S2N = (n * (n + 1) * (2 * n + 1)) / 6; // Y
    long long S = 0;
    long long S2 = 0;

    for (int i = 0; i < n; i++)
    {
        S += a[i];
        S2 += (long long)a[i] * a[i];
    }
    long long val1 = S - SN;
    long long val2 = S2 - S2N;

    val2 /= val1;
    long long X = (val1 + val2) / 2;
    long long Y = X - val1;

    return {(int)X, (int)Y};
}

//  Number of Inversions

int merge(vector<int> &arr, int low, int mid, int high)
{
    vector<int> temp;
    int left = low;
    int right = mid + 1;
    int count = 0;

    while (left <= right && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            count += (mid - left + 1);
            right++;
        }
    }

    while (left <= right)
    {
        temp.push_back(arr[left]);
        left++;
    }

    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }

    return count;
}

int mergeSort(vector<int> &arr, int low, int high)
{
    int count = 0;
    if (low >= high)
    {
        return count;
    }

    int mid = (low + high) / 2;
    count += mergeSort(arr, low, mid);
    count += mergeSort(arr, mid + 1, high);
    count += merge(arr, low, mid, high);
    return count;
}

int numberOfInversions(vector<int> &a, int n)
{
    return mergeSort(a, 0, n - 1);
}

//  Team Contest or Reverse Pairs

void countPairs(vector<int> &arr, int low, int mid, int high, int &count)
{
    int right = mid + 1;
    for (int i = low; i <= mid; i++)
    {
        while (right <= high && arr[i] > 2 * arr[right])
        {
            right++;
        }
        count += (right - (mid + 1));
    }
}

int merge1(vector<int> &arr, int low, int mid, int high)
{
    vector<int> temp;
    int left = low;
    int right = mid + 1;
    int count = 0;

    while (left <= right && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            count += (mid - left + 1);
            right++;
        }
    }

    while (left <= right)
    {
        temp.push_back(arr[left]);
        left++;
    }

    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
}

void mergeSort1(vector<int> &arr, int low, int high, int &count)
{
    if (low >= high)
    {
        return;
    }

    int mid = (low + high) / 2;
    mergeSort1(arr, low, mid, count);
    mergeSort1(arr, mid + 1, high, count);
    countPairs(arr, low, mid, high, count);
    merge1(arr, low, mid, high);
}

int team(vector<int> &skill, int n)
{
    int count = 0;
    mergeSort1(skill, 0, n - 1, count);
    return count;
}

//  Subarray With Maximum Product
int subarrayWithMaxProduct(vector<int> &arr)
{
    int n = arr.size();
    int maxProduct = INT_MIN;
    int prefixSum = 1;
    int suffixSum = 1;

    for (int i = 0; i < n; i++)
    {
        if (prefixSum == 0)
        {
            prefixSum = 1;
        }
        if (suffixSum == 0)
        {
            suffixSum = 1;
        }

        prefixSum *= arr[i];
        suffixSum *= arr[n - i - 1];

        maxProduct = max(maxProduct, max(prefixSum, suffixSum));
    }
    return maxProduct;
}

// ************************* STRINGS EASY ***************************
// sort the string --> lexicographically
string sortlexicographically(string str)
{
    sort(str.begin(), str.end());
    return str;
}

// Valid Anagram -->  rearranging letters of a word to get another word
bool isAnagram(string s, string t)
{
    if (s.length() != t.length())
    {
        return false;
    }

    sort(s.begin(), s.end());
    sort(t.begin(), t.end());

    return s == t;
}

// Check Isomorphic --> 1 to 1 mapping
bool isIsomorphic(string s, string t)
{
    if (s.length() != t.length())
    {
        return false;
    }

    vector<int> s1(128, -1);
    vector<int> s2(128, -1);

    for (int i = 0; i < s.length(); i++)
    {
        if (s1[s[i]] != s2[t[i]])
        {
            return false;
        }
        s1[s[i]] = i;
        s2[t[i]] = i;
    }
    return true;
}

// Longest Common Prefix
string longestCommonPrefix(vector<string> &strs)
{
    if (strs.empty())
    {
        return "";
    }

    string mainStr = strs[0];
    int lonngestCount = mainStr.size();

    for (int i = 1; i < strs.size(); i++)
    {
        int j = 0;
        while (j < mainStr.size() && j < strs[i].size() && mainStr[j] == strs[i][j])
        {
            j++;
        }
        lonngestCount = min(lonngestCount, j);
    }

    string ans = mainStr.substr(0, lonngestCount);
    return ans;
}

// Maximum consecutive 1's fliped k times
int maxConsecutive1sKtimes(string str, int k) // TC --> O(N^2) SC --> O(1)
{
    int n = str.length();
    int maxLen = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        int currZero = 0;
        for (int j = i; j < n; j++)
        {
            if (str[j] == '0')
            {
                currZero--;
            }

            if (currZero <= k)
            {
                maxLen = max(maxLen, j - i + 1);
            }
        }
    }
    return maxLen;
}

// Remove Outermost Parentheses
string removeOuterParentheses(string s)
{
    int n = s.length();
    int balance = 0;
    string ans = "";

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
        {
            if (balance > 0)
            {
                ans.push_back(s[i]);
            }
            balance++;
        }
        else if (s[i] == ')')
        {
            balance--;
            if (balance > 0)
            {
                ans.push_back(s[i]);
            }
        }
    }
    return ans;
}

// Reverse Words in a String
string reverseWords(string s)
{
    int n = s.length();
    string ans = "";
    string finalAns = "";

    for (int i = n - 1; i >= 0; i--)
    {
        if (s[i] == !' ')
        {
            ans += s[i];
        }
        else
        {
            if (!ans.empty())
            {
                reverse(ans.begin(), ans.end());
                if (!finalAns.empty())
                {
                    finalAns += " ";
                }
                finalAns += ans;
                ans = "";
            }
        }
    }

    if (!ans.empty())
    {
        reverse(ans.begin(), ans.end());
        if (!finalAns.empty())
        {
            finalAns += " ";
        }
        finalAns += ans;
    }
    return finalAns;
}

// Largest Odd Number in String
string largestOddNumber(string str) // TC --> O(N) SC --> O(1)
{
    int n = str.length();
    string largestOdd = "";

    for (int i = n - 1; i >= 0; i--)
    {
        if ((str[i] - '0') % 2 != 0)
        {
            largestOdd = str.substr(0, i + 1);
            break;
        }
    }
    return largestOdd;
}

// Rotate String
bool rotateString(string str, string goal)
{
    int n = str.length();
    int m = goal.length();

    if (n != m)
    {
        return false;
    }

    string doubleStr = str + str;
    return (doubleStr.find(goal) != string::npos);
}

// ************************* STRINGS MEDIUM ***************************

// Sort Characters By Frequency
string frequencySort(string s) // TC --> O(n+nlogn)  SC --> O(n+m)
{
    int n = s.length();
    unordered_map<char, int> freq;

    for (int i = 0; i < n; i++)
    {
        freq[s[i]]++;
    }

    vector<pair<char, int>> freqList(freq.begin(), freq.end());

    sort(freqList.begin(), freqList.end(), [](const pair<char, int> &a, const pair<char, int> &b)
         { return a.second > b.second; });

    string result;
    for (auto &pair : freqList)
    {
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

    for (int i = 0; i < n; i++)
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
            total -= roman[i];
        }
        else
        {
            total += roman[i];
        }
    }
    return total;
}

//  String to Integer (atoi)
int myAtoi(string str) // TC --> O(N) SC --> O(1)
{
    int n = str.length();
    int i = 0;

    while (i <= n && str[i] == ' ')
    {
        i++;
    }

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
        i++;
    }

    long long ans = 0;

    while (i < n && isdigit(str[i]))
    {
        ans = ans * 10 + (str[i] - '0');

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

        count += (right - left + 1);
        right++;
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

// Longest Palindromic Substring
string longestPalindrome(string s) // TC --> O(N^2) SC --> O(1)
{
    int n = s.length();
    int start = 0;
    int maxLen = 1;

    if (n == 0)
    {
        return "";
    }

    for (int i = 0; i < n; i++)
    {
        int left = i - 1;
        int right = i + 1;

        // Odd length palindromes
        while (left >= 0 && right < n && s[left] == s[right])
        {
            if ((right - left + 1) > maxLen)
            {
                maxLen = right - left + 1;
                start = left;
            }
            left--;
            right++;
        }

        // Even length palindromes
        left = i;
        right = i + 1;
        while (left >= 0 && right < n && s[left] == s[right])
        {
            if ((right - left + 1) > maxLen)
            {
                maxLen = right - left + 1;
                start = left;
            }
            left--;
            right++;
        }
    }

    return s.substr(start, maxLen);
}

// Sum of Beauty of All Substrings
int beautySum(string s) // TC --> O(N^2) SC -- O(1)
{
    int n = s.length();
    unordered_map<char, int> mpp;
    int diffFreq;
    int beatySum = 0;

    for (int i = 0; i < n; i++)
    {
        mpp.clear();

        for (int j = i; j < n; j++)
        {
            mpp[s[j]]++;

            if (mpp.size() >= 2)
            {
                int maxFreq = 0, minFreq = INT_MAX;
                for (auto it = mpp.begin(); it != mpp.end(); it++)
                {
                    maxFreq = max(maxFreq, it->second);
                    minFreq = min(minFreq, it->second);
                }
                diffFreq = maxFreq - minFreq;
                beatySum += diffFreq;
            }
        }
    }
    return beatySum;
}

// Minimum Add to Make Parentheses Valid
int minAddToMakeValid(string s)
{
    int openNeeded = 0;
    int closeNeeded = 0;

    for (char ch : s)
    {
        if (ch == '(')
        {
            openNeeded++;
        }
        else
        {
            if (openNeeded > 0)
            {
                openNeeded--;
            }
            else
            {
                closeNeeded++;
            }
        }
    }
    return openNeeded + closeNeeded;
}

int main()
{
    // cout << "Hello World";

    string str = "())";
    cout << minAddToMakeValid(str);
    
    return 0;
}