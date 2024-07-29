#include <bits/stdc++.h>
using namespace std;

// Rules for 2D matrix --> recursion
// 1) Express the index of (i, j) i --> row && j --> col
// 2) Do all stuffs on this indexes
// 3) Sum/Min/Max up all ways

// Unique Paths

int uniquePathsHelper(int row, int col, vector<vector<int>> &dp)
{
    if (row == 0 && col == 0)
    {
        return 1;
    }

    if (row < 0 || col < 0)
    {
        return 0;
    }

    if (dp[row][col] != -1)
    {
        return dp[row][col];
    }

    int up = uniquePathsHelper(row - 1, col, dp);
    int left = uniquePathsHelper(row, col - 1, dp);

    return dp[row][col] = up + left;
}

// Memoization                          recusion stack space and dp array
int uniquePaths(int m, int n) // TC --> O(n*m) SC --> O(n-1)(m-1)  + O(n*m)
{
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return uniquePathsHelper(m - 1, n - 1, dp);
}

// Unique Paths II
int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
{
    
}

int main()
{
    // int m = 3, n = 2;
    vector<vector<int>> obstacleGrid = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    // cout << "Unique Paths: " << uniquePaths(m, n) << endl;
    cout << "Unique Paths II: " << uniquePathsWithObstacles(obstacleGrid) << endl;

    return 0;
}