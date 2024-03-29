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



int main()
{
    vector<vector<int>> matrix = {
        {1, 2, 4},
        {6, 7, 8},
        {9, 10, 34}};

    int n = matrix.size();
    int m = matrix[0].size();
    int target = 78;

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

    int max1sRow = searchMatrix(matrix, target);
    cout << "Search In A 2D Matrix: " << max1sRow << endl;

    return 0;
}





#include <bits/stdc++.h> 
string sentenceSorting(string &str) {
    stringstream ss(str);
    vector<pair<string, int>> words; // Store each word along with its suffix number

    string word;
    while (ss >> word) {
        int suffix = word.back() - '0'; // Extract the suffix number from the word
        word.pop_back(); // Remove the suffix number from the word
        words.push_back({word, suffix});
    }

    // Sort the words based on their suffix numbers
    sort(words.begin(), words.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
        return a.second < b.second;
    });

    // Reconstruct the sorted words into a new string
    string result;
    for (const auto& w : words) {
        result += w.first + " ";
    }
    result.pop_back(); // Remove the extra space at the end

    return result;
}