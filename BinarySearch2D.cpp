#include <bits/stdc++.h>
using namespace std;

// Binary Search on 2D Arrays

//  Row with max 1s

int lowerBound(vector<int> arr, int n, int x)
{
    int low = 0;
    int high = n - 1;
    int ans = n;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] >= x)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

int rowWithMax1s(vector<vector<int>> &matrix, int n, int m) // TC --> O(nlogn2)  Sc--> O(1)
{
    int maxCount = 0;
    int maxIdx = -1;
    for (int i = 0; i < n; i++)
    {
        int count_ones = m - lowerBound(matrix[i], m, 1);
        if (count_ones > maxCount)
        {
            maxCount = count_ones;
            maxIdx = i;
        }
    }
    return maxIdx;
}

//  Search In A 2D Matrix
// row --> ind / m
// column --> ind % m

bool searchMatrix(vector<vector<int>> &mat, int target)
{

    int n = mat.size();
    int m = mat[0].size();

    int low = 0;
    int high = (n * m - 1);

    while (low <= high)
    {
        int mid = (low + high) / 2;
        int row = mid / m;
        int col = mid % m;

        if (mat[row][col] == target)
        {
            return true;
        }
        else if (mat[row][col] > target)
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

//  Search In A Sorted 2D Matrix - II
bool searchElementII(vector<vector<int>> &MATRIX, int target)
{ // TC --> O(n+m)
    int n = MATRIX.size();
    int m = MATRIX[0].size();

    int row = 0;
    int col = m - 1;
    while (row < n && col >= 0)
    {
        if (MATRIX[row][col] == target)
        {
            return true;
        }
        else if (MATRIX[row][col] < target)
        {
            row++;
        }
        else
        {
            col--;
        }
    }
    return false;
}

//  Find A Peak Element in 2D Matrix

int FindMaxNuminCol(vector<vector<int>> &g, int n, int m, int midcol)
{
    int maxValCol = -1;
    int maxNumidx = -1;

    for (int i = 0; i < n; i++)
    {
        if (g[i][midcol] > maxValCol)
        {
            maxValCol = g[i][midcol];
            maxNumidx = i;
        }
    }
    return maxNumidx;
}

vector<int> findPeakGrid(vector<vector<int>> &g)
{
    int n = g.size();
    int m = g[0].size();
    int low = 0;
    int high = m - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        int maxRowIdx = FindMaxNuminCol(g, n, m, mid);
        int left = mid - 1 >= 0 ? g[maxRowIdx][mid - 1] : -1;
        int right = mid + 1 < m ? g[maxRowIdx][mid + 1] : -1;

        if (g[maxRowIdx][mid] > left && g[maxRowIdx][mid] > right)
        {
            return {maxRowIdx, mid};
        }
        else if (g[maxRowIdx][mid] < left)
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

//  Median in a row-wise sorted Matrix

int upperBound(vector<int> &arr, int x, int n) // TC --> O(logn)  SC --> O(1)
{
    int low = 0;
    int high = n - 1;
    int ans = n;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] > x)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

int CountsmallerEqual(vector<vector<int>> &matrix, int n, int m, int mid)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        count += upperBound(matrix[i], mid, m);
    }
    return count;
}

int median2DArray(vector<vector<int>> &matrix, int n, int m)
{
    int low = INT_MAX;
    int high = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        low = min(low, matrix[i][0]);
        high = max(high, matrix[i][m - 1]);
    }

    int req = (n * m) / 2;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int SmallerEquals = CountsmallerEqual(matrix, n, m, mid);
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

int main()
{
    vector<vector<int>> matrix = {{1, 5, 7, 9, 11},
                                  {2, 3, 4, 8, 9},
                                  {4, 11, 14, 19, 20},
                                  {6, 10, 22, 99, 100},
                                  {7, 15, 17, 24, 28}};

    int n = matrix.size();
    int m = matrix[0].size();
    int target = 80;

    cout << "Display 2D Matrix: " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;

    // int max1sRow = rowWithMax1s(matrix, n, m);
    // cout << "Row with maximum 1s: " << max1sRow << endl;

    // int max1sRow = searchMatrix(matrix, target);
    // cout << "Search In A 2D Matrix: " << max1sRow << endl;

    // int max1sRow = searchElementII(matrix, target);
    // cout << "Search In A 2D Matrix - II: " << max1sRow << endl;

    // vector<int> result = findPeakGrid(matrix);
    // cout << "Find A Peak Element: (" << result[0] << ", " << result[1] << ")" << endl;

    int max1sRow = median2DArray(matrix, n, m);
    cout << "Median in a row-wise sorted Matrix: " << max1sRow << endl;

    return 0;
}