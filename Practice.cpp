#include <bits/stdc++.h>
using namespace std;

// selection sort --> finds smallest in all the array and then swap it with the current position

void selectionSort(vector<int> &varr)
{
    int n = varr.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (varr[i] > varr[j])
            {
                swap(varr[i], varr[j]);
            }
        }
    }
}

// Bubble sort
void BubbleSort(vector<int> &varr)
{
    int n = varr.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (varr[j] > varr[j + 1])
            {
                swap(varr[j], varr[j + 1]);
            }
        }
    }
}

// Insertion Sort
void InsertionSort(vector<int> &varr)
{
    int n = varr.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j > 0; j--)
        {
            if (varr[j] < varr[j - 1])
            {
                swap(varr[j], varr[j - 1]);
            }
        }
    }
}

// Merge Sort

void merge(vector<int> &varr, int low, int mid, int high)
{
    int left = low;
    int right = mid + 1;
    int tmpIdx = 0;
    vector<int> temp(high - low + 1);

    while (left <= mid && right <= high)
    {
        if (varr[left] <= varr[right])
        {
            temp[tmpIdx++] = varr[left++];
        }
        else
        {
            temp[tmpIdx++] = varr[right++];
        }
    }

    while (left <= mid)
    {
        temp[tmpIdx++] = varr[left++];
    }

    while (right <= high)
    {
        temp[tmpIdx++] = varr[right++];
    }

    for (int i = low, j = 0; i <= high; i++, j++)
    {
        varr[i] = temp[j];
    }
}

void mergeSort(vector<int> &varr, int low, int high)
{
    if (low < high)
    {
        int mid = low + (high - low) / 2;
        mergeSort(varr, low, mid);
        mergeSort(varr, mid + 1, high);
        merge(varr, low, mid, high);
    }
}

// Quick Sort
int partition(vector<int> &varr, int low, int high)
{
    int pivot = varr[low];
    int i = low + 1;
    int j = high;

    while (i <= j)
    {
        while (i <= high && varr[i] <= pivot)
        {
            i++;
        }

        while (varr[j] > pivot && j >= low)
        {
            j--;
        }

        if (i < j)
        {
            swap(varr[i], varr[j]);
        }
    }

    swap(varr[low], varr[j]);
    return j;
}

void quicksort(vector<int> &varr, int low, int high)
{
    if (low < high)
    {
        int pivotIndex = partition(varr, low, high);
        quicksort(varr, low, pivotIndex - 1);
        quicksort(varr, pivotIndex + 1, high);
    }
}

// Largest Element in Array
int largest(vector<int> &arr)
{
    int n = arr.size();
    if (n == 1)
    {
        return arr[0];
    }

    int maxVal = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > maxVal)
        {
            maxVal = max(maxVal, arr[i]);
        }
    }
    return maxVal;
}

// Second Largest
int print2largest(vector<int> &arr)
{
    int n = arr.size();

    int first = INT_MIN;
    int second = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > first)
        {
            second = first;
            first = arr[i];
        }
        else if (arr[i] > second && arr[i] != first)
        {
            second = arr[i];
        }
    }

    return (second == INT_MIN) ? -1 : second;
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
int removeDuplicates(vector<int> &nums) // TC --> O(nlogn) SC --> O(n)
{
    set<int> unique_values(nums.begin(), nums.end());
    nums.assign(unique_values.begin(), unique_values.end());
    return unique_values.size();
}

// left Rotate Array by one times
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

// left Rotate Array by k times
void rotate(vector<int> &nums, int k)
{
    int n = nums.size();
    k = k % n;

    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end());
}

//  Move Zeroes at end
void moveZeroes(vector<int> &nums)
{
    int n = nums.size();
    int nonZeroIndex = 0;

    for (int i = 0; i < n; i++)
    {
        if (nums[i] != 0)
        {
            nums[nonZeroIndex++] = nums[i];
        }
    }

    for (int i = nonZeroIndex; i < n; i++)
    {
        nums[i] = 0;
    }
}

// Sorted Array Search
int searchInSorted(int arr[], int N, int K)
{
    for (int i = 0; i < N; i++)
    {
        if (arr[i] == K)
        {
            return 1;
        }
    }
    return -1;
}

// 	Find the Union
vector<int> findUnion(int arr1[], int arr2[], int n, int m)
{
    map<int, int> mpp;
    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
        mpp[arr1[i]]++;
    }

    for (int i = 0; i < m; i++)
    {
        mpp[arr2[i]]++;
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
    int totalSum = (n * (n + 1)) / 2;
    int actualsum = 0;
    for (int i = 0; i < n; i++)
    {
        actualsum += nums[i];
    }
    return totalSum - actualsum;
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
    map<int, int> freq;

    for (int i = 0; i < n; i++)
    {
        freq[nums[i]]++;
    }

    for (auto it : freq)
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

    if (maxLen != INT_MIN)
    {
        return maxLen;
    }
    else
    {
        return 0;
    }
}

int lenOfLongSubarr1(int a[], int n, int k)
{
    int left = 0, right = 0;
    long long sum = a[0];
    int maxLen = 0;
    while (right < n)
    {
        while (left <= right && sum > k)
        {
            sum -= a[left];
            left++;
        }

        if (sum == k)
        {
            maxLen = max(maxLen, right - left + 1);
        }

        right++;
        if (right < n)
            sum += a[right];
    }

    return maxLen;
}

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

// Sort Colors 0's 1's and 2's
void sortColors(vector<int> &nums)
{
    int count0 = 0;
    int count1 = 0;
    int count2 = 0;
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        if (nums[i] == 0)
        {
            count0++; // 2
        }
        else if (nums[i] == 1)
        {
            count1++; // 2
        }
        else
        {
            count2++; // 2
        }
    }

    for (int i = 0; i < count0; i++)
    {
        nums[i] = 0; // 0->2
    }

    for (int i = count0; i < count0 + count1; i++)
    {
        nums[i] = 1; // 2->4
    }

    for (int i = count0 + count1; i < n; i++)
    {
        nums[i] = 2; // 4-> 6
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
        if (it.second > n / 2)
        {
            return it.first;
        }
    }
    return -1;
}

// Maximum Subarray
int maxSubArray(vector<int> &nums)
{
    int sum = 0;
    int maxVal = INT_MIN;
    int n = nums.size();

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

// Maximum Score from Subarray Minimums
int pairWithMaxSum(vector<int> &arr)
{
    int n = arr.size();
    int maxSum = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        int currSum = arr[i] + arr[i + 1];
        maxSum = max(maxSum, currSum);
    }
    return maxSum;
}

// Best Time to Buy and Sell Stock
int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    if (n == 0)
    {
        return 0;
    }

    int maxProfit = 0;
    int minPrice = prices[0];

    for (int i = 1; i < n; i++)
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

    // Separate positive and negative numbers
    for (int i = 0; i < n; i++)
    {
        if (nums[i] < 0)
        {
            negative.push_back(nums[i]);
        }
        else
        {
            positive.push_back(nums[i]);
        }
    }

    // Interleave positive and negative numbers
    int pn = positive.size();
    for (int i = 0; i < pn; i++)
    {
        ans.push_back(positive[i]);
        ans.push_back(negative[i]);
    }

    return ans;
}


int main()
{
    vector<int> varr = {1, 2, 3};
    int arr[] = {10, 5, 2, 7, 1, 9};
    int N = sizeof(arr) / sizeof(arr[0]);
    int k = 6;
    // vector<int> varr1 = {1, 2, 3, 6, 7};

    cout << "Printing the array: ";
    for (int i : varr)
    {
        cout << i << " ";
    }

    cout << endl;

    // selectionSort(varr);

    // cout << "Selection sorted array: ";
    // for (int i : varr)
    // {
    //     cout << i << " ";
    // }

    // BubbleSort(varr);

    // cout << "Bubble sorted array: ";
    // for (int i : varr)
    // {
    //     cout << i << " ";
    // }

    // InsertionSort(varr);

    // cout << "Insertion sorted array: ";
    // for (int i : varr)
    // {
    //     cout << i << " ";
    // }

    // mergeSort(varr, 0, varr.size());

    // cout << "Merge Sort sorted array: ";
    // for (int i : varr)
    // {
    //     cout << i << " ";
    // }

    // quicksort(varr, 0, varr.size());

    // cout << "quick Sort sorted array: ";
    // for (int i : varr)
    // {
    //     cout << i << " ";
    // }

    // cout << "array: " << largest(varr) << endl;
    // cout << "Second Largest: " << print2largest(varr) << endl;
    // cout << " Check if Array Is Sorted and Rotated: " << check(varr) << endl;

    // removeDuplicates(varr);
    // cout << "Remove Duplicates from Sorted Array: ";
    // for (int i : varr)
    // {
    //     cout << i << " ";
    // }

    // rotateone(varr);
    // cout << "Rotate Array by one: ";
    // for (int i : varr)
    // {
    //     cout << i << " ";
    // }

    // rotate(varr, 3);
    // cout << "Rotate Array by K times: ";
    // for (int i : varr)
    // {
    //     cout << i << " ";
    // }

    // moveZeroes(varr);
    // cout << "Move Zeroes: ";
    // for (int i : varr)
    // {
    //     cout << i << " ";
    // }

    // vector<int> unionArray = findUnion(arr1, arr2, n, m);
    // cout << "Union of the two arrays is: ";
    // for (int i = 0; i < unionArray.size(); i++)
    // {
    //     cout << unionArray[i] << " ";
    // }
    // cout << endl;

    // cout << "Missing Number: " << missingNumber(varr) << endl;
    // cout << "Max Consecutive Ones: " << findMaxConsecutiveOnes(varr) << endl;
    // cout << "Single Number: " << singleNumber(varr) << endl;
    // int result = lenOfLongSubarr(arr, N, k);
    // cout << "Longest Sub-Array with Sum " << k << " has length: " << result << endl;

    // vector<int> ansArray = twoSum(varr, k);
    // cout << "two sum is: ";
    // for (int i = 0; i < ansArray.size(); i++)
    // {
    //     cout << ansArray[i] << " ";
    // }
    // cout << endl;

    // sortColors(varr);
    // cout << "Sort Colors is: ";
    // for (int i = 0; i < varr.size(); i++)
    // {
    //     cout << varr[i] << " ";
    // }
    // cout << endl;

    // cout << "Majority Element: " << majorityElement(varr) << endl;
    // cout << "Maximum Score from Subarray Minimums: " << pairWithMaxSum(varr) << endl;
    // cout << "Best Time to Buy and Sell Stock: " << maxProfit(varr) << endl;

    // vector<int> rearrangeArrayAns = rearrangeArray(varr);

    // cout << "Rearranged array: ";
    // for (int i = 0; i < rearrangeArrayAns.size(); i++)
    // {
    //     cout << rearrangeArrayAns[i] << " ";
    // }
    // cout << endl;

    nextPermutation(varr);

    cout << "Next Permutation: ";
    for (int i = 0; i < varr.size(); i++)
    {
        cout << varr[i] << " ";
    }
    cout << endl;

    return 0;
}