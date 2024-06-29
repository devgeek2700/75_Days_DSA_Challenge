#include <bits/stdc++.h>
using namespace std;

// Palindrome Partitioning

bool isPalindrome(string &str, int start, int end)
{
    while (start <= end)
    {
        if (str[start] != str[end])
            return false;
        start++;
        end--;
    }
    return true;
}

void partitionHelper(string &str, int currIdx, vector<string> &subset, vector<vector<string>> &ansSet)
{
    if (currIdx == str.length())
    {
        ansSet.push_back(subset);
        return;
    }

    for (int i = currIdx; i < str.length(); i++)
    {
        if (isPalindrome(str, currIdx, i))
        {
            subset.push_back(str.substr(currIdx, i - currIdx + 1));
            partitionHelper(str, i + 1, subset, ansSet);
            subset.pop_back();
        }
    }
}

vector<vector<string>> partition(string s)
{
    vector<vector<string>> ansSet;
    vector<string> subset;
    partitionHelper(s, 0, subset, ansSet);
    return ansSet;
}

// Word Search

bool existHelper(vector<vector<char>> &board, string word, int row, int col, int currIdx)
{
    if (currIdx == word.length())
    {
        return true;
    }

    if (row < 0 || col < 0 || row >= board.size() || col >= board[0].size())
    {
        return false;
    }

    if (board[row][col] != word[currIdx])
    {
        return false;
    }

    char temp = board[row][col];
    board[row][col] = '#';
    // right                                                     // left                                                 // up                                                 // down
    bool found = existHelper(board, word, row + 1, col, currIdx + 1) || existHelper(board, word, row - 1, col, currIdx + 1) || existHelper(board, word, row, col - 1, currIdx + 1) || existHelper(board, word, row, col + 1, currIdx + 1);
    board[row][col] = temp;
    return found;
}

bool exist(vector<vector<char>> &board, string word) // TC --> O(n*m*4^n)  SC --> O(word.len)
{
    int bn = board.size();
    int wn = word.size();
    if (bn == 0 || wn == 0)
    {
        return false;
    }

    for (int i = 0; i < bn; i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            if (existHelper(board, word, i, j, 0))
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    vector<vector<char>> board = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}};
    string word = "ABCB";

    cout << "Board characters: " << endl;
    for (const auto &row : board)
    {
        for (char ch : row)
        {
            cout << ch << " ";
        }
        cout << endl;
    }

    cout << "Word to search: " << word << endl;

    bool result = exist(board, word);
    cout << "Word Search result: " << result << endl;

    return 0;
}