#include <bits/stdc++.h>
using namespace std;

// Greedy Algorithms
// Assign Cookies
int findContentChildren(vector<int> &g, vector<int> &s)
{
    int n = g.size();
    int m = s.size();
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int childIndex = 0;
    int cookieIndex = 0;
    int maxContent = 0;

    while (cookieIndex < m && childIndex < n)
    {
        if (s[cookieIndex] >= g[childIndex])
        {
            maxContent++;
            childIndex++;
        }
        cookieIndex++;
    }
    return maxContent;
}

int main()
{
    vector<int> g = {1, 2};
    vector<int> s = {1, 2, 3};
    cout << findContentChildren(g, s) << endl;
    return 0;
}
