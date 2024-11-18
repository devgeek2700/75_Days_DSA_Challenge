#include <bits/stdc++.h>
using namespace std;

// ************************* ARRAY EASY ***************************

// Largest Element in Array

int largest(vector<int> &arr)
{
    int maxVal = INT_MIN;
    for (int i = 0; i < arr.size(); i++)
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
    int firstMax = INT_MIN;
    int secondMax = INT_MIN;

    for (int i = 0; i < arr.size(); i++)
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
    for (int i = 0; i < arr.size(); i++)
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
    int count = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        count += nums[i] > nums[(i + 1) % nums.size()];
    }
    return count <= 1;
}

// Remove Duplicates from Sorted Array
int removeDuplicates(vector<int> &nums)
{
    set<int> uniq_val(nums.begin(), nums.end());
    nums.assign(uniq_val.begin(), uniq_val.end());
    return uniq_val.size();
}

// Rotate Array to right by k times
void rotate(vector<int> &nums, int k)
{
    k = k % nums.size();

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

// Sorted Array Search
bool searchInSorted(vector<int> arr, int k)
{
    for (int i = 0; i < arr.size(); i++)
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
        mpp[a[i]] = 1;
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
    int maxCount = INT_MIN;
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if (nums[i] == 1)
        {
            count++;
        }
        else
        {
            maxCount = max(maxCount, count);
            count = 0;
        }
    }
    maxCount = max(maxCount, count);
    return maxCount;
}

// Single Number
int singleNumber(vector<int> &nums)
{
    int ans = 0;
    map<int, int> mpp;
    for (int i = 0; i < nums.size(); i++)
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

// // Longest subarray with sum K (Positives + Negatives)

int lenOfLongestSubarr(vector<int> &arr, int k)
{
    int n = arr.size();
    map<int, int> mpp;
    int maxLen = 0;
    int curSum = 0;

    for (int i = 0; i < n; i++)
    {
        curSum += arr[i];

        if (curSum == k)
        {
            maxLen = i + 1;
        }
        // Check if the difference (currSum - k) exists in the hash map:
        // If it exists, it means there's a subarray with sum k, and its length is i - mp[currSum - k].
        if (mpp.find(curSum - k) != mpp.end())
        {
            maxLen = max(maxLen, i - mpp[curSum - k]);
        }

        // If currSum is not in the hash map, store it with the current index.
        if (mpp.find(curSum) == mpp.end())
        {
            mpp[curSum] = i;
        }
    }
    return maxLen;
}

int main()
{
    vector<int> arr;
    int n, m, mum, num;

    cout << "Enter the number of elements1: ";
    cin >> n;
    // cout << "Enter the number of elements2: ";
    // cin >> m;

    cout << "Enter the elements1: ";
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        arr.push_back(num);
    }

    // cout << "Enter the elements2: ";
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> mum;
    //     arr.push_back(mum);
    // }

    // cout << "The largest element in the array is: " << largest(arr) << endl;
    // cout << "The second largest element in the array is: " << print2largest(arr) << endl;
    // cout << "The array is sorted: " << arraySortedOrNot(arr, n) << endl;
    // cout << "The array is sorted and rotated: " << check(arr) << endl;
    // cout << "The number of unique elements in the array is: " << removeDuplicates(arr) << endl;
    // rotate(arr, 3);
    // cout << "The array after rotating to right by k times is: ";
    // for (int i = 0; i < arr.size(); i++)
    // {
    //     cout << arr[i] << " ";
    // }

    // moveZeroes(arr);
    // cout << "The array after moving zeroes to end is: ";
    // for (int i = 0; i < arr.size(); i++)
    // {
    //     cout << arr[i] << " ";
    // }
    // cout << "The element is present in the array: " << searchInSorted(arr, 3) << endl;
    // vector<int> ans = findUnion(arr, arr);
    // cout << "The union of two sorted arrays is: ";
    // for (int i = 0; i < ans.size(); i++)
    // {
    //     cout << ans[i] << " ";
    // }
    // cout << "The missing number in the array is: " << missingNumber(arr) << endl;
    // cout << "The maximum number of consecutive ones in the array is: " << findMaxConsecutiveOnes(arr) << endl;
    // cout << "The single number in the array is: " << singleNumber(arr) << endl;
    // cout << "The length of the longest sub-array with sum K is: " << lenOfLongestSubarr(arr, 3) << endl;
    cout << "The length of the longest sub-array with sum K is: " << lenOfLongestSubarr(arr, 15) << endl;

    return 0;
}
