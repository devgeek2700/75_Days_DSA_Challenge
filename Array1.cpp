#include <bits/stdc++.h>
using namespace std;

// 	Largest Element in an Array

int LargestElementArray(int arr[], int n)
{
    int maxval = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > maxval)
        {
            maxval = arr[i];
        }
    }
    return maxval;
}

//  Second Largest and Smallest Number in an Array

vector<int> getSecondOrderElements(int n, vector<int> a)
{
    vector<int> answer;

    sort(a.begin(), a.end());

    answer.push_back(a[n - 2]);
    answer.push_back(a[1]);

    return answer;
}

//  Check Sorted Array
int isSorted(int n, vector<int> a)
{
    for (int i = 1; i < n; i++)
    {
        if (a[i] < a[i - 1])
        {
            return false;
        }
    }
    return true;
}

//  Remove Duplicates from Sorted Array with extra space
// int removeDuplicates(vector<int> &arr, int n)
// {
//     vector<int> temp;
//     for(int i = 0; i < n; i++){
//         for(int j = 1; j < n; j++){
//             if(arr[i] == arr[j] && i != j){
//                 arr.erase(arr.begin() +1);
//                 j--;
//                 n--;
//             }
//         }
//         temp.push_back(arr[i]);
//     }
//     cout<<endl;
//     cout << "arr array: ";
//     for (auto it : temp)
//     {
//         cout << it << " ";
//     }

//     return temp.size();
// }

//  Remove Duplicates from Sorted Array with extra space
int removeDuplicates(vector<int> &arr, int n)
{
    int tempindex = 1;
    if (n == 0)
    {
        return 0;
    }

    for (int i = 1; i < n; i++)
    {
        if (arr[i] != arr[i - 1])
        {
            arr[tempindex++] = arr[i];
        }
    }

    arr.resize(tempindex);

    return tempindex;
}

//  Left Rotate an Array by One

vector<int> rotateArrayleft(vector<int> &arr, int n)
{
    if (n == 0 || n == 1)
        return arr;

    int firstVal = arr[0];

    for (int i = 1; i < n; i++)
    {
        arr[i - 1] = arr[i];
    }

    arr[n - 1] = firstVal;

    return arr;
}

//  Rotate array by k times

vector<int> rotateArraybyktimes(vector<int> arr, int k)
{
    int n = arr.size();
    if (n == 0 || n == 1 || k == 0)
        return arr;

    for (int i = 1; i <= k; i++)
    {
        int firstvalue = arr[0];
        for (int j = 1; j < n; j++)
        {
            arr[j - 1] = arr[j];
        }
        arr[n - 1] = firstvalue;

        cout << endl;
        cout << "arr array " << i << " times: ";
        for (auto it : arr)
        {
            cout << it << " ";
        }
    }

    return arr;
}

//  Move Zero's to End

vector<int> moveZeros(int n, vector<int> a)
{
    int tempidx = 0;
    if (n == 0 || n == 1)
        return a;

    for (int i = 0; i < n; i++)
    {
        if (a[i] != 0)
        {
            a[tempidx++] = a[i];
        }
    }

    a.resize(tempidx);

    for (int i = tempidx; i < n; i++)
    {
        a.push_back(0);
    }

    return a;
}

//  Linear Search

int linearSearch(int n, int num, vector<int> &arr)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == num)
        {
            return i;
        }
    }
    return -1;
}

//   Merge 2 Sorted Array

vector<int> sortedArrayMergetwoArray(vector<int> a, vector<int> b)
{
    vector<int> answerArr;
    int n = a.size();
    int m = b.size();

    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (a[i] < b[j])
        {
            answerArr.push_back(a[i]);
            i++;
        }
        if (b[j] < a[i])
        {
            answerArr.push_back(b[j]);
            j++;
        }
        if (a[i] == b[j])
        {
            answerArr.push_back(a[i]);
            i++;
            j++;
        }
    }

    while (i < n)
    {
        answerArr.push_back(a[i]);
        i++;
    }

    while (j < m)
    {
        answerArr.push_back(b[j]);
        j++;
    }

    sort(answerArr.begin(), answerArr.end());

    // check for duplicate elements

    answerArr.erase(unique(answerArr.begin(), answerArr.end()), answerArr.end());

    return answerArr;
}

// Missing Number in an Array

int missingNumber(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        if (nums[i] != i)
        {
            return i;
        }
    }
}

// Maximum consecutive one’s

int findMaxConsecutiveOnes(vector<int> &nums)
{
    int n = nums.size();
    int count = 0;
    int maxval = 0;

    for (int i = 0; i < n; i++)
    {
        if (nums[i] == 1)
        {
            count++;
        }
        else
        {
            maxval = max(maxval, count);
            count = 0;
        }
    }

    maxval = max(maxval, count);

    return maxval;
}

//  Find The Single Element

int getSingleElement(vector<int> &arr)
{
    map<int, int> map;
    // Store the values and their counts
    for (int it : arr)
    {
        map[it]++;
    }

    // Find the values with the count that is 1
    for (auto pair : map)
    {
        if (pair.second == 1)
        {
            return pair.first;
        }
    }
}

//  Longest Subarray With Sum K  --> Brute Approach

// int longestSubarrayWithSumK(vector<int> a, long long k)
// {
//     int maxlen = 0;
//     for (int i = 0; i < a.size(); i++)
//     {
//         int sum = 0;
//         for (int j = i; j < a.size(); j++)
//         {
//             sum += a[j];
//             if (sum == k)
//             {
//                 maxlen = max(maxlen, j - i + 1);
//             }
//         }
//     }
//     return maxlen;
// }

// Longest Subarray with given Sum K(Positives) --> Better Approach --> postivies, zeos, negatives

int longestSubarrayWithSumK(vector<int> nums, long long k) // TC --> O(n*logn) ord MAp , O(n*1) --> unordMap
{

    int maxlen = 0;
    int sum = nums[0];
    int right = 0;
    int left = 0;
    int n = nums.size();

    while (right < n)
    {
        while (left <= right && sum > k)
        {
            sum -= nums[left];
            left++;
        }
        if (sum == k)
        {
            maxlen = max(maxlen, right - left + 1);
        }
        right++;
        if (right < n)
        {
            sum += nums[right];
        }
    }
    return maxlen;
}

// Longest Subarray with sum K | [Postives and Negatives]
int getLongestSubarrayposandneg(vector<int> &a, int k)
{
    map<long long, int> prefSumMap;
    long long sum = 0;
    int maxlen = 0;
    for (int i = 0; i < a.size(); i++)
    {
        sum += a[i];
        if (sum == k)
        {
            maxlen = max(maxlen, i + 1);
        }
        long long rem = sum - k;
        if (prefSumMap.find(rem) != prefSumMap.end())
        {
            int len = i - prefSumMap[rem];
            maxlen = max(maxlen, len);
        }
        if (prefSumMap.find(sum) == prefSumMap.end())
        {
            prefSumMap[sum] = i;
        }
    }
    return maxlen;
}

//  Two Sum Array

string TwoSum(int n, vector<int> book, int target)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (book[i] + book[j] == target)
            {
                return "YES";
            }
        }
    }
    return "NO";
}

//  Sort An Array of 0s, 1s and 2s
// MTD-1
// void sortArray0_1_2(vector<int> &arr, int n)
// {
//     sort(arr.begin(), arr.end());
// }

// MTD-2   --> TC = O(n)
// void sortArray0_1_2(vector<int> &arr, int n)
// {
//     int count0 = 0;
//     int count1 = 0;
//     int count2 = 0;

//     for (int i = 0; i < n; i++)
//     {
//         if (arr[i] == 0)
//         {
//             count0++;
//         }
//         if (arr[i] == 1)
//         {
//             count1++;
//         }
//         if (arr[i] == 2)
//         {
//             count2++;
//         }
//     }

//     for (int i = 0; i < count0; i++)
//     {
//         arr[i] = 0;
//     }
//     for (int i = count0; i < count0 + count1; i++)
//     {
//         arr[i] = 1;
//     }
//     for (int i = count0 + count1; i < n; i++)
//     {
//         arr[i] = 2;
//     }
// }

// MTD-3 using Ductch national flag Algorithm  {Optimal} --> TC = O(n)
void sortArray0_1_2(vector<int> &arr, int n)
{
    int low = 0;
    int mid = 0;
    int high = n - 1;

    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            swap(arr[mid], arr[low]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

//  Majority Element appears more than 'n' / 2 times.

int majorityElement(vector<int> v)
{
    int n = v.size();
    map<int, int> map;

    // stores the count of the every elements
    for (auto it : v)
    {
        map[it]++;
    }

    for (auto pair : map)
    {
        if (pair.second > n / 2)
        {
            return pair.first;
        }
    }
}

//  Maximum Subarray Sum
// MTD:-
// long long maxSubarraySum(vector<int> arr, int n)
// {
//     long long sum = arr[0];
//     long long maxVal = arr[0];
//     for (int i = 1; i < n; i++)
//     {
//         sum = max((long long)arr[i], sum + arr[i]);
//         maxVal = max(sum, maxVal);
//     }
//     return maxVal;
// }

// Mtd-2 using Kadane's Algorithm  --> TC --> O(n)
long long maxSubarraySum(vector<int> arr, int n)
{
    long long sum = 0;
    long long maxVal = arr[0];
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        maxVal = max(maxVal, sum);
        if (sum < 0)
        {
            sum = 0;
        }
    }

    if (maxVal > 0)
    {
        return maxVal;
    }
    else
    {
        return 0;
    }
}

// Rearrange Array Elements by Sign
// MTD-1  --> CN   TC --> O(n^2)
vector<int> alternateNumbers(vector<int> &a)
{
    int n = a.size();
    vector<int> PostArr;
    vector<int> NegArr;
    vector<int> finalArr(n);

    for (int i = 0; i < n; i++)
    {
        if (a[i] > 0)
        {
            PostArr.push_back(a[i]);
        }
        else
        {
            NegArr.push_back(a[i]);
        }
    }

    for (int i = 0; i < n / 2; i++)
    {
        finalArr[2 * i] = PostArr[i];
        finalArr[2 * i + 1] = NegArr[i];
    }
    return finalArr;
}

// MTD-2  --> Leetcode same number -->n/2
// vector<int> alternateNumbers(vector<int> &a)
// {
//     int n = a.size();
//     vector<int> Answer(n, 0);
//     int posIdx = 0;
//     int NegIdx = 1;

//     for (int i = 0; i < n; i++)
//     {
//         if (a[i] < 0)
//         {
//             Answer[NegIdx++] = a[i];
//             NegIdx += 2;
//         }
//         else
//         {
//             Answer[posIdx++] = a[i];
//             posIdx += 2;
//         }
//     }
//     return Answer;
// }

//  Longest Successive Elements

// Mtd-1   TC --> O(n^2)
bool searchElement(vector<int> &a, int key)
{
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == key)
        {
            return true;
        }
    }
    return false;
}

// int longestSuccessiveElements(vector<int> &a)
// {
//     int n = a.size();
//     int maxlen = 1;

//     for (int i = 0; i < n; i++)
//     {
//         int findVal = a[i];
//         int count = 1;

//         while ((searchElement(a, findVal + 1) == true))
//         {
//             findVal += 1;
//             count++;
//         }

//         maxlen = max(maxlen, count);
//     }

//     return maxlen;
// }

// Mtd-2   TC --> O(n)

// int longestSuccessiveElements(vector<int> &a)
// {
//     sort(a.begin(), a.end());
//     int maxlen = 1;
//     int lastsamllest = INT_MIN;
//     int curCount = 0;
//     int n = a.size();

//     for (int i = 0; i < n; i++)
//     {
//         if (a[i] - 1 == lastsamllest)
//         {
//             curCount++;
//             lastsamllest = a[i];
//         }
//         else if (a[i] != lastsamllest)
//         {
//             curCount = 1;
//             lastsamllest = a[i];
//         }
//         maxlen = max(maxlen, curCount);
//     }
//     return maxlen;
// }

// Mtd-3 using set   TC -->

int longestSuccessiveElements(vector<int> &a)
{
    int n = a.size();
    if (n == 0)
    {
        return 0;
    }

    int maxlen = 0;
    unordered_set<int> st;

    for (int i = 0; i < n; i++)
    {
        st.insert(a[i]);
    }

    for (auto it : st)
    {
        if (st.find(it - 1) == st.end())
        {
            int count = 1;
            int x = it;
            while (st.find(x + 1) != st.end())
            {
                x += 1;
                count++;
            }
            maxlen = max(maxlen, count);
        }
    }

    return maxlen;
}

//  Superior Elements
// Mtd-1    TC --> O(n^2)
// vector<int> superiorElements(vector<int> &a)
// {
//     int n = a.size();
//     vector<int> ans;

//     for (int i = 0; i < n; i++)
//     {
//         bool leader = true;
//         for (int j = i + 1; j < n; j++)
//         {
//             if (a[j] >= a[i])
//             {
//                 leader = false;
//                 break;
//             }
//         }
//         if (leader == true)
//         {
//             ans.push_back(a[i]);
//         }
//     }

//     sort(ans.begin(), ans.end());

//     return ans;
// }

// Mtd-2    TC --> O(nlogn)

vector<int> superiorElements(vector<int> &a)
{
    int n = a.size();
    vector<int> ans;
    int maxVal = INT_MIN;

    for (int i = n - 1; i >= 0; i--)
    {
        if (a[i] > maxVal)
        {
            ans.push_back(a[i]);
        }
        maxVal = max(maxVal, a[i]);
    }

    sort(ans.begin(), ans.end());

    return ans;
}

// All possible Permutations  TC --> O(n!)
// SC  --> O(n)+O(n)

// void recurPermutation(vector<int> &ds, vector<int> &A, vector<vector<int>> &ans, vector<int> &frequency)
// {
//     int n = A.size();
//     if (ds.size() == n)
//     {
//         ans.push_back(ds);
//         return;
//     }

//     for (int i = 0; i < n; i++)
//     {
//         if (!frequency[i])
//         {
//             ds.push_back(A[i]);
//             frequency[i] = 1;
//             recurPermutation(ds, A, ans, frequency);
//             frequency[i] = 0;
//             ds.pop_back();
//         }
//     }
// }

// vector<vector<int>> allPermutation(vector<int> &A)
// {
//     int n = A.size();
//     vector<vector<int>> ans;
//     vector<int> ds;
//     vector<int> frequency(n, 0);
//     recurPermutation(ds, A, ans, frequency);
//     return ans;
// }

//  Next Greater Permutation
// MTD-1    --> finding all perms, linear searching it, if matchs return i+1
void recurnextPermutation(vector<int> &ds, vector<int> &A, vector<vector<int>> &ans, vector<int> &frequency)
{
    int n = A.size();
    if (ds.size() == n)
    {
        ans.push_back(ds);
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (!frequency[i])
        {
            ds.push_back(A[i]);
            frequency[i] = 1;
            recurnextPermutation(ds, A, ans, frequency);
            frequency[i] = 0;
            ds.pop_back();
        }
    }
}

// vector<int> nextGreaterPermutation(vector<int> &A) {
//     int n = A.size();
//     vector<vector<int>> ans;
//     vector<int> ds;
//     vector<int> frequency(n, 0);
//     recurnextPermutation(ds, A, ans, frequency);

//     sort(ans.begin(), ans.end());

//     vector<int> nextGreaterPer;
//     bool found = false;
//     for (int i = 0; i < ans.size(); i++) {
//         if (ans[i] == A) {
//             if (i < ans.size() - 1) {
//                 nextGreaterPer = ans[i + 1];
//                 found = true;
//                 break;
//             } else { // Wrap around to the first permutation
//                 nextGreaterPer = ans[0];
//                 found = true;
//                 break;
//             }
//         }
//     }

//     if (!found) {
//         nextGreaterPer = {};
//     }
//     return nextGreaterPer;
// }

// MTD-2    --> Better
// vector<int> nextGreaterPermutation(vector<int> &A)
// {
//     next_permutation(A.begin(), A.end());
//     return A;
// }

// MTD-3    --> Optimal
vector<int> nextGreaterPermutation(vector<int> &A)
{
    int idx = -1;
    int n = A.size();
    for (int i = n - 2; i >= 0; i--)
    {
        if (A[i] < A[i + 1])
        {
            idx = i;
            break;
        }
    }

    if (idx == -1)
    {
        reverse(A.begin(), A.end());
        return A;
    }

    for (int i = n - 1; i > idx; i--)
    {
        if (A[i] > A[idx])
        {
            swap(A[i], A[idx]);
            break;
        }
    }

    reverse(A.begin() + idx + 1, A.end());

    return A;
}

//  Best time to buy and sell stock

int bestTimeToBuyAndSellStock(vector<int> &prices)
{
    int minVal = prices[0];
    int profit = 0;
    int n = prices.size();

    for (int i = 1; i < n; i++)
    {
        int cost = prices[i] - minVal;
        profit = max(profit, cost);
        minVal = min(minVal, prices[i]); // using DP bcoz remaining the min value to sell it
    }
    return profit;
}

//  Rotate The Matrix

// Mtd-1 using Extra Space TC --> O(n^2)
// void rotateMatrix(vector<vector<int>> &mat)
// {
//     int n = mat.size();
//     vector<vector<int>> ansMatrix(n, vector<int>(n));

//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             ansMatrix[j][n - 1 - i] = mat[i][j];
//         }
//     }

//     mat = ansMatrix;
// }

// Mtd-2  TC --> O(n^2)
void rotateMatrix(vector<vector<int>> &mat)
{

    int n = mat.size();

    // 1) transpose the matrix

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            swap(mat[i][j], mat[j][i]);
        }
    }

    // 2) then reverse the row

    for (int i = 0; i < n; i++)
    {
        reverse(mat[i].begin(), mat[i].end());
    }
}

//  Spiral Matrix --> only one optimal way to solve this problem

vector<int> spiralMatrix(vector<vector<int>> &MATRIX)
{
    int n = MATRIX.size();
    int m = MATRIX[0].size();

    int left = 0, right = m - 1;
    int top = 0, bottom = n - 1;
    vector<int> ans;

    while (top <= bottom && left <= right)
    {

        for (int i = left; i <= right; i++)
        {
            ans.push_back(MATRIX[top][i]);
        }
        top++;

        for (int i = top; i <= bottom; i++)
        {
            ans.push_back(MATRIX[i][right]);
        }
        right--;

        if (top <= bottom)
        {
            for (int i = right; i >= left; i--)
            {
                ans.push_back(MATRIX[bottom][i]);
            }
            bottom--;
        }

        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
            {
                ans.push_back(MATRIX[i][left]);
            }
            left++;
        }
    }

    return ans;
}

//  Count All Subarrays With Given Sum
int findAllSubarraysWithGivenSum(vector<int> &arr, int k)
{
    int n = arr.size();
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            if (sum == k)
            {
                count++;
            }
        }
    }
    return count;
}


void pascalTriangleprintRow(int N)
{ // TC --> O(N) SC --> O(1)
    int res = 1;
    cout << res << " ";

    for (int i = 1; i < N; i++)
    {
        res = res * (N - i);
        res = res / i;
        cout << res << " ";
    }
}

int main()
{
    // int n;
    // cout << "n: ";
    // cin >> n;

    // int arr[n];
    // cout << "Array Values: ";
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> arr[i];
    // }

    // cout << "Display Array Values: ";
    // for (int i = 0; i < n; i++)
    // {
    //     cout << arr[i] << " ";
    // }
    // cout << endl;

    // cout << "Largest Element in an Array: " << LargestElementArray(arr, n) << endl;

    // vector<int> varr = {15, 6, 2, 1, 16, 4, 2, 29, 9, 12, 8, 5, 14, 21, 8, 12, 17, 16, 6, 26, 3};
    vector<int> varr = {3, 1, 2, 4};
    int k = 6;
    // vector<vector<int>> matrix = {
    //     {1, 5, 9, 13},
    //     {14, 15, 16, 17},
    //     {19, 20, 21, 50},
    //     {59, 60, 71, 80}
    // };

    // vector<int> barr = {2 ,3 ,4 ,6, 7};

    // cout << "Vector Values: " << endl;
    // for (const auto &row : matrix)
    // {
    //     for (int element : row)
    //     {
    //         cout << element << " ";
    //     }
    //     cout << endl;
    // }

    cout << "Vector Values: ";
    for (auto it : varr)
    {
        cout << it << " ";
    }

    // auto result = getSecondOrderElements(5, varr);
    // auto answer = isSorted(5, varr);
    // auto result = removeDuplicates(varr, 9);
    // auto result = rotateArrayleft(varr, 5);
    // int k = 3;
    // auto result = rotateArraybyktimes(varr, k);
    // auto result = moveZeros(5, varr);
    // int num = 20;
    // auto result = linearSearch(4, num, varr);
    // auto result = sortedArrayMergetwoArray(varr, barr);
    // auto result = missingNumber(varr);
    // auto result = findMaxConsecutiveOnes(varr);
    // auto result = getSingleElement(varr);
    // auto result = longestSubarrayWithSumK(varr, k);
    // auto result = getLongestSubarrayposandneg(varr, k);
    // auto result = TwoSum(7, varr, target);
    // sortArray0_1_2(varr, varr.size());
    // auto result = majorityElement(varr);
    // long long result = maxSubarraySum(varr, varr.size());
    // auto result = alternateNumbers(varr);
    // vector<int> merged = alternateNumbers(varr);
    // auto result = longestSuccessiveElements(varr);
    // auto result = superiorElements(varr);
    // auto result = allPermutation(varr);
    // auto result = nextGreaterPermutation(varr);
    // auto result = bestTimeToBuyAndSellStock(varr);
    // rotateMatrix(matrix);
    // auto result = spiralMatrix(matrix);
    // auto result = findAllSubarraysWithGivenSum(varr, k);

    // Accessing the result vector of pairs
    // cout << "\nSecond smallest and second largest: " << result[0] << " and " << result[1] << endl;
    cout << endl;
    // cout << " Check Sorted Array: " << (answer ? "Yes" : "No") << endl;
    // cout << "Remove Duplicates from Sorted Array: " <<result<< endl;
    // cout << "Rotate array K Times: ";

    // for (auto it : result)
    // {
    //     cout << it << " ";
    // }

    // cout << "Move Zero's to End: ";
    // for (auto it : result)
    // {
    //     cout << it << " ";
    // }

    // cout << "Linear Search: " << result << endl;

    // cout << "Merge 2 Sortedin Final Array: ";
    // for (auto it : result)
    // {
    //     cout << it << " ";
    // }

    // cout << "Number in the range that is Missing is: " << result << endl;
    // cout << "Maximum consecutive ones: " << result << endl;
    // cout << " Find The Single Element: " << result << endl;
    // cout << " Longest Subarray With Sum K: " << result << endl;
    // cout << " Longest Subarray[pos&neg] With Sum K: " << result << endl;
    // cout << "Two Sum: " << result << endl;
    // cout << "Sort An Array of 0s, 1s and 2s: ";
    // for (auto it : varr)
    // {
    //     cout << it << " ";
    // }

    // cout << "Majority element of the array: " << result << endl;
    // cout << "Maximum Subarray Sum: " << result << endl;

    // cout << "Rearrange Array Elements by Sign: ";
    // for (auto it : merged)
    // {
    //     cout << it << " ";
    // }

    // cout << "Longest Successive Elements: " << result << endl;

    // cout << " Superior Elements: ";
    // for (auto it : result)
    // {
    //     cout << it << " ";
    // }

    //   cout << "All Permutations: ";
    // for (auto vec : result)
    // {
    //     cout << "[ ";
    //     for (auto num : vec)
    //     {
    //         cout << num << " ";
    //     }
    //     cout << "], ";
    // }
    // cout << endl;

    // cout << "Next Greater Permutation: ";
    // for (auto it : result)
    // {
    //     cout << it << " ";
    // }
    // cout << endl;

    // cout << "Best time to buy and sell stock: " << result << endl;

    // cout << " Rotate The Matrix: " << endl;
    // for (const auto &row : matrix)
    // {
    //     for (int element : row)
    //     {
    //         std::cout << element << " ";
    //     }
    //     std::cout << std::endl;
    // }

    // cout << " Spiral Matrix Elements: ";
    // for (auto it : result)
    // {
    //     cout << it << " ";
    // }
    // cout << endl;

    // cout << "Count of Subarrays With Given Sum: " << result << endl;


    // cout << "majority Element: " << result << endl;
    return 0;
}