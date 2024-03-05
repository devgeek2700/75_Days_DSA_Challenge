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

//  Majority Element greater than floor(N / 3)

vector<int> majorityElement(vector<int> v)
{
    int n = v.size();
    vector<int> answer;
    map<int, int> map;

    for (auto it : v)
    {
        map[it]++;
    }

    int floorVal = floor(n / 3);
    for (auto val : map)
    {
        if (val.second > floorVal)
        {
            answer.push_back(val.first);
        }
    }
    return answer;
}

//  Three Sum
// brute force soln
// vector<vector<int>> triplet(int n, vector<int> &arr) // TC --> O(n^3)
// {
//     vector<vector<int>> tripletValues;
//     set<vector<int>> st;
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = i + 1; j < n; j++)
//         {
//             for (int k = j + 1; k < n; k++)
//             {
//                 if (arr[i] + arr[j] + arr[k] == 0)
//                 {
//                     vector<int> currVal = {arr[i], arr[j], arr[k]};
//                     sort(currVal.begin(), currVal.end());
//                     st.insert(currVal);
//                 }
//             }
//         }
//     }

//     for (const auto val : st)
//     {
//         tripletValues.push_back(val);
//     }

//     return tripletValues;
// }

// better soln
// vector<vector<int>> triplet(int n, vector<int> &arr) // TC --> O(n^2)   SC --> O(n)
// {
//     vector<vector<int>> tripletValues;
//     set<vector<int>> st;
//     for (int i = 0; i < n; i++)
//     {
//         set<int> hashset;
//         for (int j = i + 1; j < n; j++)
//         {
//             int third = -(arr[i] + arr[j]);
//             if (hashset.find(third) != hashset.end())
//             {
//                 vector<int> currVal = {arr[i], arr[j], third};
//                 sort(currVal.begin(), currVal.end());
//                 st.insert(currVal);
//             }
//             hashset.insert(arr[j]);
//         }
//     }

//     for (const auto val : st)
//     {
//         tripletValues.push_back(val);
//     }

//     return tripletValues;
// }

// Optimal soln
vector<vector<int>> triplet(int n, vector<int> &arr)
{ // TC --> O(nlogn)*O(n^2)
    vector<vector<int>> tripletValues;
    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; i++)
    {
        if (i > 0 && arr[i] == arr[i - 1])
        {
            continue;
        }

        int j = i + 1;
        int k = n - 1;
        while (j < k)
        {
            int sum = arr[i] + arr[j] + arr[k];
            if (sum < 0)
            {
                j++;
            }
            else if (sum > 0)
            {
                k--;
            }
            else
            {
                vector<int> currVal = {arr[i], arr[j], arr[k]};
                tripletValues.push_back(currVal);
                j++;
                k--;

                while (j < k && arr[j] == arr[j - 1])
                {
                    j++;
                }
                while (j < k && arr[k] == arr[k + 1])
                {
                    k--;
                }
            }
        }
    }

    return tripletValues;
}

// Four Sum
// brute force
// vector<vector<int>> fourSum(vector<int> &arr, int target) // TC --> O(n^4)
// {
//     int n = arr.size();
//     vector<vector<int>> quadruplets;
//     set<vector<int>> st;
//     int count = 0;

//     for (int i = 0; i < n; i++)
//     {
//         for (int j = i + 1; j < n; j++)
//         {
//             for (int k = j + 1; k < n; k++)
//             {
//                 for (int l = k + 1; l < n; l++)
//                 {
//                     if (arr[i] + arr[j] + arr[k] + arr[l] == target)
//                     {
//                         vector<int> currVal = {arr[i], arr[j], arr[k], arr[l]};
//                         sort(currVal.begin(), currVal.end());
//                         st.insert(currVal);
//                     }
//                 }
//             }
//         }
//     }

//     for (const auto val : st)
//     {
//         quadruplets.push_back(val);
//     }

//     return quadruplets;
// }

// optimal soln
vector<vector<int>> fourSum(vector<int> &arr, int target)
{
    int n = arr.size();
    vector<vector<int>> quadruplets;
    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; i++)
    {
        if (i > 0 && arr[i] == arr[i - 1])
        {
            continue;
        }

        for (int j = i + 1; j < n; j++)
        {
            if (j > i + 1 && arr[j] == arr[j - 1])
            {
                continue;
            }

            int k = j + 1;
            int l = n - 1;

            while (k < l)
            {
                int sum = arr[i] + arr[j] + arr[k] + arr[l];
                if (sum < target)
                {
                    k++;
                }
                else if (sum > target)
                {
                    l--;
                }
                else
                {
                    quadruplets.push_back({arr[i], arr[j], arr[k], arr[l]});
                    k++;
                    l--;

                    while (k < l && arr[k] == arr[k - 1])
                    {
                        k++;
                    }
                    while (k < l && arr[l] == arr[l + 1])
                    {
                        l--;
                    }
                }
            }
        }
    }

    return quadruplets;
}

//  Longest Subarray With Zero Sum

// int getLongestZeroSumSubarrayLength(vector<int> &arr){
// 	int maxlen = 0;
//     int n = arr.size();
//     for (int i = 0; i < n; i++) {
//         int sum = 0;
//         for (int j = i; j < n; j++) {
//             sum += arr[j];
//             if (sum == 0) {
//                 maxlen = max(maxlen, j - i + 1);
//             }
//         }
//     }
//     return maxlen;

// }

// optimal soln
int getLongestZeroSumSubarrayLength(vector<int> &arr)
{ // TC --> O(nlogn)  SC --> O(n)
    int maxlen = 0;
    int sum = 0;
    int n = arr.size();
    unordered_map<int, int> umap;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum == 0)
        {
            maxlen = i + 1;
        }
        else
        {
            if (umap.find(sum) != umap.end())
            {
                maxlen = max(maxlen, i - umap[sum]);
            }
            else
            {
                umap[sum] = i;
            }
        }
    }
    return maxlen;
}

int subarraysWithSumK(vector < int > a, int b) {
    
}

int subarraysWithSumK1(vector < int > a, int b) {
    
}

int main()
{

    // int n, m;
    // cout << "Enter the number of rows (n): ";
    // cin >> n;
    // cout << "Enter the number of columns (m): ";
    // cin >> m;
    vector<int> varr = {1, 1};
    int target = 0;
    cout << "Vector Values: ";
    for (auto it : varr)
    {
        cout << it << " ";
    }
    cout << endl;

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
    // int n = 1;
    // int r = 2;
    // int c = 2;
    // int result = pascalTriangleRownCol(n - 1, r - 1);
    // auto result = generatepascalTriangle(n);
    // auto result = majorityElement(varr);
    // auto result = triplet(varr.size(), varr);
    // auto result = fourSum(varr, target);
    auto result = getLongestZeroSumSubarrayLength(varr);

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
    // cout << "the Nth row of the traingle: ";
    // pascalTriangleprintRow(n - 1);
    // cout << endl;

    // cout << "Print Pascal’s Triangle:" << endl;
    // for (const auto &row : result)
    // {
    //     for (int num : row)
    //     {
    //         cout << num << " ";
    //     }
    //     cout << endl;
    // }

    // cout << " Majority Element of floor n/3: ";
    // for (auto it : result)
    // {
    //     cout << it << " ";
    // }
    // cout << endl;

    // cout << "Three Sum: ";
    // for (const auto &triplet : result)
    // {
    //     for (int num : triplet)
    //     {
    //         cout << num << " ";
    //     }
    //     cout << "| ";
    // }
    // cout << endl;

    // cout << "Four Sum: ";
    // for (auto &quad : result)
    // {
    //     cout << "[ ";
    //     for (auto num : quad)
    //     {
    //         cout << num << " ";
    //     }
    //     cout << "] ";
    // }
    // cout << endl;

    // cout << "Four Sum Count is: " << result.size() << endl;
    cout << " Longest Subarray With Zero Sum: " << result << endl;
    return 0;
}