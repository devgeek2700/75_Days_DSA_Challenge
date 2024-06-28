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

int main()
{
    string str = "a";

    cout << "str:  " << str << endl;

    cout << "Palindrome Partitioning: ";
    vector<vector<string>> result = partition(str);

    for (const auto &combination : result)
    {
        for (const auto &word : combination)
        {
            cout << word << " ";
        }
        cout << endl;
    }

    return 0;
}