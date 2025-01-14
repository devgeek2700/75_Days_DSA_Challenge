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

// Pascal's Triangle
vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> ans;

    for (int i = 0; i < numRows; i++)
    {
        vector<int> row(i + 1, 1);

        for (int j = 1; j < i; j++)
        {
            row[j] = ans[i - 1][j - 1] + ans[i - 1][j];
        }
        ans.push_back(row);
    }
    return ans;
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

//  Subarrays with XOR ‘K’

// int subarraysWithSumK(vector<int> arr, int b)  // TC  --> O(n^2)
// {
//     int n = arr.size();
//     int count = 0;
//     for (int i = 0; i < n; i++)
//     {
//         int Xor = 0;
//         for (int j = i; j < n; j++)
//         {
//             Xor = Xor ^ arr[j];
//             if (Xor == b)
//             {
//                 count++;
//             }
//         }
//     }
//     return count;
// }

int subarraysWithSumK(vector<int> arr, int b) // TC  --> O(n)*nlogn   SC --> O(n)
{
    int n = arr.size();
    int count = 0;
    int xr = 0;
    map<int, int> mapp;
    mapp[xr]++; // {0,1}

    for (int i = 0; i < n; i++)
    {
        xr = xr ^ arr[i];
        int x = xr ^ b;
        count += mapp[x];
        mapp[xr]++;
    }
    return count;
}

//  Merge All Overlapping Intervals

// vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> &arr)
// { // TC --> O(nlogn)+O(2n)
//     int n = arr.size();
//     sort(arr.begin(), arr.end());

//     vector<vector<int>> ans;

//     for (int i = 0; i < n; i++)
//     {
//         int start = arr[i][0];
//         int end = arr[i][1];
//         if (!ans.empty() && end <= ans.back()[1])
//         {
//             continue;
//         }
//         for (int j = i + 1; j < n; j++)
//         {
//             if (arr[j][0] <= end)
//             {
//                 end = max(arr[j][1], end);
//             }
//             else
//             {
//                 break;
//             }
//         }
//         ans.push_back({start, end});
//     }

//     return ans;
// }

// Optimal soln
vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> &arr)
{ // TC --> O(nlogn)    SC --> )(n)
    int n = arr.size();
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;

    for (int i = 0; i < n; i++)
    {
        if (ans.empty() || arr[i][0] > ans.back()[1])
        {
            ans.push_back(arr[i]);
        }
        else
        {
            ans.back()[1] = max(ans.back()[1], arr[i][1]);
        }
    }

    return ans;
}

//  Merge Two Sorted Arrays Without Extra Space
// void mergeTwoSortedArraysWithoutExtraSpace(vector<long long> &a, vector<long long> &b)
// {  // TC--> O(n+m)+O(n+m)   SC --> O(n+m)
//     int n = a.size();
//     int m = b.size();
//     int left = 0;
//     int right = 0;
//     int index = 0;
//     long long temp[n + m];

//     while (left < n && right < m)
//     {
//         if (a[left] <= b[right])
//         {
//             temp[index] = a[left];
//             left++;
//             index++;
//         }
//         else
//         {
//             temp[index] = b[right];
//             right++;
//             index++;
//         }
//     }

//     while (left < n)
//     {
//         temp[index++] = a[left++];
//     }

//     while (right < m)
//     {
//         temp[index++] = b[right++];
//     }

//     for (int i = 0; i < n+m; i++)
//     {
//         if (i < n)
//         {
//             a[i] = temp[i];
//         }
//         else
//         {
//             b[i - n] = temp[i];
//         }
//     }
// }

// Optimal soln
void mergeTwoSortedArraysWithoutExtraSpace(vector<long long> &a, vector<long long> &b)
{ // TC--> O(min(n,m))+O(nlogn)+O(mlogm)   SC --> O(1)
    int n = a.size();
    int m = b.size();
    int left = n - 1;
    int right = 0;

    while (left >= 0 && right < m)
    {
        if (a[left] > b[right])
        {
            swap(a[left], b[right]);
            left--;
            right++;
        }
        else
        {
            break;
        }
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
}

//  Missing And Repeating Numbers
// vector<int> findMissingRepeatingNumbers(vector<int> a) { // TC --> O(n^2)   SC --> O(1)
//     int repeatVal = -1;
//     int missingVal = -1;

//     for(int i = 1; i <= a.size(); i++) {
//         int count = 0;
//         for(int j = 0; j < a.size(); j++) {
//             if(a[j] == i) {
//                 count++;
//             }
//         }
//         if(count == 2) {
//             repeatVal = i;
//         } else if(count == 0) {
//             missingVal = i;
//         }

//         if(missingVal != -1 && repeatVal != -1) {
//             break;
//         }
//     }

// return {repeatVal, missingVal};

// }

// Better soln
// vector<int> findMissingRepeatingNumbers(vector<int> a)
// { // TC --> O(n)   SC --> O(1)
//     int n = a.size();
//     int hash[n + 1] = {0};
//     for (int i = 0; i < n; i++)
//     {
//         hash[a[i]]++; // incraete the val by 1
//     }

//     int repeatVal = -1;
//     int missingVal = -1;
//     for (int i = 1; i <= n; i++)
//     {
//         if (hash[i] == 2)
//         {
//             repeatVal = i;
//         }
//         else if (hash[i] == 0)
//         {
//             missingVal = i;
//         }

//         if (missingVal != -1 && repeatVal != -1)
//         {
//             break;
//         }
//     }

//     return {repeatVal, missingVal};
// }

// Optimal soln  --> (Maths Soln)
// 1 to n = n*(n+1)/2
// 1^2 to n^2 = n*(n+1)*(2n+1)/6

vector<int> findMissingRepeatingNumbers(vector<int> a)
{ // TC --> O(n)  SC --> O(1)
    long long n = a.size();
    long long SN = (n * (n + 1)) / 2;
    long long S2N = (n * (n + 1) * (2 * n + 1)) / 6;
    long long S = 0, S2 = 0;

    for (int i = 0; i < n; i++)
    {
        S += a[i];
        S2 += (long long)a[i] * a[i];
    }
    long long val1 = S - SN;   // X - Y
    long long val2 = S2 - S2N; // X^2 - Y^2
    val2 /= val1;              // Divide by X - Y

    long long X = (val1 + val2) / 2; // X = (X - Y + X^2 - Y^2) / 2
    long long Y = X - val1;          // Y = X - (X - Y)

    return {(int)X, (int)Y};
}

//  Number of Inversions

// int numberOfInversions(vector<int>&a, int n) { // TC --> O(n^2)  SC --> O(1)
//     int count = 0;
//     for(int i = 0; i < n; i++){
//         for(int j = i+1; j<n; j++){
//             if(a[i] > a[j]){
//                 count++;
//             }
//         }
//     }
//        return count;
// }

// Optimal soln
// int merge(vector<int> &arr, int low, int mid, int high)
// {
//     vector<int> temp;
//     int left = low;
//     int right = mid + 1;

//     // Modification 1: cnt variable to count the pairs:
//     int cnt = 0;

//     while (left <= mid && right <= high)
//     {
//         if (arr[left] <= arr[right])
//         {
//             temp.push_back(arr[left]);
//             left++;
//         }
//         else
//         {
//             temp.push_back(arr[right]);
//             cnt += (mid - left + 1); // Modification 2
//             right++;
//         }
//     }

//     while (left <= mid)
//     {
//         temp.push_back(arr[left]);
//         left++;
//     }

//     while (right <= high)
//     {
//         temp.push_back(arr[right]);
//         right++;
//     }

//     for (int i = low; i <= high; i++)
//     {
//         arr[i] = temp[i - low];
//     }

//     return cnt; // Modification 3
// }

// int mergeSort(vector<int> &arr, int low, int high)
// {
//     int cnt = 0;
//     if (low >= high)
//         return cnt;
//     int mid = (low + high) / 2;
//     cnt += mergeSort(arr, low, mid);      // left half
//     cnt += mergeSort(arr, mid + 1, high); // right half
//     cnt += merge(arr, low, mid, high);    // merging sorted halves
//     return cnt;
// }

// int numberOfInversions(vector<int> &a, int n)
// { // TC --> O(nlogn)  SC --> O(n)
//     return mergeSort(a, 0, n - 1);
// }



//  Team Contest or Reverse Pairs

// int team(vector<int>& skill, int n) {  // TC --> O(N^2)  SC --> O(1)
//     int count = 0;
//     for(int i = 0; i < n; i++) {
//         for(int j = i + 1; j < n; j++) {
//             if(skill[i] > 2 * skill[j]) {
//                 count++;
//             } 
//         }
//     }
//     return count; 
// }


// Optimal soln
void countPairs(vector<int>& arr, int low, int mid, int high, int& count) {
    int right = mid + 1;
    for (int i = low; i <= mid; i++) {
        while (right <= high && arr[i] > 2 * arr[right]) {
            right++;
        }
        count += (right - (mid + 1));
    }
}

void merge(vector<int>& arr, int low, int mid, int high) {
    vector<int> temp;
    int left = low;
    int right = mid + 1;

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        } else {
            temp.push_back(arr[right]);
            right++;
        }
    }

    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}

void mergeSort(vector<int>& arr, int low, int high, int& count) {
    if (low >= high)
        return;
    int mid = (low + high) / 2;
    mergeSort(arr, low, mid, count);      // left half
    mergeSort(arr, mid + 1, high, count); // right half
    countPairs(arr, low, mid, high, count);
    merge(arr, low, mid, high);           // merging sorted halves
}

int team(vector<int>& skill, int n) {  // Tc --> O(2nlogn)  SC --> O(n)
    int count = 0;
    mergeSort(skill, 0, n - 1, count);
    return count;
}

//  Subarray With Maximum Product

// int subarrayWithMaxProduct(vector<int> &arr){  // TC --> O(n^2)  SC --> O(1)
//     int n = arr.size();
//     int maxProduct = INT_MIN;

//     for(int i = 0; i<n; i++){
//         int currProduct = 1;
//         for(int j = i; j<n; j++){
//             currProduct *= arr[j];
//             maxProduct = max(maxProduct, currProduct);
//         }
//     }
//     return maxProduct;
// }

// Optimal soln
int subarrayWithMaxProduct(vector<int> &arr){  // TC --> O(n)  SC --> O(1)
    int n = arr.size();
    int maxProduct = INT_MIN;
    int prefixSum = 1;
    int SuffixSum = 1;

    for(int i = 0; i<n; i++){
        if(prefixSum == 0){
            prefixSum = 1;
        }
        if(SuffixSum == 0){
            SuffixSum = 1;
        }

        prefixSum *= arr[i];
        SuffixSum *= arr[n-i-1];

        maxProduct = max(maxProduct, max(prefixSum, SuffixSum));
    }

    return maxProduct;
}


int main()
{

    // int n, m;
    // cout << "Enter the number of rows (n): ";
    // cin >> n;
    // cout << "Enter the number of columns (m): ";
    // cin >> m;

    vector<int> a = {-1, 3, 0, -4, 3};
    // vector<long long> b = {2, 3, 4 ,5};
    int n = a.size();
    // int m = b.size();
    int k = 3;
    int target = 0;
    cout << "Vector Values a: ";
    for (auto it : a)
    {
        cout << it << " ";
    }
    cout << endl;

    // cout << "Vector Values b: ";
    // for (auto it : b)
    // {
    //     cout << it << " ";
    // }
    // cout << endl;

    // vector<vector<int>> varr = {{1, 3}, {2, 6}, {8, 9}, {9, 11}, {8, 10}, {8, 4}, {15, 18}, {16, 17}};
    // int k = 3;
    // int target = 0;

    // cout << "Vector Values: ";
    // for (auto it : varr)
    // {
    //     cout << "("; // Add opening bracket before each pair
    //     for (auto num : it)
    //     {
    //         cout << num << " ";
    //     }
    //     cout << ") "; // Add closing bracket after each pair
    // }
    // cout << endl;

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
    // auto result = getLongestZeroSumSubarrayLength(varr);
    // auto result = subarraysWithSumK(varr, k);
    // auto result = mergeOverlappingIntervals(varr);
    // mergeTwoSortedArraysWithoutExtraSpace(a, b);
    // findMissingRepeatingNumbers(a);
    // auto result = numberOfInversions(a, a.size());
    // auto result = team(a, a.size());
    auto result = subarrayWithMaxProduct(a);

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
    // cout << " Longest Subarray With Zero Sum: " << result << endl;

    // cout << "Subarrays with XOR 'k': " << result << endl;

    // cout << "Answer Values: ";
    // for (auto it : result)
    // {
    //     cout << "("; // Add opening bracket before each pair
    //     for (auto num : it)
    //     {
    //         cout << num << " ";
    //     }
    //     cout << ") "; // Add closing bracket after each pair
    // }
    // cout << endl;

    //   cout << "Merge Two Sorted Arrays Without Extra Space: ";
    // for (auto it : a) {
    //     cout << it << " ";
    // }
    // for (auto it : b) {
    //     cout << it << " ";
    // }
    // cout << endl;

    // cout << "Missing And Repeating Numbers: ";
    // for (auto it : result)
    // {
    //     cout << it << " ";
    // }
    // cout << endl;

    // cout << " Number of Inversions: " << result << endl;

    // cout << "Reverse Pairs: " << result << endl;

    cout << "Subarray With Maximum Product: " << result << endl;

    return 0;
}