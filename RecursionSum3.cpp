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

// N-Queens

bool canFill(int row, int currCol, vector<string> &board, int n)
{
    int i, j;
    // check upper left diagonal
    for (i = row, j = currCol; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 'Q')
        {
            return false;
        }
    }

    // check row-wise
    for (i = row, j = currCol; j >= 0; j--)
    {
        if (board[i][j] == 'Q')
        {
            return false;
        }
    }

    // check lower right diagonal
    for (i = row, j = currCol; i < n && j >= 0; i++, j--)
    {
        if (board[i][j] == 'Q')
        {
            return false;
        }
    }

    return true;
}

void solveNQueensHelper(int n, vector<string> &board, vector<vector<string>> &res, int currCol)
{
    if (currCol == n)
    {
        res.push_back(board);
    }

    for (int i = 0; i < n; i++)
    {
        if (canFill(i, currCol, board, n))
        {
            board[i][currCol] = 'Q';
            solveNQueensHelper(n, board, res, currCol + 1);
            board[i][currCol] = '.';
        }
    }
}

vector<vector<string>> solveNQueens(int n)
{
    vector<vector<string>> res;
    vector<string> board(n);
    string s(n, '.');
    for (int i = 0; i < n; i++)
    {
        board[i] = s;
    }

    solveNQueensHelper(n, board, res, 0);
    return res;
}

// Rat in a Maze Problem - I
void findPathHelper(vector<vector<int>> &m, int n, vector<string> &ans, vector<vector<int>> &visitArr, int row, int col, string move)
{
    if (row == n - 1 && col == n - 1)
    {
        ans.push_back(move);
        return;
    }
    // Mark the current cell as visited
    visitArr[row][col] = 1;

    // Downward
    if (row + 1 < n && !visitArr[row + 1][col] && m[row + 1][col] == 1)
    {
        findPathHelper(m, n, ans, visitArr, row + 1, col, move + "D");
    }

    // Leftward
    if (col - 1 >= 0 && !visitArr[row][col - 1] && m[row][col - 1] == 1)
    {
        findPathHelper(m, n, ans, visitArr, row, col - 1, move + "L");
    }

    // Rightward
    if (col + 1 < n && !visitArr[row][col + 1] && m[row][col + 1] == 1)
    {
        findPathHelper(m, n, ans, visitArr, row, col + 1, move + "R");
    }

    // Upward
    if (row - 1 >= 0 && !visitArr[row - 1][col] && m[row - 1][col] == 1)
    {
        findPathHelper(m, n, ans, visitArr, row - 1, col, move + "U");
    }

    // Backtrack: Unmark the current cell
    visitArr[row][col] = 0;
}

vector<string> findPath(vector<vector<int>> &m, int n) // TC --> O(4^n*m) SC --> O(n*m)
{
    vector<string> ans;
    vector<vector<int>> visitArr(n, vector<int>(n, 0));

    if (m[0][0] == 1)
    {
        findPathHelper(m, n, ans, visitArr, 0, 0, "");
    }

    if (ans.empty())
    {
        ans.push_back("-1");
    }

    return ans;
}

// Word Break

bool wordBreakHelper(const string &s, const unordered_set<string> &dict, int start)
{
    if (start == s.length())
    {
        return true;
    }

    for (int end = start + 1; end <= s.length(); end++)
    {
        if (dict.find(s.substr(start, end - start)) != dict.end() && wordBreakHelper(s, dict, end))
        {
            return true;
        }
    }
    return false;
}

bool wordBreak(string s, vector<string> &wordDict)
{
    unordered_set<string> dict(wordDict.begin(), wordDict.end());
    return wordBreakHelper(s, dict, 0);
}

// M-Coloring Problem
bool isSafe(bool graph[101][101], int n, int color[], int node, int col)
{
    for (int i = 0; i < n; i++)
    {
        if (graph[node][i] && color[i] == col)
        {
            return false;
        }
    }
    return true;
}

bool graphColoringHelper(bool graph[101][101], int m, int n, int color[], int node)
{
    if (node == n)
    {
        return true;
    }

    for (int i = 1; i <= m; i++)
    {
        if (isSafe(graph, n, color, node, i))
        {
            color[node] = i;
            if (graphColoringHelper(graph, m, n, color, node + 1))
            {
                return true;
            }
            color[node] = 0;
        }
    }
    return false;
}

bool graphColoring(bool graph[101][101], int m, int n) // TC --> O(N^m) SC --> O(2*n)
{
    int color[101] = {0};
    if (graphColoringHelper(graph, m, n, color, 0))
    {
        return true;
    }

    return false;
}

// Sudoku Solver

void displayBoard(const vector<vector<char>> &board)
{
    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            if (j == 3 || j == 6)
                cout << " | ";
            cout << board[i][j] << " ";
        }
        cout << endl;
        if (i == 2 || i == 5)
            cout << "-------+-------+-------" << endl;
    }
}

void vectorToBoard(const vector<char> &vectorBoard, vector<vector<char>> &board)
{
    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            board[i][j] = vectorBoard[i * 9 + j];
        }
    }
}

// *********** sum ***********

bool checkrthreeules(vector<vector<char>> &board, int row, int col, char ch)
{
    for (int i = 0; i < 9; i++)
    {
        if (board[i][col] == ch)
        {
            return false;
        }

        if (board[row][i] == ch)
        {
            return false;
        }

        if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == ch)
        {
            return false;
        }
    }
    return true;
}

bool solveSudokuHelper(vector<vector<char>> &board)
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board.size(); j++)
        {
            if (board[i][j] == '.')
            {
                for (char ch = '1'; ch <= '9'; ch++)
                {
                    if (checkrthreeules(board, i, j, ch))
                    {
                        board[i][j] = ch;

                        if (solveSudokuHelper(board) == true)
                        {
                            return true;
                        }
                        else
                        {
                            board[i][j] = '.';
                        }
                    }
                }
            return false;
            }
        }
    }
    return true;
}

void solveSudoku(vector<vector<char>> &board)
{
    solveSudokuHelper(board);
}

int main()
{
    // int n = 1;
    // cout << "the value of n: " << n << endl;

    // vector<vector<int>> arr = {{1, 0},
    //                            {1, 0}};

    // int numVertices = 101;

    // vector<pair<int, int>> edges = {
    //     {0, 1},
    //     {1, 2},
    //     {0, 2}};

    // bool graph[101][101] = {false}; // Initialize the adjacency matrix with false (0)

    // // Populate the adjacency matrix using the edges
    // for (const auto &edge : edges)
    // {
    //     int u = edge.first;
    //     int v = edge.second;
    //     graph[u][v] = true;
    //     graph[v][u] = true; // Since the graph is undirected
    // }
    // string word = "leetcode";
    // vector<string> wordDict = {"leet", "code"};

    // cout << "Word: " << word << endl;

    // Display the graph
    // cout << "Graph adjacency matrix:" << endl;
    // for (int i = 0; i < 101; i++)
    // {
    //     for (int j = 0; j < 101; j++)
    //     {
    //         cout << graph[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // for (const auto &row : wordDict)
    // {
    //     for (char i : row)
    //     {
    //         cout << i;
    //     }
    //     cout << endl;
    // }

    // bool result = exist(board, word);
    // cout << "Word Search result: " << result << endl;

    // vector<vector<string>> result = solveNQueens(n);
    // cout << "N Queens: " << endl;
    // for (const auto &board : result)
    // {
    //     for (const auto &row : board)
    //     {
    //         for (char ch : row)
    //         {
    //             cout << ch << " ";
    //         }
    //         cout << endl;
    //     }
    //     cout << endl;
    // }

    // vector<string> result = findPath(arr, 2);
    // cout << "Rat in a Maze: " << endl;
    // for (const auto &path : result)
    // {
    //     for (char ch : path)
    //     {
    //         cout << ch << " ";
    //     }
    //     cout << endl;
    // }

    // bool result = wordBreak(word, wordDict);
    // cout << "Word Break: " << result << endl;
    // int m = 2; // Number of colors
    // bool result = graphColoring(graph, m, 3);
    // cout << "M-Coloring Problem: " << (result ? "Possible" : "Not Possible") << endl;

    vector<char> initialVector = {
        '5', '3', '.', '.', '7', '.', '.', '.', '.',
        '6', '.', '.', '1', '9', '5', '.', '.', '.',
        '.', '9', '8', '.', '.', '.', '.', '6', '.',
        '8', '.', '.', '.', '6', '.', '.', '.', '3',
        '4', '.', '.', '8', '.', '3', '.', '.', '1',
        '7', '.', '.', '.', '2', '.', '.', '.', '6',
        '.', '6', '.', '.', '.', '.', '2', '8', '.',
        '.', '.', '.', '4', '1', '9', '.', '.', '5',
        '.', '.', '.', '.', '8', '.', '.', '7', '9'};

    vector<vector<char>> board(9, vector<char>(9, '.'));
    vectorToBoard(initialVector, board);

    cout << "Initial Board:" << endl;
    displayBoard(board);

    solveSudoku(board);

    cout << "\nSolved Board:" << endl;
    displayBoard(board);

    return 0;
}