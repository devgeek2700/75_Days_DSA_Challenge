#include <bits/stdc++.h>
using namespace std;

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

int main()
{
    vector<int> arr = {-5, 8, -14, 2, 4, 12};
    cout << "Before Sorting" << endl;
    for (auto it : arr)
    {
        cout << it << " ";
    }
    cout << endl;

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

    int A[] = {-5,8,-14,2,4,2};
    int N = 6;
    int K = 6;
    int ans = lenOfLongSubarr(A, N, K);
    cout << "Length of longest subarray: " << ans << endl;
    int ans1 = lenOfLongSubarrpn(A, N, K);
    cout << "Length of longest subarray: " << ans1 << endl;

    return 0;
}