#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

// Generate all binary strings without consecutive 1’s

void generateAllStringsfuther(char str[], int k, int currStart)
{

    if (currStart == k)
    {
        str[currStart] = '\0';
        cout << str << " ";
        return;
    }

    // currStart - 1 --> 1 0 _

    if (str[currStart - 1] == '1')
    {
        str[currStart] = '0';
        generateAllStringsfuther(str, k, currStart + 1);
    }

    if (str[currStart - 1] == '0')
    {
        // currStart - 0 --> 0 0 _
        str[currStart] = '0';
        generateAllStringsfuther(str, k, currStart + 1);

        // currStart - 0 --> 0 1 _

        str[currStart] = '1';
        generateAllStringsfuther(str, k, currStart + 1);
    }
}

void generateAllStrings(int k)
{
    if (k == 0)
    {
        cout << "";
        return;
    }

    char str[k];

    // start with 0 _ _
    str[0] = '0';
    generateAllStringsfuther(str, k, 1);

    // start with  1 _ _

    str[0] = '1';
    generateAllStringsfuther(str, k, 1);
}

// Generate Parentheses

void generateAllParentheses(vector<string> &result, int n, int open, int close, string currStr)
{
    if (currStr.length() == n * 2)
    {
        result.push_back(currStr);
        return;
    }

    if (open < n)
    {
        generateAllParentheses(result, n, open + 1, close, currStr + '(');
    }
    if (close < open)
    {
        generateAllParentheses(result, n, open, close + 1, currStr + ')');
    }
}

vector<string> generateParenthesis(int n) // TC --> O(n*2^n)  SC -->  O(n*2^n)
{
    vector<string> result;
    generateAllParentheses(result, n, 0, 0, "");
    return result;
}

// Generate Subsets

void generateAllSubset(vector<vector<int>> &result, int currIdx, vector<int> &nums, vector<int> &subset) // TC --> O(n*2^n)  SC -->  O(n*2^n)
{
    int n = nums.size();
    if (currIdx == n)
    {
        result.push_back(subset);
        return;
    }

    // NOT include that particular element
    generateAllSubset(result, currIdx + 1, nums, subset);

    // IF included that particular element
    subset.push_back(nums[currIdx]);
    generateAllSubset(result, currIdx + 1, nums, subset);
    // for back tracking so that next element gets thet org subset before inserting this element for its operation
    subset.pop_back();
}

vector<vector<int>> subsets(vector<int> &nums)
{
    // for n = 2^n substring can be Generated
    vector<vector<int>> result;
    vector<int> subset;
    generateAllSubset(result, 0, nums, subset);
    return result;
}

// Better String

void generateAllsubsequences(unordered_set<string> &result, int currIdx, string &str, string &subsequences) // TC --> O(n*2^n)  SC -->  O(n*2^n)
{
    int n = str.length();
    if (currIdx == n)
    {
        result.insert(subsequences);
        return;
    }

    // NOT include that particular element
    generateAllsubsequences(result, currIdx + 1, str, subsequences);

    // IF included that particular element
    subsequences.push_back(str[currIdx]);
    generateAllsubsequences(result, currIdx + 1, str, subsequences);
    // for back tracking so that next element gets thet org subset before inserting this element for its operation
    subsequences.pop_back();
}

unordered_set<string> subsequences(string &str)
{
    // for n = 2^n substring can be Generated
    unordered_set<string> result;
    string subsequences;
    generateAllsubsequences(result, 0, str, subsequences);
    return result;
}

string betterString(string str1, string str2)
{

    unordered_set<string> result1 = subsequences(str1);
    unordered_set<string> result2 = subsequences(str2);
    if (result2.size() > result1.size())
    {
        return str2;
    }
    else
    {
        return str1;
    }
}

// Perfect Sum Problem

int perfectSumHelper(int arr[], int n, int sum, int count, int currIdx)
{
    if (currIdx == n)
    {
        if (sum == 0)
        {
            count++;
        }
        return count;
    }

    // if the element is included
    count = perfectSumHelper(arr, n, sum - arr[currIdx], count, currIdx + 1);

    // if the element is exclude
    count = perfectSumHelper(arr, n, sum, count, currIdx + 1);

    return count;
}

int perfectSum(int arr[], int n, int sum) // TC --> O(n*2^n)  SC -->  O(1)
{
    return perfectSumHelper(arr, n, sum, 0, 0);
}

// Subset Sum
bool isSubsetPresentHelper(int n, int k, vector<int> &a, int currIdx, int currSum)
{
    if (k == currSum)
    {
        return true;
    }

    if (currIdx == n)
    {
        return false;
    }

    // if the element is included
    bool include = isSubsetPresentHelper(n, k, a, currIdx + 1, currSum + a[currIdx]);

    // if the element is exclude
    bool exclude = isSubsetPresentHelper(n, k, a, currIdx + 1, currSum);

    return include || exclude;
}

bool isSubsetPresent(int n, int k, vector<int> &a)
{
    return isSubsetPresentHelper(n, k, a, 0, 0);
}

// Combination Sum

void combinationSumHelper(vector<int> &candidates, int target, vector<vector<int>> &ans, vector<int> &subset, int currIdx, int n)
{
    if (currIdx == n)
    {
        if (target == 0)
        {
            ans.push_back(subset);
        }
        return;
    }

    if (target < 0 || currIdx == n)
    {
        return;
    }

    // if the element is included
    subset.push_back(candidates[currIdx]);
    combinationSumHelper(candidates, target - candidates[currIdx], ans, subset, currIdx, n);
    subset.pop_back();

    // if the element is exclude
    combinationSumHelper(candidates, target, ans, subset, currIdx + 1, n);
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target) // TC --> O(2^n)  SC -->  O(k*2^n)
{
    int n = candidates.size();
    vector<vector<int>> ans;
    vector<int> subset;
    combinationSumHelper(candidates, target, ans, subset, 0, n);
    return ans;
}

// Combination Sum II
void combinationSumHelper(vector<int> &candidates, int target, set<vector<int>> &ansSet, vector<int> &subset, int currIdx)
{

    if (target == 0)
    {
        ansSet.insert(subset);
        return;
    }

    if (target < 0 || currIdx == candidates.size())
    {
        return;
    }

    // if the element is included
    for (int i = currIdx; i < candidates.size(); i++)
    {
        if (i > currIdx && candidates[i] == candidates[i - 1])
        {
            continue;
        }
        subset.push_back(candidates[i]);
        combinationSumHelper(candidates, target - candidates[i], ansSet, subset, i + 1);
        subset.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{

    int n = candidates.size();
    sort(candidates.begin(), candidates.end());
    set<vector<int>> ansSet;
    vector<int> subset;
    combinationSumHelper(candidates, target, ansSet, subset, 0);
    vector<vector<int>> ans(ansSet.begin(), ansSet.end());
    return ans;
}

// Subset Sums
void subsetSumsHelper(vector<int> &arr, vector<int> &ans, int currIdx, int sum)
{
    if (currIdx == arr.size())
    {
        ans.push_back(sum);
        return;
    }

    // Include the current element
    subsetSumsHelper(arr, ans, currIdx + 1, sum + arr[currIdx]);

    // Exclude the current element
    subsetSumsHelper(arr, ans, currIdx + 1, sum);
}

vector<int> subsetSums(vector<int> arr, int n) // TC --> O(2^n)  SC --> O(2^n)
{
    vector<int> ans;
    subsetSumsHelper(arr, ans, 0, 0);
    sort(ans.begin(), ans.end());
    return ans;
}

int main()
{
    // int n = 3;
    // string str1 = "abc";
    // string str2 = "bdb";
    vector<int> arr = {5, 2, 1};
    int k = 8;

    cout << "Display Array: ";
    for (int i; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // cout << "Binary strings of size " << k << " without consecutive 1's: ";
    // generateAllStrings(k);
    // cout << endl;
    // cout << "str1: " << str1 << endl;
    // cout << "N: " << n << endl;

    // vector<string> result = generateParenthesis(n);

    // cout << "Generate Parentheses: " << result.size() << endl;
    // for (const auto &str : result)
    // {
    //     cout << str << " ";
    // }

    // vector<int> nums = {1, 2, 3, 4, 5};
    // vector<vector<int>> result = subsets(nums);

    // cout << "Generate Subsets: " << result.size() << endl;
    // for (const auto &subset : result)
    // {
    //     cout << "{ ";
    //     for (int num : subset)
    //     {
    //         cout << num << " ";
    //     }
    //     cout << "} ";
    // }
    // cout << endl;

    // cout << "Better String: " << betterString(str1, str2) << endl;
    // cout << "Perfect Sum Problem: " << perfectSum(arr, n, sum) << endl;
    // cout << "Is Subset sum: " << isSubsetPresent(arr.size(), k, arr) << endl;

    // vector<vector<int>> result = combinationSum(arr, k);

    // cout << "Combination Sum: " << result.size() << endl;
    // for (const auto &subset : result)
    // {
    //     cout << "{ ";
    //     for (int num : subset)
    //     {
    //         cout << num << " ";
    //     }
    //     cout << "} ";
    // }
    // cout << endl;

    // vector<vector<int>> result = combinationSum2(arr, k);

    // cout << "Combination Sum 2: " << result.size() << endl;
    // for (const auto &subset : result)
    // {
    //     cout << "{ ";
    //     for (int num : subset)
    //     {
    //         cout << num << " ";
    //     }
    //     cout << "}, ";
    // }
    // cout << endl;

    vector<int> result = subsetSums(arr, arr.size());

    cout << "Subset Sums: ";
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}