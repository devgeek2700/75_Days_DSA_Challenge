#include <bits/stdc++.h>
using namespace std;

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

int main()
{
    // int n = 3;

    // cout << "Binary strings of size " << k << " without consecutive 1's: ";
    // generateAllStrings(k);
    // cout << endl;
    // cout << "N: " << n << endl;

    // vector<string> result = generateParenthesis(n);

    // cout << "Generate Parentheses: " << result.size() << endl;
    // for (const auto &str : result)
    // {
    //     cout << str << " ";
    // }

    vector<int> nums = {1, 2, 3, 4, 5};
    vector<vector<int>> result = subsets(nums);

    cout << "Generate Subsets: " << result.size() << endl;
    for (const auto &subset : result)
    {
        cout << "{ ";
        for (int num : subset)
        {
            cout << num << " ";
        }
        cout << "} ";
    }
    cout << endl;

    return 0;
}