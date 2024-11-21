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
    return ans;
}

// Sort Colors
void sortColors1(vector<int> &nums)
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

// Sort Colors --> Mthd-2
void sortColors(vector<int> &nums)
{
    int n = nums.size();
    int low = 0;
    int high = n - 1;
    int mid = 0;

    while (mid <= high)
    {
        if (nums[mid] == 0)
        {
            swap(nums[low], nums[mid]);
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

// Maximum Subarray
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

    for (int i = 0; i < n - 1; i++)
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
            negative.push_back(nums[i]);
        }
        else
        {
            positive.push_back(nums[i]);
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

    // First mark rows and columns that contain 0

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

    // second pass:  mark rows and columns that contain -1 to 1
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
    return count;
}

// ************************* STRING EASY ***************************
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

    string startStr = strs[0];
    int longestcount = startStr.size();

    for (int i = 1; i < strs.size(); i++)
    {
        int j = 0; // Pointer to compare characters in the current string and the main string
        while (j < startStr.size() && j < strs[i].size() && startStr[j] == strs[i][j])
        {
            j++;
        }
        longestcount = min(longestcount, j);
    }
    string ans = startStr.substr(0, longestcount); // excliduing the longestcount number index
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
                currZero++;
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
    int n = s.size();
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
        if (s[i] != ' ')
        {
            ans.push_back(s[i]);
        }
        else
        {
            if (!ans.empty())
            {
                reverse(ans.begin(), ans.end());
                if (!finalAns.empty())
                {
                    finalAns.push_back(' ');
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
            finalAns.push_back(' ');
        }
        finalAns += ans;
    }

    return finalAns;
}

// Largest Odd Number in String
string largestOddNumber(string num)
{
    int n = num.length();
    string longestOdd = "";

    for (int i = n - 1; i >= 0; i--)
    {
        if ((num[i] - '0') % 2 != 0)
        {
            longestOdd = num.substr(0, i + 1);
            break;
        }
    }
    return longestOdd;
}

// Rotate String
bool rotateString(string str, string goal)
{
    int n = str.size();
    int m = goal.size();

    if (n != m)
    {
        return false;
    }

    string doubleStr = str + str;

    return (doubleStr.find(goal) != string::npos);
}

// Armstrong number
bool isArmstrong(int n)
{
    int orgnum = n;
    int sum = 0;
    int digits = 0;

    while (n > 0)
    {
        n /= 10;
        digits++;
    }
    n = orgnum;

    while (n > 0)
    {
        int num = n % 10;
        sum += pow(num, digits);
        n /= 10;
    }
    return sum == orgnum;
}

// reverse a digit
int reverseDigit(int n)
{
    int rev = 0;
    while (n > 0)
    {
        rev = rev * 10 + n % 10;
        n /= 10;
    }
    return rev;
}

// sum of digits is palindrome is not
bool isPalindrome(int n)
{
    int sum = 0;

    while (n > 0)
    {
        sum += n % 10;
        n /= 10;
    }

    int rev = reverseDigit(sum);

    return sum == rev;
}

// swap the kth element with the kth last element
void swapKthElement(vector<int> &arr, int k)
{
    int n = arr.size();
    swap(arr[k - 1], arr[n - k]);
}

// remove spaces
string removeSpaces(string str)
{
    // str.erase(new_end, str.end()) removes all elements starting from new_end to the end.
    str.erase(remove(str.begin(), str.end(), ' '), str.end());
    return str;
}

// Sum of Mutliplication table
int sumOfMultiplicationTable(int n, int m)
{
    int sum = 0;
    for (int i = 1; i <= m; i++)
    {
        sum += (n * i);
    }
    return sum;
}

// find subarray with given sum
vector<vector<int>> findSubarrayWithGivenSum(vector<int> &arr, int k)
{
    int n = arr.size();
    int count = 0;
    vector<vector<int>> ans;

    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            if (sum == k)
            {
                vector<int> temp;
                for (int k = i; k < j + 1; k++)
                {
                    temp.push_back(arr[k]);
                }
                ans.push_back(temp);
            }
        }
    }
    return ans;
}

// unique path
int uniquePaths(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, 1));

    for (int i = 0; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    return dp[m - 1][n - 1];
}

// Cubes of all numbers in range
int cubesInRange(int n, int m)
{
    int sum = 0;
    for (int i = n; i <= m; i++)
    {
        int digitCube = i * i * i;
        sum += digitCube;
    }
    return sum;
}

// sum of unique elements
int sumOfUniqueElements(vector<int> &arr)
{
    int n = arr.size();
    int sum = 0;
    unordered_map<int, int> mpp;

    for (int i = 0; i < n; i++)
    {
        mpp[arr[i]]++;
    }

    for (auto it : mpp)
    {
        sum += it.first;
    }
    return sum;
}

// maximum sum of subarray
int maxSubArraySum(vector<int> &arr)
{
    int n = arr.size();
    int maxSum = INT_MIN;
    int currsum = 0;

    for (int i = 0; i < n; i++)
    {
        currsum = max(arr[i], currsum + arr[i]);
        maxSum = max(maxSum, currsum);
    }
    return maxSum;
}

// maximum number in each contigous window
vector<int> maxInEachContigousWindow(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<int> ans;

    for (int i = 0; i <= n - k; i++)
    {
        int maxNum = arr[i];

        for (int j = i; j < i + k; j++)
        {
            maxNum = max(maxNum, arr[j]);
        }
        ans.push_back(maxNum);
    }
    return ans;
}

// find avg and sum of elements in array
vector<double> findAvgAndSum(vector<double> &arr)
{
    int n = arr.size();
    double sum = 0;
    double avg = 0;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    avg = sum / n;

    // round off uptp 4 decmial
    sum = round(sum * 10000.0) / 10000.0;
    avg = round(avg * 10000.0) / 10000.0;

    return {sum, avg};
}

// find palindrome in given range
bool isPalindrome(string &str, int n, int m)
{

    while (n < m)
    {
        if (str[n] != str[m])
        {
            return false;
        }
        n++;
        m--;
    }
    return true;
}

/********************************** STRING MEDIUM **********************************/
// Sort Characters By Frequency
string frequencySort(string s)
{
    unordered_map<char, int> mpp;
    for (int i = 0; i < s.length(); i++)
    {
        mpp[s[i]]++;
    }

    vector<pair<char, int>> freqList(mpp.begin(), mpp.end());
    sort(freqList.begin(), freqList.end(), [](const pair<char, int> &a, const pair<char, int> &b)
         { return a.second < b.second; });

    string res = "";
    for (auto &lst : freqList)
    {
        res.append(lst.second, lst.first);
    }
    return res;
}

int main()
{
    // vector<int> arr;
    // int n, m, mum, num;

    // cout << "Enter the number of elements1: ";
    // cin >> n;
    // // cout << "Enter the number of elements2: ";
    // // cin >> m;

    // cout << "Enter the elements1: ";
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> num;
    //     arr.push_back(num);
    // }

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
    // cout << "The length of the longest sub-array with sum K is: " << lenOfLongestSubarr(arr, 15) << endl;
    // vector<int> ans = twoSum(arr, 9);
    // cout << "The indices of the two numbers that add up to the target sum are: ";
    // for (int i = 0; i < ans.size(); i++)
    // {
    //     cout << ans[i] << " ";
    // }

    // sortColors(arr);
    // cout << "The sorted array is: ";
    // for (int i = 0; i < arr.size(); i++)
    // {
    //     cout << arr[i] << " ";
    // }
    // -2,1,-3,4,-1,2,1,-5,4]

    // cout << "The majority element in the array is: " << majorityElement(arr) << endl;
    // cout << "The maximum sum of the subarray is: " << maxSubArray(arr) << endl;
    // cout << "The maximum profit from buying and selling stock is: " << maxProfit(arr) << endl;

    // vector<int> ans = rearrangeArray(arr);
    // cout << "The rearranged array is: ";
    // for (int i = 0; i < ans.size(); i++)
    // {
    //     cout << ans[i] << " ";
    // }

    // nextPermutation(arr);
    // cout << "The next permutation of the array is: ";
    // for (int i = 0; i < arr.size(); i++)
    // {
    //     cout << arr[i] << " ";
    // }

    // vector<int> ans = leaders(arr);
    // cout << "The leaders in the array are: ";
    // for (int i = 0; i < ans.size(); i++)
    // {
    //     cout << ans[i] << " ";
    // }

    // cout << "The longest consecutive sequence in the array is: " << longestConsecutive(arr) << endl;

    // vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    // setZeroes(matrix);
    // cout << "The matrix after setting zeroes is: ";
    // for (int i = 0; i < matrix.size(); i++)
    // {
    //     for (int j = 0; j < matrix[0].size(); j++)
    //     {
    //         cout << matrix[i][j] << " ";
    //     }
    // }

    // rotate(matrix);
    // cout << "The matrix after rotating is: " << endl;
    // for (int i = 0; i < matrix.size(); i++)
    // {
    //     for (int j = 0; j < matrix[0].size(); j++)
    //     {
    //         cout << matrix[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // vector<int> ans = spiralOrder(matrix);
    // cout << "The spiral order of the matrix is: ";
    // for (int i = 0; i < ans.size(); i++)
    // {
    //     cout << ans[i] << " ";
    // }

    // cout << "The number of subarrays with sum K is: " << subarraySum(arr, 3) << endl;

    // vector<string> str = {"dog", "racecar", "car"};
    // string str = "abcde";
    // string t = "abced";
    // string t = "bar";
    // cout << "The lexicographically sorted string is: " << sortlexicographically("hello") << endl;
    // cout << "The strings are anagrams: " << isAnagram(str, t) << endl;
    // cout << "The strings are isomorphic: " << isIsomorphic(str, t) << endl;
    // cout << "The longest common prefix is: " << longestCommonPrefix(str) << endl;
    // cout << "The maximum consecutive 1's fliped k times is: " << maxConsecutive1sKtimes(str, 2) << endl;
    // cout << "The string after removing outermost parentheses is: " << removeOuterParentheses(str) << endl;
    // cout << "The string after reversing words is: " << reverseWords(str) << endl;
    // cout << "The largest odd number in the string is: " << largestOddNumber(str) << endl;
    // cout << "The strings are rotated: " << rotateString(str, t) << endl;
    // cout << "The number is armstrong: " << isArmstrong(120) << endl;
    // cout << "The reverse of the digit is: " << reverseDigit(200) << endl;
    // cout << "The sum of digits is palindrome: " << isPalindrome(51241) << endl;

    // vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8};
    // swapKthElement(arr, 3);
    // cout << "The array after swapping the kth element with the kth last element is: ";
    // for (int i = 0; i < arr.size(); i++)
    // {
    //     cout << arr[i] << " ";
    // }

    // string str = "Hello World";
    // cout << "The string after removing spaces is: " << removeSpaces(str) << endl;
    // cout << "The sum of the multiplication table is: " << sumOfMultiplicationTable(10, 10) << endl;

    // vector<int> arr = {3, 4, -7, 1, 3, 3, 1, -4};
    // vector<vector<int>> ans = findSubarrayWithGivenSum(arr, 7);
    // cout << "The subarrays with the given sum are: " << endl;
    // for (int i = 0; i < ans.size(); i++)
    // {
    //     for (int j = 0; j < ans[i].size(); j++)
    //     {
    //         cout << ans[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // cout << "The sum of the cubes of all numbers in the range is: " << cubesInRange(4, 9) << endl;

    // vector<int> arr = {1, 3, 2, 3, 2, 4};
    // cout << "The sum of the unique elements in the array is: " << sumOfUniqueElements(arr) << endl;

    // vector<int> arr = {1, 2, 3, 4, 5};
    // cout << "The maximum sum of the subarray is: " << maxSubArraySum(arr) << endl;

    // vector<int> arr = {1, 3, -1, -3, 5, 3, 6, 7};
    // vector<int> ans = maxInEachContigousWindow(arr, 3);
    // cout << "The maximum number in each contigous window is: ";
    // for (int i = 0; i < ans.size(); i++)
    // {
    //     cout << ans[i] << " ";
    // }

    // vector<double> arr = {1.55, 2, 3.555, 4, 5.5};
    // vector<double> ans = findAvgAndSum(arr);
    // cout << "The sum and average of the elements in the array is: " << ans[0] << " " << ans[1] << endl;

    // string str = "abccba";
    // cout << "The string is palindrome: " << isPalindrome(str, 0, 5) << endl;

    string str = "tree";
    cout << "The sorted characters by frequency is: " << frequencySort(str) << endl;

    return 0;
}
