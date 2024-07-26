#include <bits/stdc++.h>
using namespace std;
// HOW TO KNOW IS THIS S DP PROBLEM?
// count total no of ways
// multiple ways but give me min/max

// SHORTCUT
//  try to repsresnt the problem in terms of index
// Do all possible stuffs on that and the all to the problem
// count all ways then --> sum of all stuffs
// find min/max --> find min/max of all stuffs

// Rescusion ha soverlaping subproblems it is solve by DP
// Rescusion --> top down (required answer to base case )
// DP
//  types
//  1) Tabulation  --> Bottom up (base case to required answer)
//  2) Memoization   --> tend to store the value of subproblems in some Map/table

// Fibonacci Numbers
// Memoization                            recusion stack space and dp array
int Fibonacci(int n, vector<int> &dp) // TC --> O(N) SC --> O(N) + O(N)
{
    if (n <= 1)
    {
        return n;
    }

    if (dp[n] != -1)
    {
        return dp[n];
    }
    return dp[n] = Fibonacci(n - 1, dp) + Fibonacci(n - 2, dp);
}

// Tabulation                                            only dp array
int Fibonaccit(int n, vector<int> &dp) // TC --> O(N) SC -->  O(N)
{
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

// Space Optimization
int Fibonaccits(int n, vector<int> &dp) // TC --> O(N) SC -->  O(1)
{
    int prev2 = 0;
    int prev1 = 1;

    for (int i = 2; i <= n; i++)
    {
        int curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

// Climbing Stairs
int climbStairsHelper(int n, vector<int> &dp)
{
    if (n <= 1)
    {
        return 1;
    }

    if (dp[n] != -1)
    {
        return dp[n];
    }

    return dp[n] = climbStairsHelper(n - 1, dp) + climbStairsHelper(n - 2, dp);
}

// Memoization               recusion stack space and dp array
int climbStairs(int n) // TC --> O(N) SC --> O(N) + O(N)
{
    vector<int> dp(n + 1, -1);
    return climbStairsHelper(n, dp);
}

int climbStairsHelpert(int n, vector<int> &dp)
{
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}
// Tabulation
int climbStairst(int n) // TC --> O(N) SC -->  O(N)
{
    vector<int> dp(n + 1, -1);
    return climbStairsHelpert(n, dp);
}

// frog Jump
int minimumEnergyHelper(vector<int> &height, int n, vector<int> &dp)
{
    if (n == 0)
    {
        return 0;
    }

    if (dp[n] != -1)
    {
        return dp[n];
    }

    int left = minimumEnergyHelper(height, n - 1, dp) + abs(height[n] - height[n - 1]);

    int right = INT_MAX; // Initialize to a large number
    if (n > 1)
    {
        right = minimumEnergyHelper(height, n - 2, dp) + abs(height[n] - height[n - 2]);
    }

    return dp[n] = min(left, right);
}

// Memoization                                 recusion stack space and dp array
int minimumEnergy(vector<int> &height, int n) // TC --> O(N) SC --> O(N) + O(N)
{
    vector<int> dp(n + 1, -1);
    return minimumEnergyHelper(height, n - 1, dp);
}

int minimumEnergyHelpert(vector<int> &height, int n, vector<int> &dp)
{
    dp[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        int left = dp[i - 1] + abs(height[i] - height[i - 1]);
        int right = INT_MAX;
        if (i > 1)
        {
            right = dp[i - 2] + abs(height[i] - height[i - 2]);
        }
        dp[i] = min(left, right);
    }
    return dp[n];
}

// Tabulation                dp array
int minimumEnergyt(vector<int> &height, int n) // TC --> O(N) SC --> O(N)
{
    vector<int> dp(n + 1, -1);
    return minimumEnergyHelpert(height, n - 1, dp);
}

// Minimal Cost by k steps
int minimizeCostHelper(vector<int> &height, int n, int k, vector<int> &dp)
{
    if (n == 0)
    {
        return 0;
    }

    if (dp[n] != -1)
    {
        return dp[n];
    }

    int minSteps = INT_MAX;

    for (int j = 1; j <= k; j++)
    {
        if (n - j >= 0)
        {
            int jump = minimizeCostHelper(height, n - j, k, dp) + abs(height[n] - height[n - j]);
            minSteps = min(jump, minSteps);
        }
    }
    return dp[n] = minSteps;
}

// Memoization               recusion stack space and dp array
int minimizeCost(vector<int> &height, int n, int k) // TC --> O(N) SC --> O(N) + O(N)
{
    vector<int> dp(n, -1);
    return minimizeCostHelper(height, n - 1, k, dp);
}

// Tabulation approach
int minimizeCostktHelper(vector<int> &height, int n, int k, vector<int> &dp)
{
    dp[0] = 0;

    for (int i = 1; i < n; i++)
    {
        int minSteps = INT_MAX;
        for (int j = 1; j <= k; j++)
        {
            if (i - j >= 0)
            {
                int jump = dp[i - j] + abs(height[i] - height[i - j]);
                minSteps = min(jump, minSteps);
            }
        }
        dp[i] = minSteps;
    }

    return dp[n - 1];
}

// Tabulation                                                         dp array
int minimizeCostkt(vector<int> &height, int n, int k) // TC --> O(N) SC --> O(N)
{
    vector<int> dp(n, INT_MAX);
    return minimizeCostktHelper(height, n, k, dp);
}

// House Robber
int robHelper(vector<int> &nums, int n, vector<int> &dp)
{
    if (n < 0)
    {
        return 0;
    }

    if (n == 0)
    {
        return nums[0];
    }

    if (dp[n] != -1)
    {
        return dp[n];
    }

    int pickedIdx = nums[n] + robHelper(nums, n - 2, dp);
    int notpickedIdx = robHelper(nums, n - 1, dp);

    return dp[n] = max(pickedIdx, notpickedIdx);
}

// Memoization               recusion stack space and dp array
int rob(vector<int> &nums) // TC --> O(N) SC --> O(N) + O(N)
{
    int n = nums.size();
    if (n == 0)
        return 0;
    vector<int> dp(n, -1);
    return robHelper(nums, n - 1, dp);
}

int robHelpert(vector<int> &nums, int n, vector<int> &dp)
{
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return nums[0];
    }

    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);

    for (int i = 2; i < n; i++)
    {
        dp[i] = max(nums[i] + dp[i - 2], dp[i - 1]);
    }

    return dp[n - 1];
}

// Tabulation                                  dp array
int robt(vector<int> &nums) // TC --> O(N) SC --> O(N)
{
    int n = nums.size();
    if (n == 0)
        return 0;
    vector<int> dp(n, -1);
    return robHelpert(nums, n, dp);
}

// House Robber II arranged in circle
int robHelper(vector<int> &nums, int start, int end, vector<int> &dp)
{
    if (start > end)
    {
        return 0;
    }

    if (start == end)
    {
        return nums[start];
    }

    if (dp[start] != -1)
    {
        return dp[start];
    }

    // so even can we out first val and calulate on rest -->  ans 1
    // or we can leave out last val and calulate on rest -->  ans 2
    // ans = max(ans 1, ans 2)

    int robCurrent = nums[start] + robHelper(nums, start + 2, end, dp);
    int skipCurrent = robHelper(nums, start + 1, end, dp);

    return dp[start] = max(robCurrent, skipCurrent);
}

// Memoization

int rob2(vector<int> &nums) // TC --> O(N) SC --> O(N) + O(N)
{
    int n = nums.size();
    if (n == 0)
        return 0;
    if (n == 1)
        return nums[0];

    vector<int> dp1(n, -1);
    int robFirstHouse = robHelper(nums, 0, n - 2, dp1);

    vector<int> dp2(n, -1);
    int robLastHouse = robHelper(nums, 1, n - 1, dp2);

    return max(robFirstHouse, robLastHouse);
}

int robHelpert(const vector<int> &nums, int start, int end)
{
    int n = end - start + 1;
    if (n == 0)
        return 0;
    if (n == 1)
        return nums[start];

    vector<int> dp(n, 0);
    dp[0] = nums[start];
    dp[1] = max(nums[start], nums[start + 1]);

    for (int i = 2; i < n; ++i)
    {
        dp[i] = max(dp[i - 1], nums[start + i] + dp[i - 2]);
    }

    return dp[n - 1];
}
// Tabulation
int rob2t(vector<int> &nums) // TC --> O(N) SC --> O(N)
{
    int n = nums.size();
    if (n == 0)
        return 0;
    if (n == 1)
        return nums[0];

    int robFirstHouse = robHelpert(nums, 0, n - 2);
    int robLastHouse = robHelpert(nums, 1, n - 1);

    return max(robFirstHouse, robLastHouse);
}

// Geek's Training
int maximumPointsHelper(const vector<vector<int>> &arr, int day, int last, int n, vector<vector<int>> &dp)
{
    if (day == 0)
    {
        int maxPoints = 0;
        for (int i = 0; i < n; i++)
        {
            if (i != last)
            {
                maxPoints = max(maxPoints, arr[day][i]);
            }
        }
        return maxPoints;
    }

    if (last != -1 && dp[day][last] != -1)
    {
        return dp[day][last];
    }

    int maxPoints = 0;
    for (int i = 0; i < n; i++)
    {
        if (i != last)
        {
            int CurrPoints = arr[day][i] + maximumPointsHelper(arr, day - 1, i, n, dp);
            maxPoints = max(maxPoints, CurrPoints);
        }
    }

    if (last != -1)
    {
        dp[day][last] = maxPoints;
    }

    return maxPoints;
}

// Memoization
int maximumPoints(vector<vector<int>> &arr, int n) // TC --> O(N) SC --> O(3*N) + O(3*N)
{
    int days = arr.size();
    if (days == 0)
        return 0;
    vector<vector<int>> dp(days, vector<int>(n, -1));
    return maximumPointsHelper(arr, days - 1, -1, n, dp);
}

int main()
{
    int n = 3;
    int k = 1;
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> arr = {{10, 40, 70}, {20, 50, 80}, {30, 60, 90}};
    // cout << "Value is: " << Fibonacci(n, dp) << endl;
    // cout << "Value t is: " << Fibonaccit(n, dp) << endl;
    // cout << "Value sop is: " << Fibonaccits(n, dp) << endl;

    // cout << "climbStairs is: " << climbStairs(n) << endl;
    // cout << "climbStairs t is: " << climbStairst(n) << endl;

    // cout << "climbStairs is: " << minimumEnergy(height, n) << endl;
    // cout << "climbStairs t is: " << minimumEnergyt(height, n) << endl;

    // cout << "Minimum energy required: " << minimizeCost(height, n, k) << endl;
    // cout << "Minimum energy required t: " << minimizeCostkt(height, n, k) << endl;

    // cout << "House Robber: " << rob(nums) << endl;
    // cout << "House Robber t: " << robt(nums) << endl;

    // cout << "House Robber II: " << rob2(nums) << endl;
    // cout << "House Robber t II: " << rob2t(nums) << endl;

    cout << "Geek's Training: " << maximumPoints(arr, arr[0].size()) << endl;

    return 0;
}