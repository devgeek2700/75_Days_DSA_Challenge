#include <bits/stdc++.h>
using namespace std;

// **************************************** SORTING EASY *************************

// selection sort --> finds smallest in all the array and then swap it with the current position
void printSelectionSort(int n, int arr[]) //  TC --> O(n^2)
{
    for (int i = 0; i < n; i++)
    {
        int minval = i;
        for (int j = i; j < n; j++)
        {
            if (arr[j] < arr[minval])
            {
                minval = j;
            }
        }
        swap(arr[minval], arr[i]);
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}

// Bubble sort
void printBubbleSort(int n, int arr[]) //  TC --> O(n^2)
{
    for (int i = 0; i < n - 1; i++)
    {
        bool didSwap = false;
        for (int j = 0; j < n - i - 1; j++) // Start from j = 0
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                didSwap = true;
            }
        }
        // print
        for (int k = 0; k < n; k++)
        {
            cout << arr[k] << " ";
        }
        cout << endl;

        if (!didSwap)
        {
            break;
        }
    }
}

// Insertion Sort
void printInsertionSort(int n, int arr[]) //  TC --> O(n^2)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j > 0; j--)
        {
            if (arr[j] < arr[j - 1])
            {
                swap(arr[j], arr[j - 1]);
            }
        }

        // print
        for (int k = 0; k < n; k++)
        {
            cout << arr[k] << " ";
        }
        cout << endl;
    }
}

// Merge Sort
void merge(int arr[], int low, int mid, int high) // TC --> O(nlogn) SC --> O(N)
{
    int left = low;
    int right = mid + 1;
    int temp[high - low + 1];
    int tmpidx = 0;

    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[high])
        {
            temp[tmpidx] = arr[left];
            left++;
        }
        else
        {
            temp[tmpidx] = arr[right];
            right++;
        }
        tmpidx++;
    }

    while (left <= mid)
    {
        temp[tmpidx] = arr[left];
        left++;
        tmpidx++;
    }

    while (right <= high)
    {
        temp[tmpidx] = arr[right];
        right++;
        tmpidx++;
    }

    for (int i = low, j = 0; i <= high; i++, j++)
    {
        arr[i] = temp[j];
    }
}

void printMergeSort(int arr[], int low, int high)
{
    if (low >= high)
    {
        return;
    }

    int mid = (low + high) / 2;
    printMergeSort(arr, low, mid);
    printMergeSort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}

// Quick Sort

int quickSort(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low;
    int j = high;

    while (i <= j)
    {
        while (arr[i] <= pivot && i <= j)
        {
            i++;
        }

        while (arr[j] > pivot && i <= j)
        {
            j--;
        }
        if (i <= j)
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    swap(arr[low], arr[j]);
    return j;
}

void printQuickSort(int arr[], int low, int high) // TC --> O(N^2) SC --> O(N)
{
    if (low < high)
    {
        int partition = quickSort(arr, low, high);
        printQuickSort(arr, low, partition - 1);
        printQuickSort(arr, partition + 1, high);
    }
}

// **************************************** ARRAYS EASY *************************

// Largest
int largest(vector<int> &arr, int n) // TC --> O(N) SC --> O(1)
{
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

int print2largest(vector<int> &arr) // TC --> O(2*N) SC --> O(1)
{
    int n = arr.size();
    int first = INT_MIN;
    int second = INT_MIN;

    // Find the first maximum element
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > first)
        {
            first = arr[i];
        }
    }

    // Find the second maximum element that is distinct from the first maximum

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > second && arr[i] < first)
        {
            second = arr[i];
        }
    }

    if (second == INT_MIN)
    {
        return -1;
    }
    else
    {
        return second;
    }
}

// Check if Array Is Sorted and Rotated
bool check(vector<int> &nums) // TC --> O(N) SC --> O(1)
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

// Left Rotate an Array by One --> left rotation
void rotaterbyOne(vector<int> &nums)
{
    int n = nums.size();

    int firstVal = nums[0];

    for (int i = 1; i < n; i++)
    {
        nums[i - 1] = nums[i];
    }
    nums[n - 1] = firstVal;
}

// Rotate Array by k times --> left rotation
void rotater(vector<int> &nums, int k)
{
    int n = nums.size();
    if (n == 0 || n == 1 || k == 0)
        return;

    for (int i = 1; i <= k; i++)
    {
        int firstVal = nums[0];
        for (int j = 1; j < n; j++)
        {
            nums[j - 1] = nums[j];
        }
        nums[n - 1] = firstVal;
    }
}

// Rotate Array by one --> right rotation
void rotaterOne(vector<int> &nums)
{
    int n = nums.size();

    int lastVal = nums[n - 1];
    for (int i = n - 1; i >= 0; i--)
    {
        nums[i] = nums[i - 1];
    }
    nums[0] = lastVal;
}

// Rotate Array by k times --> Right rotation
void rotaterKtimes(vector<int> &nums, int k)
{
    int n = nums.size();
    if (n == 0 || n == 1 || k == 0)
        return;

    for (int i = 1; i <= k; i++)
    {
        int lastVal = nums[n - 1];
        for (int j = n; j >= 0; j--)
        {
            nums[j] = nums[j - 1];
        }
        nums[0] = lastVal;
    }
}

void rotaterKtimesMod(vector<int> &nums, int k)
{
    int n = nums.size();
    k = k % n;

    reverse(nums.begin(), nums.end());

    reverse(nums.begin(), nums.begin() + k);

    reverse(nums.begin() + k, nums.end());
}

// Move Zeroes
void moveZeroes(vector<int> &nums)
{
    int n = nums.size();
    int tempIdx = 0;

    if (n == 0)
    {
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (nums[i] != 0)
        {
            nums[tempIdx++] = nums[i];
        }
    }

    nums.resize(tempIdx);

    for (int i = tempIdx; i < n; i++)
    {
        nums.push_back(0);
    }
}

// Linear Search

int searchInSorted(int arr[], int N, int K) // TC --> O(N) SC --> O(1)
{
    if (N == 0)
    {
        return -1;
    }

    for (int i = 0; i < N; i++)
    {
        if (arr[i] == K)
        {
            return 1;
        }
    }
    return -1;
}

// Union of Two Sorted Arrays

vector<int> findUnion(int arr1[], int arr2[], int n, int m) // TC --> O((n+m)logn(n+m) SC --> O(n+m)
{
    map<int, int> mpp;
    vector<int> result;

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
        result.push_back(it.first);
    }
    return result;
}

// Missing Number
int missingNumber1(vector<int> &nums)
{
    sort(nums.begin(), nums.end());

    for (int i = 0; i <= nums.size(); i++)
    {
        if (nums[i] != i)
        {
            return i;
        }
    }
}
// Mtd-2
int missingNumber(vector<int> &nums)
{
    int n = nums.size();
    int tolSum = n * (n + 1) / 2;
    int actulSum = 0;
    for (int i = 0; i < n; i++)
    {
        actulSum += nums[i];
    }

    return tolSum - actulSum;
}

// Max Consecutive Ones
int findMaxConsecutiveOnes(vector<int> &nums)
{
    int n = nums.size();
    int count = 0;
    int maxVal = INT_MIN;
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
        mpp[nums[i]]++;
    }

    for (auto it : mpp)
    {
        if (it.second == 1)
        {
            return it.first;
        }
    }
}

// Longest Sub-Array with Sum K(positives)
int lenOfLongSubarr1(int A[], int N, int K)
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

int lenOfLongSubarr(int A[], int N, int K)
{
    int maxLen = 0;
    int left = 0;
    int right = 0;
    int sum = 0;

    while (right < N)
    {
        sum += A[right];

        while (left <= right && sum > K)
        {
            sum -= A[left];
            left++;
        }

        if (sum == K)
        {
            maxLen = max(maxLen, right - left + 1);
        }
        right++;
    }
    return maxLen;
}

// **************************************** ARRAYS EASY *************************
// Two Sum
vector<int> twoSum(vector<int> &nums, int target)
{
    unordered_map<int, int> mpp;
    vector<int> ans;
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        int complement = target - nums[i];
        if (mpp.find(complement) != mpp.end())
        {
            ans.push_back(mpp[complement]);
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
    sort(nums.begin(), nums.end());
}

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
        if (it.second > n / 2)
            return it.first;
    }
}

//  Maximum Subarray Sum
int maxSubarraySum(vector<int> arr, int n)
{
    int sum = 0;
    int maxVal = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        maxVal = max(maxVal, sum);
        if (sum < 0)
        {
            sum = 0;
        }
    }

    return maxVal;
}

int maxProfit(vector<int> &prices)
{
    int n = prices.size();

    if (prices.empty())
    {
        return 0;
    }

    int minPrice = prices[0];
    int maxProfit = 0;

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

// Subarray Sum Equals K
int subarraySum(vector<int> &nums, int k)
{
    int n = nums.size();
    int subcount = 0;

    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += nums[j];
            if (sum == k)
            {
                subcount++;
            }
        }
    }
    return subcount;
}

// Remove duplicates from Sorted Array
vector<int> removeDuplicatesg(vector<int> &nums)
{
    int n = nums.size();
    vector<int> ans;
    map<int, int> mpp;

    for(int i = 0; i<n; i++){
        mpp[nums[i]]++;
    }

    for(const auto &pair : mpp){
        if(pair.second == 1){
            ans.push_back(pair.first);
        }
    }
    return ans;
}

// **************************************** STRING EASY *************************

// sort the string --> lexicographically
string sortlexicographically(string str)
{
    int n = str.length();
    vector<int> freq(26, 0);

    for (int i = 0; i < n; i++)
    {
        freq[str[i] - 'a']++;
    }

    int j = 0;
    for (int i = 0; i < freq.size(); i++)
        while (freq[i]--)
        {
            str[j] = i + 'a';
            j++;
        }
    return str;
}

bool checkAnagram(string str, string t)
{
    int m = str.length();
    int n = t.length();
    map<char, int> freq;

    if (m != n)
    {
        return false;
    }

    for (char i = 0; i < m; i++)
    {
        freq[str[i]]++;
    }

    for (auto ch : t)
    {
        if (freq.find(ch) == freq.end())
        {
            return false;
        }
        freq[ch]--;
    }

    return true;
}

bool checkIsomorphic(string str, string t)
{
    int n = str.length();
    int m = t.length();
    vector<int> s1{128, -1};
    vector<int> s2{128, -1};

    for (int i = 0; i < n; i++)
    {
        if (s1[str[i]] != s2[t[i]])
        {
            return false;
        }
        s1[str[i]] = i;
        s2[t[i]] = i;
    }
    return true;
}

vector<string> reversestr(vector<string> s)
{
    reverse(s.begin(), s.end());
    return s;
}

string reverseWords(string s)
{
    int n = s.length();
    string ans = "";
    string finalans = "";

    for (int i = 0; i < n; i++)
    {
        if (s[i] != ' ')
        {
            ans = s[i];
        }
        else
        {
            if (!ans.empty())
            {
                reverse(ans.begin(), ans.end());
                if (!finalans.empty())
                {
                    finalans += ' ';
                }

                finalans += ans;
                ans = "";
            }
        }
    }
    if (!ans.empty())
    {
        reverse(ans.begin(), ans.end());
        if (!finalans.empty())
        {
            finalans += ' ';
        }

        finalans += ans;
        ans = "";
    }

    return finalans;
}

bool isplaindrome(string str)
{
    int n = str.length();
    int start = 0;
    int end = n - 1;

    while (start <= end)
    {
        if (str[start] == str[end])
        {
            start++;
            end--;
        }
        else
        {
            return false;
        }
    }
    return true;
}

/* Binary search */
int search(vector<int> &nums, int target)
{
    int n = nums.size();
    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (nums[mid] == target)
        {
            return mid;
        }
        else if (nums[mid] > target)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
}

int searchInsert(vector<int> &nums, int target)
{
    int n = nums.size();
    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (nums[mid] >= target)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return low;
}

int main()
{

    int arr[] = {10, 5, 2, 7, 1, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    // printSelectionSort(n, arr);

    // cout << "Bubble Sort" << endl;
    // printBubbleSort(n, arr);

    // cout << "Insertion Sort" << endl;
    // printInsertionSort(n, arr);

    // cout << "Merge Sort" << endl;
    // printMergeSort(arr, 0, n - 1);

    // for (int i = 0; i < n; i++)
    // {
    //     cout << arr[i] << " ";
    // }
    // cout << endl;

    // cout << "Quick Sort" << endl;
    // printQuickSort(arr, 0, n - 1);

    // for (int i = 0; i < n; i++)
    // {
    //     cout << arr[i] << " ";
    // }
    // cout << endl;

    // ****************** ARRAYS **********************
    // vector<int> varr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    // int k = 9;

    // cout << "Largest Element in Array: " << largest(varr, varr.size()) << endl;
    // cout << "Second Largest in Array: " << print2largest(varr) << endl;
    // cout << "Check if Array Is Sorted and Rotated: " << check(varr) << endl;
    // cout << "Remove Duplicates from Sorted Array: " << removeDuplicates(varr) << endl;
    // cout << "Remove Duplicates from Sorted Array by one: ";
    // rotatebyOne(varr);

    // for (int i = 0; i < varr.size(); i++)
    // {
    //     cout << varr[i] << " ";
    // }

    // rotaterKtimes(varr, k);
    // moveZeroes(varr);
    // cout << "Move Zeroes: ";

    // for (int i = 0; i < varr.size(); i++)
    // {
    //     cout << varr[i] << " ";
    // }

    // cout << "Sorted Array Search: " << searchInSorted(arr, n, k) << endl;

    // int arr1[] = {1, 1, 1, 1, 1};
    // int arr2[] = {2, 2, 2, 2, 2};
    // int n1 = sizeof(arr1) / sizeof(arr1[0]);
    // int m = sizeof(arr2) / sizeof(arr2[0]);

    // vector<int> unionArray = findUnion(arr1, arr2, n1, m);

    // for (int i = 0; i < unionArray.size(); i++)
    // {
    //     cout << unionArray[i] << " ";
    // }

    // cout << "Missing Number: " << missingNumber(varr) << endl;
    // cout << "Max Consecutive Ones: " << findMaxConsecutiveOnes(varr) << endl;
    // cout << "Single Number: " << singleNumber(varr) << endl;
    // cout << "Longest Sub-Array with Sum K: " << lenOfLongSubarr(arr, n, k) << endl;

    // cout << "Two Sum: ";
    // auto result = twoSum(varr, k);
    // for (int i = 0; i < result.size(); i++)
    // {
    //     cout << result[i] << " ";
    // }

    // cout << "Sort Colors: ";
    // sortColors(varr);
    // for (int i = 0; i < varr.size(); i++)
    // {
    //     cout << varr[i] << " ";
    // }

    // cout << "Majority Element: " << majorityElement(varr) << endl;
    // cout << "maxSubarraySum : " << maxSubarraySum(varr, varr.size()) << endl;

    string str = "mohm";
    string t = "atom";

    // cout << "string : " << str << endl;
    // cout << "t : " << t << endl;
    // auto result = sortlexicographically(str);
    // cout << "Sorted string: " << result << endl;

    // auto result = checkAnagram(str, t);
    // cout << "checkAnagram or not?: " << result << endl;

    // auto result = checkIsomorphic(str, t);
    // cout << "checkIsomorphic or not?: " << result << endl;

    // auto result = reverse(str);
    // cout << "reverseWords: " << result << endl;

    // vector<string> str = {"microscope", "microphone", "microbial"};

    // cout << "Original string: ";
    // for (int i = 0; i < str.size(); i++)
    // {
    //     cout << str[i] << " ";
    // }
    // cout << endl;

    // auto result = reverseWords(str);
    // cout << "Reverse Words in a String: " << result << endl;

    auto result = isplaindrome(str);
    cout << "isplaindrome or not?: " << result << endl;
    return 0;
}