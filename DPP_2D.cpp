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
int uniquePathsWithObstaclesHelper(vector<vector<int>> &obstacleGrid, int row, int col, vector<vector<int>> &dp)
{
    if (row == 0 && col == 0)
    {
        return obstacleGrid[row][col] == 1 ? 0 : 1;
    }

    if (row >= 0 && col >= 0 && obstacleGrid[row][col] == 1)
    {
        return 0;
    }

    if (row < 0 || col < 0)
    {
        return 0;
    }

    if (dp[row][col] != -1)
    {
        return dp[row][col];
    }

    int up = uniquePathsWithObstaclesHelper(obstacleGrid, row - 1, col, dp);
    int left = uniquePathsWithObstaclesHelper(obstacleGrid, row, col - 1, dp);

    return dp[row][col] = up + left;
}

// Memoization                          recusion stack space and dp array
int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) // TC --> O(n*m) SC --> O(n-1)(m-1)  + O(n*m)
{
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return uniquePathsWithObstaclesHelper(obstacleGrid, m - 1, n - 1, dp);
}

// Minimum Path Sum
int minPathSumHelper(vector<vector<int>> &grid, int row, int col, vector<vector<int>> &dp)
{
    if (row == 0 && col == 0)
    {
        return grid[0][0];
    }

    if (row < 0 || col < 0)
    {
        return INT_MAX;
    }

    if (dp[row][col] != -1)
    {
        return dp[row][col];
    }

    int up = minPathSumHelper(grid, row - 1, col, dp);
    int left = minPathSumHelper(grid, row, col - 1, dp);

    return dp[row][col] = grid[row][col] + min(up, left);
}

// Memoization                          recusion stack space and dp array
int minPathSum(vector<vector<int>> &grid) // TC --> O(n*m) SC --> O(n-1)(m-1)  + O(n*m)
{
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return minPathSumHelper(grid, m - 1, n - 1, dp);
}

int main()
{
    // int m = 3, n = 2;
    vector<vector<int>> grid = {{1, 2, 3}, {4, 5, 6}};
    // cout << "Unique Paths: " << uniquePaths(m, n) << endl;
    // cout << "Unique Paths II: " << uniquePathsWithObstacles(obstacleGrid) << endl;
    cout << "Minimum Path Sum: " << minPathSum(grid) << endl;

    return 0;
}