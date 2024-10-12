#include <bits/stdc++.h>
using namespace std;

//  Aggressive Cows  --> min distance between 2 cows is max
// min --> always between adjacent stalls
bool canweplacecows(vector<int> &stalls, int mid, int k)
{
    int countCows = 1;
    int lastplaceCows = stalls[0];

    for (int i = 1; i < stalls.size(); i++)
    {
        if (stalls[i] - lastplaceCows >= mid)
        {
            countCows++;
            lastplaceCows = stalls[i];
        }
    }

    return countCows >= k;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    int n = stalls.size();
    sort(stalls.begin(), stalls.end());   // Sort the stalls for binary search
    int low = 1;                          // Minimum possible distance
    int high = stalls[n - 1] - stalls[0]; // Maximum possible distance
    int ans = -1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (canweplacecows(stalls, mid, k))
        {
            ans = mid; // Try for a larger minimum distance
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return ans;
}

// Allocate Books

int maxminumPagesAllocate(vector<int> &arr, int mid)
{
    int pagesHold = 0;
    int currStudent = 1;

    for (int i = 0; i < arr.size(); i++)
    {
        if (pagesHold + arr[i] <= mid)
        {
            pagesHold += arr[i];
        }
        else
        {
            currStudent++;
            pagesHold = arr[i];
        }
    }
    return currStudent;
}

int findPages(vector<int> &arr, int n, int m)
{
    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    int ans = -1;

    if (m > n)
    {
        return ans;
    }

    while (low <= high)
    {
        int mid = (low + high) / 2;
        int noOfStudents = maxminumPagesAllocate(arr, mid);

        if (noOfStudents > m)
        {
            low = mid + 1;
        }
        else
        {
            ans = mid;
            high = mid - 1;
        }
    }
    return ans;
}

// Split Array Largest Sum --> same Book Allocation, Painter's partition

int SubarrayDivide(vector<int> &arr, int mid)
{
    int CurrentSubArr = 1;
    int SubArrnxt = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        if (SubArrnxt + arr[i] <= mid)
        {
            SubArrnxt += arr[i];
        }
        else
        {
            CurrentSubArr += 1;
            SubArrnxt = arr[i];
        }
    }

    return CurrentSubArr;
}

int splitArrayHelper(vector<int> &arr, int n, int m)
{
    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    int ans = -1;

    if (m > n)
    {
        return ans;
    }

    while (low <= high)
    {
        int mid = (low + high) / 2;
        int noOfStudents = SubarrayDivide(arr, mid);

        if (noOfStudents > m)
        {
            low = mid + 1;
        }
        else
        {
            ans = mid;
            high = mid - 1;
        }
    }
    return ans;
}

int splitArray(vector<int> &nums, int k)
{
    return splitArrayHelper(nums, nums.size(), k);
}

// Painter's Partition Problem --> same Book Allocation, Split Array Largest Sum

int paintersubarray(vector<int> &arr, int mid)
{
    int CurrentSubArr = 1;
    int SubArrnxt = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        if (SubArrnxt + arr[i] <= mid)
        {
            SubArrnxt += arr[i];
        }
        else
        {
            CurrentSubArr += 1;
            SubArrnxt = arr[i];
        }
    }

    return CurrentSubArr;
}

int PainterPartitionHelper(vector<int> &arr, int n, int m)
{
    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    int ans = -1;

    if (m > n)
    {
        return ans;
    }

    while (low <= high)
    {
        int mid = (low + high) / 2;
        int noOfStudents = paintersubarray(arr, mid);

        if (noOfStudents > m)
        {
            low = mid + 1;
        }
        else
        {
            ans = mid;
            high = mid - 1;
        }
    }
    return ans;
}

int PainterPartition(vector<int> &nums, int k)
{
    return PainterPartitionHelper(nums, nums.size(), k);
}

//  Minimize Max Distance to Gas Station  --> Min on Max
int noofGasStationsrequired(vector<int> &arr, long double mid)
{
    int n = arr.size();
    int count = 0;
    for (int i = 1; i < n; i++)
    {
        int numberInBetween = ((arr[i] - arr[i - 1]) / mid);
        count += numberInBetween;
    }
    return count;
}

double minimiseMaxDistance(vector<int> &arr, int k)
{
    long double low = 0;
    long double high = *max_element(arr.begin(), arr.end()) - *min_element(arr.begin(), arr.end());
    long double ans = -1;
    long double diff = 1e-6;

    while (high - low > diff)
    {
        long double mid = (low + high) / (2.0);
        int countofGasStn = noofGasStationsrequired(arr, mid);
        if (countofGasStn > k)
        {
            low = mid;
        }
        else
        {
            ans = mid;
            high = mid;
        }
    }
    return ans;
}

// Median of Two Sorted Arrays
double findMedianSortedArrays1(vector<int> &nums1, vector<int> &nums2)
{
    int n1 = nums1.size();
    int n2 = nums2.size();

    if (n1 > n2)
    {
        return findMedianSortedArrays1(nums2, nums1);
    }
    int low = 0;
    int high = n1;
    int left = (n1 + n2 + 1) / 2;
    int n = n1 + n2;

    while (low <= high)
    {
        int mid1 = (low + high) >> 1;
        int mid2 = left - mid1;
        int l1 = (mid1 == 0) ? INT_MIN : nums1[mid1 - 1];
        int l2 = (mid2 == 0) ? INT_MIN : nums2[mid2 - 1];
        int r1 = (mid1 == n1) ? INT_MAX : nums1[mid1];
        int r2 = (mid2 == n2) ? INT_MAX : nums2[mid2];
        if (l1 <= r2 && l2 <= r1)
        {
            if (n % 2 == 1)
            {
                return max(l1, l2);
            }
            return (double)(max(l1, l2) + min(r1, r2)) / 2.0;
        }
        else if (l1 > r2)
        {
            high = mid1 - 1;
        }
        else
        {
            low = mid1 + 1;
        }
    }
    return 0;
}

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    int n1 = nums1.size();
    int n2 = nums2.size();
    int i = 0, j = 0;
    int n = n1 + n2;
    int index1 = n / 2;
    int index2 = index1 - 1;
    int count = 0;
    int ele1 = -1, ele2 = -1;

    while (i < n1 && j < n2)
    {
        if (nums1[i] < nums2[j])
        {
            if (count == index1)
            {
                ele1 = nums1[i];
            }
            if (count == index2)
            {
                ele2 = nums1[i];
            }
            count++;
            i++;
        }
        else
        {
            if (count == index1)
            {
                ele1 = nums2[j];
            }
            if (count == index2)
            {
                ele2 = nums2[j];
            }
            count++;
            j++;
        }
    }

    // If there are remaining elements in nums1
    while (i < n1)
    {
        if (count == index1)
        {
            ele1 = nums1[i];
        }
        if (count == index2)
        {
            ele2 = nums1[i];
        }
        count++;
        i++;
    }

    // If there are remaining elements in nums2
    while (j < n2)
    {
        if (count == index1)
        {
            ele1 = nums2[j];
        }
        if (count == index2)
        {
            ele2 = nums2[j];
        }
        count++;
        j++;
    }

    // If the total number of elements is odd, return the middle element
    if (n % 2 == 1)
    {
        return ele1;
    }

    // If the total number of elements is even, return the average of the two middle elements
    return (double)(ele1 + ele2) / 2.0;
}

// K-th element of two Arrays
int kthElement(int k, vector<int> &arr1, vector<int> &arr2)
{
    int n1 = arr1.size();
    int n2 = arr2.size();

    // Ensure that arr1 is the smaller array
    if (n1 > n2)
    {
        return kthElement(k, arr2, arr1);
    }

    int low = max(0, k - n2); // If k > n2, adjust the low bound
    int high = min(k, n1);    // If k < n1, adjust the high bound

    while (low <= high)
    {
        int mid1 = (low + high) / 2;
        int mid2 = k - mid1;

        // Left and right boundaries for arr1 and arr2
        int l1 = (mid1 == 0) ? INT_MIN : arr1[mid1 - 1];
        int l2 = (mid2 == 0) ? INT_MIN : arr2[mid2 - 1];
        int r1 = (mid1 == n1) ? INT_MAX : arr1[mid1];
        int r2 = (mid2 == n2) ? INT_MAX : arr2[mid2];

        // Check if we have found the k-th element
        if (l1 <= r2 && l2 <= r1)
        {
            return max(l1, l2);
        }
        else if (l1 > r2) // Reduce mid1 if l1 is greater than r2
        {
            high = mid1 - 1;
        }
        else // Increase mid1 if l2 is greater than r1
        {
            low = mid1 + 1;
        }
    }

    return -1; // Fallback case (should not be reached)
}

// ************************* BINARY SERACH 2D Array ***************************
// Row with max 1s
int lowerBound(vector<int> &arr, int target) // lb/up/first occurrence of 1 --> bcoz we need to find first occurrence of 1
{
    auto lowerboundans = lower_bound(arr.begin(), arr.end(), target) - arr.begin();
    return lowerboundans;
}

int rowWithMax1s(vector<vector<int>> &arr)
{
    int n = arr.size();
    int maxCount = 0;
    int maxIdx = -1;

    for (int i = 0; i < n; i++)
    {
        int count_ones = n - lowerBound(arr[i], 1);
        if (count_ones > maxCount)
        {
            maxCount = count_ones;
            maxIdx = i;
        }
    }
    return maxIdx;
}

// Search a 2D Matrix
bool searchMatrix1(vector<vector<int>> &matrix, int target)
{
    int n = matrix.size();    // row
    int m = matrix[0].size(); // col
    int low = 0, high = (n * m - 1);

    while (low <= high)
    {
        int mid = (low + high) / 2;
        int row = mid / m;
        int col = mid % m;

        if (matrix[row][col] == target)
        {
            return true;
        }
        else if (matrix[row][col] > target)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return false;
}

// Search a 2D Matrix II
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int n = matrix.size();
    int m = matrix[0].size();
    int row = 0;
    int col = m - 1;

    while (row < n && col >= 0)
    {
        if (matrix[row][col] == target)
        {
            return true;
        }
        else if (matrix[row][col] > target)
        {
            col--;
        }
        else
        {
            row++;
        }
    }
    return false;
}

// Find a Peak Element II
int FindMaxNuminCol(vector<vector<int>> &mat, int n, int m, int midcol)
{
    int maxValCol = -1;
    int maxNumidx = -1;

    for (int i = 0; i < n; i++)
    {
        if (mat[i][midcol] > maxValCol)
        {
            maxValCol = mat[i][midcol];
            maxNumidx = i;
        }
    }
    return maxNumidx;
}

vector<int> findPeakGrid(vector<vector<int>> &mat)
{
    int n = mat.size();
    int m = mat[0].size();
    int low = 0;
    int high = m - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        int maxRowIdx = FindMaxNuminCol(mat, n, m, mid);
        int left = mid - 1 >= 0 ? mat[maxRowIdx][mid - 1] : -1;
        int right = mid + 1 < m ? mat[maxRowIdx][mid + 1] : -1;

        if (mat[maxRowIdx][mid] > left && mat[maxRowIdx][mid] > right)
        {
            return {maxRowIdx, mid};
        }
        else if (mat[maxRowIdx][mid] > left)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return {-1, -1};
}

// Median in a row-wise sorted Matrix
// need to find greater than (n*m)/2

int upperBound(vector<int> &arr, int target)
{
    return upper_bound(arr.begin(), arr.end(), target) - arr.begin();
}

int CountsmallerEqual(vector<vector<int>> &matrix, int n, int m, int mid)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        count += upperBound(matrix[i], mid); // Counting in each row
    }
    return count;
}

int median(vector<vector<int>> &matrix, int R, int C)
{
    int low = matrix[0][0];
    int high = matrix[R - 1][C - 1];
    int req = (R * C) / 2;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        int SmallerEquals = CountsmallerEqual(matrix, R, C, mid);

        if (SmallerEquals <= req)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return low;
}

// ************************* STRING EASY ***************************
// sort the string --> lexicographically

string sortlexicographically(string str)
{
    int n = str.size();
    vector<int> freq(26, 0);

    for (int i = 0; i < n; i++)
    {
        freq[str[i] - 'a']++;
    }

    int j = 0;
    for (int i = 0; i < freq.size(); i++)
    {
        while (freq[i]--)
        {
            str[j] = i + 'a';
            j++;
        }
    }
    return str;
}

// Anagram --> rearranging letters of a word to get another word

bool checkAnagram(string str, string t) // TC --> O(2*N)  SC --> O(1)
{
    int n = str.size();
    int m = t.size();
    map<char, int> freq;

    if (m != n)
    {
        return false;
    }

    for (int i = 0; i < n; i++)
    {
        freq[str[i]]++;
    }

    for (auto ch : t)
    {
        if (freq.find(ch) == freq.end() || freq[ch] == 0)
        {
            return false;
        }
        freq[ch]--;
    }
    return true;
}

// Check Isomorphic --> 1 to 1 mapping
bool checkIsomorphic(string str, string t)
{
    int n = str.size();
    int m = t.size();
    vector<int> s1(128, -1);
    vector<int> s2(128, -1);

    if (m != n)
    {
        return false;
    }

    for (int i = 0; i < n; i++)
    {
        if (s1[str[i]] != s2[t[i]])
        {
            return false;
        }
        s1[str[i]] = i;
        s2[str[i]] = i;
    }
    return true;
}

// // longest common prefix string among array
string longestCommonPrefix(vector<string> &str)
{
    int n = str.size();
    if (n == 0)
    {
        return "";
    }

    string mainStr = str[0];
    int count = mainStr.size();

    for (int i = 1; i < n; i++)
    {
        int j = 0;
        while (j < mainStr.size() && j < str[i].size() && mainStr[j] == str[i][j])
        {
            j++;
        }
        count = min(count, j);
    }

    string ans = mainStr.substr(0, count);
    return ans;
}

// Remove outermost Paranthesis
string removeOuterParentheses(string s)
{
    int n = s.size();
    string ans = "";
    int balance = 0;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
        {
            if (balance > 0)
            {
                ans += s[i];
            }
            balance++;
        }
        else if (s[i] == ')')
        {
            balance--;
            if (balance > 0)
            {
                ans += s[i];
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
        ans = "";
    }

    return finalAns;
}

// Largest Odd Number in String
string largestOddNumber(string str)
{
    int n = str.size();
    string largestOddNumber = "";

    for (int i = n - 1; i >= 0; i--)
    {
        if ((str[i] - '0') % 2 != 0)
        {
            largestOddNumber = str.substr(0, i + 1);
            break;
        }
    }
    return largestOddNumber;
}

// Rotate String
bool rotateString(string s, string goal)
{
    int n = s.size();
    int m = goal.size();

    if (n != m)
    {
        return false;
    }

    string doubleStr = s + s;
    return (doubleStr.find(goal) != string::npos);
}

// Sort Characters By Frequency
string frequencySort(string s)
{
    int n = s.size();
    unordered_map<char, int> mpp;

    for (int i = 0; i < n; i++)
    {
        mpp[s[i]]++;
    }

    vector<pair<char, int>> freqlist(mpp.begin(), mpp.end());
    sort(freqlist.begin(), freqlist.end(), [](const pair<char, int> &a, const pair<char, int> &b)
         { return a.second > b.second; });

    string result;
    for (auto &pair : freqlist)
    {
        result.append(pair.second, pair.first);
    }
    return result;
}

// Maximum Nesting Depth of the Parentheses
int maxDepth(string s)
{
    int n = s.size();
    int maxDepth = INT_MIN;
    int currDepth = 0;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
        {
            currDepth++;
            maxDepth = max(currDepth, maxDepth);
        }
        else if (s[i] == ')')
        {
            currDepth--;
        }
    }
    return maxDepth;
}

// Roman to Integer
int romanToInt(string s)
{
    int n = s.size();
    int total = 0;
    unordered_map<char, int> roman = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};

    for (int i = 0; i < n; i++)
    {
        if (i + 1 < n && roman[s[i]] < roman[s[i + 1]])
        {
            total -= roman[s[i]];
        }
        else
        {
            total += roman[s[i]];
        }
    }
    return total;
}

// String to Integer (atoi)
int myAtoi(string s)
{
    int n = s.size();
    int i = 0;

    // Check leading whitespace.
    while (i <= n && s[i] == ' ')
    {
        i++;
    }

    // Check sign character.
    int sign = 1;
    if (i < n && (s[i] == '+' || s[i] == '-'))
    {
        if (s[i] == '-')
        {
            sign = -1;
        }
        i++;
    }

    long long ans = 0;
    while (i < n && isdigit(s[i]))
    {
        ans = ans * 10 + (s[i] - '0');
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
long long int atMostKDistinct(string s, int k)
{
    long long int count = 0;
    int n = s.size();
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

long long int substrCount(string s, int k)
{
    if (k <= 0)
    {
        return 0;
    }

    return atMostKDistinct(s, k) - atMostKDistinct(s, k - 1);
}

// Longest Palindromic Substring
string longestPalindrome(string s)
{
    int n = s.length();
    string maxSubWord = "";
    int start = 0;
    int maxSubCount = 1;

    if (n == 0)
    {
        return "";
    }

    for (int i = 0; i < n; i++)
    {
        int left = i - 1;
        int right = i + 1;

        // ODD

        while (left >= 0 && right < n && s[left] == s[right])
        {
            if ((right - left + 1) > maxSubCount)
            {
                maxSubCount = right - left + 1;
                start = left;
            }
            left--;
            right++;
        }

        // EVEN
        left = i;
        right = i + 1;

        while (left >= 0 && right < n && s[left] == s[right])
        {
            if ((right - left + 1) > maxSubCount)
            {
                maxSubCount = right - left + 1;
                start = left;
            }
            left--;
            right++;
        }
    }
    return s.substr(start, maxSubCount);
}

// Sum of Beauty of All Substrings
int beautySum(string s)
{
    int n = s.size();
    int beautySum = 0;
    unordered_map<char, int> freq;
    int diffFreq;

    for (int i = 0; i < n; i++)
    {
        unordered_map<char, int> freq;

        for (int j = i; j < n; j++)
        {
            freq[s[j]]++;

            if (freq.size() >= 2)
            {
                int maxFreq = 0, minFreq = INT_MAX;
                for (auto &entry : freq)
                {
                    maxFreq = max(maxFreq, entry.second);
                    minFreq = min(minFreq, entry.second);
                }
                beautySum += (maxFreq - minFreq);
            }
        }
    }
    return beautySum;
}

int main()
{

    // vector<int> nums1 = {2, 3, 6, 7, 9};
    // vector<int> nums2 = {1, 4, 8, 10};
    // int k = 5;
    // int m = 2;
    // cout << "The largest minimum distance is: " << aggressiveCows(nums, k) << endl;
    // cout << "The largest minimum distance is: " << findPages(nums, n, m) << endl;
    // cout << "The splitArray is: " << splitArray(arr1, k) << endl;
    // cout << "The Painter's Partition Problem is: " << PainterPartition(arr1, k) << endl;
    // cout << "The Minimize Max Distance to Gas Station is: " << minimiseMaxDistance(arr1, k) << endl;
    // double median = findMedianSortedArrays(nums1, nums2);
    // cout << "The median is: " << median << endl;

    // int result = kthElement(k, nums1, nums2);
    // cout << "The " << k << "-th element is: " << result << endl;

    // vector<vector<int>> matrix = {
    //     {1, 3, 5},
    //     {2, 6, 9},
    //     {3, 6, 9}};
    // int target = 20;

    // int result = rowWithMax1s(matrix);
    // cout << "Row with max 1s index is: " << result << endl;

    // int result = searchMatrix(matrix, target);
    // cout << "Search a 2D Matrix: " << result << endl;

    // bool result = searchMatrix(matrix, target);
    // cout << "Search a 2D Matrix: " << (result ? "True" : "False") << endl;

    // vector<int> peak = findPeakGrid(matrix);
    // cout << "Peak element found at: [" << peak[0] << ", " << peak[1] << "]" << endl;

    // int R = matrix.size();
    // int C = matrix[0].size();

    // cout << "Median of the matrix is: " << median(matrix, R, C) << endl;

    string str = "aabcbaa";
    int k = 2;
    // string goal = "abced";

    // vector<string> strs = {"flower", "flow", "flight"};

    // auto result = sortlexicographically(str);
    // cout << "Sorted string: " << result << endl;

    // auto result = checkAnagram(str, t);
    // cout << "Sorted string: " << result << endl;

    // auto result = checkIsomorphic(str, t);
    // cout << "Sorted string: " << result << endl;

    // auto result = longestCommonPrefix(strs);
    // cout << "Sorted string: " << result << endl;

    // auto result = removeOuterParentheses(str);
    // cout << "Remove Outermost Parentheses: " << result << endl;

    // auto result = reverseWords(str);
    // cout << "Reverse Words in a String: " << result << endl;

    // auto result = largestOddNumber(str);
    // cout << "Largest Odd Number in String: " << result << endl;

    // auto result = rotateString(str, goal);
    // cout << "Rotate String: " << result << endl;

    // auto result = frequencySort(str);
    // cout << "Sort Characters By Frequency: " << result << endl;

    // auto result = maxDepth(str);
    // cout << "Maximum Nesting Depth of the Parentheses: " << result << endl;

    // auto result = romanToInt(str);
    // cout << "Roman to Integer: " << result << endl;

    // auto result = substrCount(str, k);
    // cout << "Count number of substrings: " << result << endl;

    // auto result = longestPalindrome(str);
    // cout << "Longest Palindromic Substring: " << result << endl;

    auto result = beautySum(str);
    cout << "Sum of Beauty of All Substrings: " << result << endl;

    return 0;
}