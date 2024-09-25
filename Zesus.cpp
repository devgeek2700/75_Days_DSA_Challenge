#include <bits/stdc++.h>
using namespace std;

// ************************* SORTING EASY ***************************

// Selection Sort

void selectionSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                swap(arr[i], arr[j]);
            }
        }
    }
}

// Bubble Sort

void BubbleSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Insertion Sort

void InsertionSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 1; i < n; i++)
    {
        {
            for (int j = i; j > 0; j--)
            {
                if (arr[j] < arr[j - 1])
                {
                    swap(arr[j], arr[j - 1]);
                }
            }
        }
    }
}

// ************************* SORTING MEDIUM ***************************

// Merge Sort

void merge(vector<int> &arr, int low, int mid, int high)
{
    int left = low;
    int right = mid + 1;
    vector<int> temp;

    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left++]);
        }
        else
        {
            temp.push_back(arr[right++]);
        }
    }

    while (left <= mid)
    {
        temp.push_back(arr[left++]);
    }

    while (right <= high)
    {
        temp.push_back(arr[right++]);
    }

    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
}

void mergesort(vector<int> &arr, int low, int high)
{
    if (low >= high)
    {
        return;
    }

    int mid = low + (high - low) / 2;
    mergesort(arr, low, mid);
    mergesort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}

// Quick Sort

int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[low];
    int start = low + 1;
    int end = high;
    while (start <= end)
    {
        while (start <= high && arr[start] <= pivot)
        {
            start++;
        }

        while (end >= low && arr[end] > pivot)
        {
            end--;
        }

        if (start < end)
        {
            swap(arr[start], arr[end]);
        }
    }

    // swap the pivot at start and end idx so that pivot is at its correct position
    swap(arr[low], arr[end]);
    return end;
}

void quicksort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pivotIdx = partition(arr, low, high);
        quicksort(arr, low, pivotIdx - 1);
        quicksort(arr, pivotIdx + 1, high);
    }
}

// Recursive Bubble Sort
void RecursiveBubbleSort(vector<int> &arr, int n)
{
    if (n <= 1)
    {
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            swap(arr[i], arr[i + 1]);
        }
    }
    RecursiveBubbleSort(arr, n - 1);
}

// Recursive Insertion Sort
void RecursiveInsertionSort(vector<int> &arr, int n)
{
    if (n <= 1)
    {
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            swap(arr[i], arr[i + 1]);
        }
    }
    RecursiveBubbleSort(arr, n - 1);
}

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

    return (secondMax == INT_MIN) ? -1 : secondMax;
}

// Check if Array Is Sorted and Rotated
bool check(vector<int> &nums)
{
    int n = nums.size();
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        count += nums[i] > (nums[(i + 1) % n]);
    }
    return count <= 1;
}

// Remove Duplicates from Sorted Array
int removeDuplicates(vector<int> &nums)
{
    set<int> unique_values(nums.begin(), nums.end());
    nums.assign(unique_values.begin(), unique_values.end());
    return unique_values.size();
}

// Left Rotate Array by one times
void rotateone(vector<int> &nums)
{
    int n = nums.size();

    for (int i = 1; i < n; i++)
    {
        int firstVal = nums[0];
        for (int j = 1; j < n; j++)
        {
            nums[j - 1] = nums[j];
        }
        nums[n - 1] = firstVal;
    }
}

// Left Rotate Array by k times
void rotate(vector<int> &nums, int k)
{
    int n = nums.size();
    k = k % n;

    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end());
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

// Linear Search
int searchInSorted(vector<int> &arr, int N, int K)
{
    for (int i = 0; i < N; i++)
    {
        if (arr[i] == K)
        {
            return i;
        }
    }
    return -1;
}

// Union of Two Sorted Arrays

vector<int> findUnion(vector<int> &arr1, vector<int> &arr2)
{
    int n = arr1.size();
    int m = arr2.size();
    map<int, int> mpp;
    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
        mpp[arr1[i]]++;
    }
    for (int j = 0; j < m; j++)
    {
        mpp[arr1[j]]++;
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
    int totsum = n * (n + 1) / 2;
    for (int i = 0; i < n; i++)
    {
        totsum -= nums[i];
    }
    return totsum;
}

// Max Consecutive Ones
int findMaxConsecutiveOnes(vector<int> &nums)
{
    int n = nums.size();
    int maxVal = 0, count = 0;

    for (int i = 0; i < n; i++)
    {
        if (nums[i] == 1)
        {
            count++;
        }
        else
        {
            maxVal = max(count, maxVal);
            count = 0;
        }
    }
    maxVal = max(count, maxVal);
    return maxVal;
}

// Single Number
int singleNumber(vector<int> &nums)
{
    int n = nums.size();
    map<int, int> mpp;

    for (int i = 0; i < n; i++)
    {
        {
            mpp[nums[i]]++;
        }
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

// Longest subarray with given sum K(positives)
int lenOfLongSubarr(int A[], int N, int K)
{
    int maxLen = INT_MIN;
    for (int i = 0; i < N; i++)
    {
        int sum = 0;
        for (int j = i; j < N; j++)
        {
            sum += A[j];
            if (sum == K)
            {
                maxLen = max(maxLen, j - i + 1);
            }
        }
    }
    return maxLen;
}

// Longest subarray with sum K (Positives + Negatives)

int lenOfLongSubarrpn(int A[], int N, int K)
{
    map<int, int> mpp;
    int sum = 0;
    int maxLen = 0;

    for (int i = 0; i < N; i++)
    {
        sum += A[i];
        if (sum == K)
        {
            maxLen = i + 1;
        }

        if (mpp.find(sum - K) != mpp.end())
        {
            maxLen = max(maxLen, i - mpp[sum - K]);
        }

        if (mpp.find(sum) == mpp.end())
        {
            mpp[sum] = i;
        }
    }
    return maxLen;
}

// ************************* ARRAY MEDIUM ***************************

// Two Sum
vector<int> twoSum(vector<int> &nums, int target)
{
    unordered_map<int, int> mpp;
    vector<int> ans;
    int n = nums.size();

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
}

// Sort Colors
void sortColors(vector<int> &nums)
{
    int n = nums.size();
    int count0 = 0;
    int count1 = 0;
    int count2 = 0;

    for (int i = 0; i < n; i++)
    {
        if (nums[i] == 0)
        {
            count0++;
        }
        else if (nums[i] == 1)
        {
            count1++;
        }
        else
        {
            count2++;
        }
    }

    for (int i = 0; i < count0; i++)
    {
        nums[i] = 0;
    }

    for (int i = count0; i < count0 + count1; i++)
    {
        nums[i] = 1;
    }

    for (int i = count0 + count1; i < n; i++)
    {
        nums[i] = 2;
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

//  Maximum Subarray
int maxSubArray1(vector<int> &nums)
{
    int n = nums.size();
    int sum = 0;
    int maxVal = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        sum += nums[i];
        maxVal = max(maxVal, sum);
        if (sum < 0)
        {
            sum = 0;
        }
    }
    return maxVal;
}

// Print subarray with maximum subarray sum (extended version of above problem)
int maxSubArray(vector<int> &nums)
{
    int n = nums.size();
    int maxSum = nums[0];
    int currentSum = nums[0];

    for (int i = 1; i < n; i++)
    {
        currentSum = max(nums[i], currentSum + nums[i]);
        maxSum = max(maxSum, currentSum);
    }
    return maxSum;
}

// Maximum Score from Subarray Minimums
int pairWithMaxSum(vector<int> &arr)
{
    int n = arr.size();
    int maxScore = INT_MIN;

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
    vector<int> positive;
    vector<int> negative;
    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
        if (nums[i] > 0)
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

    while (i >= 0 && nums[i] >= nums[i + 1])
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
vector<int> leaders(int n, int arr[])
{
    vector<int> ans;
    int maxfromRight = arr[n - 1];

    for (int i = n - 1; i >= 0; i--)
    {
        if (arr[i] >= maxfromRight)
        {
            ans.push_back(arr[i]);
            maxfromRight = arr[i];
        }
    }
    reverse(ans.begin(), ans.end()); // Reverse to get the correct order
    return ans;
}

// Subarray Sum Equals K
int subarraySum(vector<int> &nums, int k)
{
    int n = nums.size();
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += nums[j];
            if (sum == k)
            {
                count++;
            }
        }
    }
}

// Longest Consecutive Sequence in an Array
int longestConsecutive(vector<int> &nums)
{
    if (nums.empty())
        return 0;

    unordered_set<int> st(nums.begin(), nums.end());
    int longestCount = 0;

    for (int num : st)
    {
        if (st.find(num - 1) == st.end())
        {
            int currNum = num;
            int currCount = 1;

            while (st.find(currNum + 1) != st.end())
            {
                currNum++;
                currCount++;
            }
            longestCount = max(longestCount, currCount);
        }
    }
    return longestCount;
}

// Set Matrix Zeroes
// Mark the entire row 'i' with -1 (except already 0 elements)
void MarkRow(vector<vector<int>> &matrix, int i, int m, int n)
{
    for (int j = 0; j < m; j++)
    {
        if (matrix[i][j] != 0)
        {
            matrix[i][j] = -1;
        }
    }
}

// Mark the entire column 'j' with -1 (except already 0 elements)
void MarkCol(vector<vector<int>> &matrix, int j, int m, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (matrix[i][j] != 0)
        {
            matrix[i][j] = -1;
        }
    }
}

// Main function to set matrix zeroes
void setZeroes(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();

    // First pass: mark rows and columns
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                MarkRow(matrix, i, m, n);
                MarkCol(matrix, j, m, n);
            }
        }
    }

    // Second pass: set all marked (-1) elements to 0
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == -1)
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

// Spiral Matrix || m -> rows, n -> columns
vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    int top = 0;
    int left = 0;
    int right = m - 1;
    int bottom = n - 1;
    vector<int> ans;

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
    vector<vector<int>> trainagle;

    for (int i = 0; i < numRows; i++)
    {
        vector<int> row(i + 1, 1);

        for (int j = 1; j < i; j++)
        {
            row[j] = trainagle[i - 1][j] + trainagle[i - 1][j - 1];
        }
        trainagle.push_back(row);
    }
    return trainagle;
}

// Majority Element II
vector<int> majorityElement1(vector<int> &nums)
{
    int n = nums.size();
    map<int, int> mpp;
    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
        mpp[nums[i]]++;
    }

    for (auto it : mpp)
    {
        if (it.second > (n / 3))
        {
            ans.push_back(it.first);
        }
    }
    return ans;
}

// Three Sum
vector<vector<int>> threeSum1(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> tripletValues;
    set<vector<int>> st;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (nums[i] + nums[j] + nums[k] == 0)
                {
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
            }
        }
    }

    for (auto it : st)
    {
        tripletValues.push_back(it);
    }
    return tripletValues;
}

// Three Sum --> Optimized
vector<vector<int>> threeSum(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());

    for (int i = 0; i < n; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
        {
            continue;
        }
        int j = i + 1;
        int k = n - 1;

        while (j < k)
        {
            int sum = nums[i] + nums[j] + nums[k];
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
                vector<int> currval = {nums[i], nums[j], nums[k]};
                ans.push_back(currval);
                j++;
                k--;

                // Skip duplicate elements for `j` and `k`
                while (j < k && nums[j] == nums[j - 1])
                {
                    j++;
                }
                while (j < k && nums[k] == nums[k + 1])
                {
                    k--;
                }
            }
        }
    }
    return ans;
}

// Largest subarray with 0 sum
int maxLen1(vector<int> &arr, int n)
{
    int maxLen = 0;

    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            if (sum == 0)
            {
                maxLen = max(maxLen, j - i + 1);
            }
        }
    }
    return maxLen;
}

int maxLen(vector<int> &arr, int n)
{
    int maxLen = 0;
    int sum = 0;
    unordered_map<int, int> mpp;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];

        if (sum == 0)
        {
            maxLen = i + 1;
        }

        else if (mpp.find(sum) != mpp.end())
        {
            maxLen = max(maxLen, i - mpp[sum]);
        }

        else
        {
            mpp[sum] = i;
        }
    }
    return maxLen;
}

// Count number of subarrays with given xor K
int subarraysXORwithK1(vector<int> &A, int n1, int k)
{
    int count = 0;
    int n = A.size();

    for (int i = 0; i < n; i++)
    {
        int XOR = 0;
        for (int j = i; j < n; j++)
        {
            XOR ^= A[j];
            if (XOR == k)
            {
                count++;
            }
        }
    }
    return count;
}

int subarraysXORwithK(vector<int> &A, int n1, int k)
{
    int count = 0;
    int n = A.size();
    int xr = 0;
    unordered_map<int, int> mpp;
    mpp[xr]++; // {0,1}

    for (int i = 0; i < n; i++)
    {
        xr ^= A[i];

        int x = xr ^ k;
        count += mpp[x];

        mpp[xr]++;
    }
    return count;
}

// Merge Intervals
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

// Merge Sorted Array
void merge1(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int top = m - 1;
    int bottom = 0;

    while (top >= 0 && bottom < m)
    {
        if (nums1[top] > nums1[bottom])
        {
            swap(nums1[top], nums2[bottom]);
        }
        else
        {
            break;
        }
    }

    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
}

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int i = m - 1;
    int j = n - 1;
    int k = m + n - 1;

    while (i >= 0 && j >= 0)
    {
        if (nums1[i] > nums2[j])
        {
            nums1[k] = nums1[i];
            i--;
        }
        else
        {
            nums1[k] = nums2[j];
            j--;
        }
        k--;
    }

    while (j >= 0)
    {
        nums1[k] = nums2[j];
        j--;
        k--;
    }
}

// 4Sum
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
                    quadruplets.push_back({arr[i], arr[j], arr[k], arr[l]});
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

// Missing And Repeating
vector<int> findTwoElement(vector<int> &arr)
{
    int n = arr.size();
    long long X = 0;
    long long X2 = 0;
    long long Y = (n * (n + 1)) / 2;
    long long Y2 = (n * (n + 1) * (2 * n + 1)) / 6;

    for (int i = 0; i < n; i++)
    {
        X += arr[i];
        X2 += (long long)arr[i] * arr[i];
    }

    long long val1 = X - Y;
    long long val2 = X2 - Y2;
    val2 /= val1;

    int repeat = (val1 + val2) / 2;
    int missing = repeat - val1;

    return {repeat, missing};
}

// Reverse Pairs
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

void mergevalues(vector<int> &arr, int low, int mid, int high)
{
    vector<int> temp(high - low + 1);
    int left = low;
    int right = mid + 1;
    int k = 0;

    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp[k++] = arr[left++];
        }
        else
        {
            temp[k++] = arr[right++];
        }
    }

    while (left <= mid)
    {
        temp[k++] = arr[left++];
    }

    while (right <= high)
    {
        temp[k++] = arr[right++];
    }

    for (int i = 0; i < temp.size(); i++)
    {
        arr[low + i] = temp[i];
    }
}

void mergeSort(vector<int> &arr, int low, int high, int &count)
{
    if (low >= high)
    {
        return;
    }

    int mid = (low + high) / 2;
    mergeSort(arr, low, mid, count);
    mergeSort(arr, mid + 1, high, count);
    countPairs(arr, low, mid, high, count);
    mergevalues(arr, low, mid, high);
}

int reversePairs(vector<int> &nums)
{
    int n = nums.size();
    int count = 0;
    mergeSort(nums, 0, n - 1, count);
    return count;
}
// maximum Product Subarray
int maxProduct(vector<int> &nums)
{
    int n = nums.size();
    int maxProd = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        int currProd = 1;
        for (int j = i; j < n; j++)
        {
            currProd *= nums[j];
            maxProd = max(maxProd, currProd);
        }
    }
    return maxProd;
}

int main()
{
    // vector<int> arr = {-5, 8, -14, 2, 4, 12};
    // cout << "Before Sorting" << endl;
    // for (auto it : arr)
    // {
    //     cout << it << " ";
    // }
    // cout << endl;

    // selectionSort(arr);
    // cout << "After Sorting" << endl;
    // for (auto it : arr)
    // {
    //     cout << it << " ";
    // }

    // BubbleSort(arr);
    // cout << "After Sorting" << endl;
    // for (auto it : arr)
    // {
    //     cout << it << " ";
    // }

    // InsertionSort(arr);
    // cout << "After Sorting" << endl;
    // for (auto it : arr)
    // {
    //     cout << it << " ";
    // }

    // mergesort(arr, 0, arr.size() - 1);
    // cout << "After Sorting" << endl;
    // for (auto it : arr)
    // {
    //     cout << it << " ";
    // }

    // quicksort(arr, 0, arr.size() - 1);
    // cout << "After Sorting" << endl;
    // for (auto it : arr)
    // {
    //     cout << it << " ";
    // }

    // RecursiveBubbleSort(arr, arr.size());
    // cout << "After Sorting" << endl;
    // for (auto it : arr)
    // {
    //     cout << it << " ";
    // }

    // RecursiveInsertionSort(arr, arr.size());
    // cout << "After Sorting" << endl;
    // for (auto it : arr)
    // {
    //     cout << it << " ";
    // }

    // cout << "Max Val: " << largest(arr) << endl;
    // cout << "second Max Val: " << print2largest(arr) << endl;
    // cout << "Is array sorted and rotated: " << (check(arr) ? "true" : "false") << endl;
    // cout << "Remove Duplicates: " << removeDuplicates(arr) << endl;

    // rotate(arr, 3);
    // cout << "After Rotating" << endl;
    // for (auto it : arr)
    // {
    //     cout << it << " ";
    // }

    // moveZeroes(arr);
    // cout << "After Moving Zeroes" << endl;
    // for (auto it : arr)
    // {
    //     cout << it << " ";
    // }

    // int ans = searchInSorted(arr, arr.size(), 3);
    // cout << "Element found at index: " << ans << endl;

    // vector<int> arr1 = {1, 2, 3, 4, 5};
    // vector<int> arr2 = {1, 2, 3, 6, 7};

    // vector<int> ans = findUnion(arr1, arr2);
    // cout << "Union of two sorted arrays: " << endl;
    // for (auto it : ans)
    // {
    //     cout << it << " ";
    // }

    // int ans = missingNumber(arr);
    // cout << "Missing Number: " << ans << endl;

    // int ans2 = findMaxConsecutiveOnes(arr);
    // cout << "Max Consecutive Ones: " << ans2 << endl;

    // int ans = singleNumber(arr);
    // cout << "Single Number: " << ans << endl;

    // int A[] = {-5, 8, -14, 2, 4, 2};
    // int N = 6;
    // int K = 6;
    // int ans = lenOfLongSubarr(A, N, K);
    // cout << "Length of longest subarray: " << ans << endl;
    // int ans1 = lenOfLongSubarrpn(A, N, K);
    // cout << "Length of longest subarray: " << ans1 << endl;

    // vector<int> nums = {2, 7, 11, 15};
    // int target = 9;
    // vector<int> ans = twoSum(nums, target);
    // cout << "Two Sum: " << endl;
    // for (auto it : ans)
    // {
    //     cout << it << " ";
    // }

    // vector<int> nums = {2, 0, 2, 1, 1, 0};
    // sortColors(nums);
    // cout << "After Sorting" << endl;
    // for (auto it : nums)
    // {
    //     cout << it << " ";
    // }

    // vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
    // int ans = majorityE3lement(nums);
    // cout << "Majority Element: " << ans << endl;

    // vector<int> nums = {5, 4, -1, 7, 8};
    // int ans = maxSubArray(nums);
    // cout << "Maximum Subarray: " << ans << endl;

    // vector<int> arr = {4, 3, 1, 5, 6};
    // int ans = pairWithMaxSum(arr);
    // cout << "Pair with Maximum Sum: " << ans << endl;

    // vector<int> prices = {7, 6, 4, 3, 1};
    // int ans = maxProfit(prices);
    // cout << "Maximum Profit: " << ans << endl;

    // vector<int> nums = {3, 2, 1};
    // vector<int> ans = rearrangeArray(nums);
    // cout << "Rearranged Array: ";
    // for (auto it : ans)
    // {
    //     cout << it << " ";
    // }

    // nextPermutation(nums);
    // cout << "Next Permutation: ";
    // for (auto it : nums)
    // {
    //     cout << it << " ";
    // }

    // vector<int> arr = {1, 2, 3};
    // cout << "Leaders in an array: " << subarraySum(arr, 3) << endl;

    // vector<int> nums = {100, 4, 200, 1, 3, 2};
    // int ans = longestConsecutive(nums);
    // cout << "Longest Consecutive Sequence: " << ans << endl;

    // vector<vector<int>> matrix = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
    // setZeroes(matrix);
    // cout << "Matrix after setting zeroes: " << endl;
    // for (auto it : matrix)
    // {
    //     for (auto jt : it)
    //     {
    //         cout << jt << " ";
    //     }
    //     cout << endl;
    // }

    // vector<vector<int>> matrix = {{5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}};
    // rotate(matrix);
    // cout << "Matrix after rotating: " << endl;
    // for (auto it : matrix)
    // {
    //     for (auto jt : it)
    //     {
    //         cout << jt << " ";
    //     }
    //     cout << endl;
    // }

    // vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    // vector<int> ans = spiralOrder(matrix);
    // cout << "Spiral Order: ";
    // for (auto it : ans)
    // {
    //     cout << it << " ";
    // }

    // int numRows = 5;
    // vector<vector<int>> ans = generate(numRows);
    // cout << "Pascal's Triangle: " << endl;
    // for (auto it : ans)
    // {
    //     for (auto jt : it)
    //     {
    //         cout << jt << " ";
    //     }
    //     cout << endl;
    // }

    // vector<int> nums = {1, 2};
    // vector<int> ans = majorityElement1(nums);
    // cout << "Majority Element II: ";
    // for (auto it : ans)
    // {
    //     cout << it << " ";
    // }

    // vector<int> nums = {-1, 0, 1, 2, -1, -4};
    // vector<vector<int>> ans = threeSum(nums);

    // cout << "Three Sum: " << endl;
    // for (auto it : ans)
    // {
    //     for (auto jt : it)
    //     {
    //         cout << jt << " ";
    //     }
    //     cout << endl;
    // }

    // vector<int> arr = {15, -2, 2, -8, 1, 7, 10, 23};
    // int n = arr.size();
    // int ans = maxLen(arr, n);
    // cout << "Largest subarray with 0 sum: " << ans << endl;

    // vector<int> A = {5, 6, 7, 8, 9};
    // int B = 6;
    // int ans = subarraysXORwithK(A, A.size(), B);
    // cout << "Count number of subarrays with given xor K: " << ans << endl;

    // vector<vector<int>> arr = {{1, 4}, {4, 5}};
    // vector<vector<int>> ans = mergeOverlappingIntervals(arr);
    // cout << "Merge Intervals: " << endl;
    // for (auto it : ans)
    // {
    //     for (auto jt : it)
    //     {
    //         cout << jt << " ";
    //     }
    //     cout << endl;
    // }

    // vector<int> nums1 = {1, 2, 3, 8, 0, 0, 0};
    // vector<int> nums2 = {2, 5, 6};

    // int m = 4;
    // int n = nums2.size();
    // // Call the merge function
    // merge(nums1, m, nums2, n);

    // // Print the merged array
    // cout << "Merged Array: ";
    // for (int num : nums1)
    // {
    //     cout << num << " ";
    // }
    // cout << endl;

    // vector<int> nums = {1, 0, -1, 0, -2, 2};
    // int target = 0; // Fixed target to match the possible sum from nums
    // vector<vector<int>> ans = fourSum(nums, target);

    // // Print the result
    // cout << "Four Sum: " << endl;
    // if (ans.empty())
    // {
    //     cout << "No quadruplets found." << endl;
    // }
    // else
    // {
    //     for (const auto &quadruplet : ans)
    //     {
    //         for (int num : quadruplet)
    //         {
    //             cout << num << " ";
    //         }
    //         cout << endl;
    //     }
    // }

    // vector<int> nums = {2, 3, -2, 4};
    // int ans = maxProduct(nums);
    // cout << "Maximum Product Subarray: " << ans << endl;

    // vector<int> nums = {2, 2};
    // vector<int> ans = findTwoElement(nums);
    // cout << "Missing and Repeating: ";
    // for (auto it : ans)
    // {
    //     cout << it << " ";
    // }

    vector<int> nums = {1, 3, 2, 3, 1};
    cout << "Number of reverse pairs: " << reversePairs(nums) << endl;

    return 0;
}