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

int main()
{
    cout << "Hello World";
    return 0;
}