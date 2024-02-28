#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> markRow(vector<vector<int>> &matrix, int i, int m)
{
    for (int j = 0; j < m; j++)
    {
        if (matrix[i][j] != 0)
        {
            matrix[i][j] = -1;
        }
    }
    return matrix;
}

vector<vector<int>> markColumn(vector<vector<int>> &matrix, int j, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (matrix[i][j] != 0)
        {
            matrix[i][j] = -1;
        }
    }
    return matrix;
}

vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int n, int m)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                markRow(matrix, i, m);
                markColumn(matrix, j, n);
            }
        }
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == -1)
            {
                matrix[i][j] = 0;
            }
        }
    }

    return matrix;
}

//  Print Pascal’s Triangle
// type of question asked
// 1) print the element row and column of that place
// 2) print the Nth row of the traingle
// 3) print the entire tree of the pascal triangle

// 1) print the element row and column of that place
// nCn = n!/n!*(n-r)!
// 7C3 = 7*6*5/1*2*3  -> formula

int pascalTriangleRownCol(int N, int Row)
{ // TC --> O(row) SC --> O(1)
    int res = 1;

    for (int i = 0; i < Row; i++)
    {
        res = res * (N - i);
        res = res / (i + 1);
    }
    return res;
}

// 2) print the Nth row of the traingle
// 5 --> 1 || 5/1 || 5*4/1*2 || 5*4*3*2/1*2*3*4

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

// 3) print the entire tree of the pascal triangle

vector<vector<int>> generatepascalTriangle(int N)
{
    vector<vector<int>> triangle;

    if (N == 0 || N == 1)
    {
        return triangle;
    }

    triangle.push_back({1});

    for (int row = 1; row < N; row++)
    {
        vector<int> currRow;
        currRow.push_back(1);

        for (int col = 1; col < row; col++)
        {
            int val = triangle[row - 1][col - 1] + triangle[row - 1][col];
            currRow.push_back(val);
        }
        currRow.push_back(1);
        triangle.push_back(currRow);
    }
    return triangle;
}

int main()
{

    // int n, m;
    // cout << "Enter the number of rows (n): ";
    // cin >> n;
    // cout << "Enter the number of columns (m): ";
    // cin >> m;

    // Input matrix
    // vector<vector<int>> matrix(n, vector<int>(m));
    // cout << "Enter the elements of the matrix:" << endl;
    // for (int i = 0; i < n; ++i)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         cin >> matrix[i][j];
    //     }
    // }

    // Displaying the input matrix
    // cout << "Dsiplay Matrix for" << n << "x" << m << " is:" << endl;
    // for (int i = 0; i < n; ++i)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         cout << matrix[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    //    zeroMatrix(matrix, n, m);
    int n = 1;
    int r = 2;
    int c = 2;
    // int result = pascalTriangleRownCol(n - 1, r - 1);
    auto result = generatepascalTriangle(n);

    // cout << "Set Zero Matrix for" << n << "x" << m << " is:" << endl;
    // for (int i = 0; i < n; ++i)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         cout << matrix[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // cout << "the element row and column using Pascal: " << result << endl;
    cout << "the Nth row of the traingle: ";
    pascalTriangleprintRow(n - 1);
    cout << endl;

    cout << "Print Pascal’s Triangle:" << endl;
    for (const auto &row : result)
    {
        for (int num : row)
        {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}