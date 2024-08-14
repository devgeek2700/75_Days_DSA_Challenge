#include <bits/stdc++.h>
using namespace std;

// magnitude easy
void maxoftwoOperations()
{
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    long long Cp = 0;
    long long Cn = 0;

    for (int i = 0; i < n; i++)
    {
        long long new_pos = max(Cp + a[i], abs(Cp + a[i]));
        long long new_neg = max(Cn + a[i], abs(Cn + a[i]));
        Cp = new_pos;
        Cn = new_neg;
    }

    int ans = max(Cp, Cn);
    cout << "Max: " << max(Cp, Cn) << endl;
}

// IQ test
void IQtestEvenness()
{
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> even_indices;
    vector<int> odd_indices;

    for (int i = 1; i < n; i++)
    {
        cin >> a[i];
        if (a[i] % 2 == 0)
        {
            even_indices.push_back(i);
        }
        else
        {
            odd_indices.push_back(i);
        }
    }

    if (odd_indices.size() == 1)
    {
        cout << odd_indices[0] << endl;
    }
    else
    {
        cout << even_indices[0] << endl;
    }
}

// Registration system
void RegistrationSystem(int n, const vector<string> &names)
{
    unordered_map<string, int> database;

    for (int i = 0; i < n; ++i)
    {
        string name = names[i];

        if (database.find(name) == database.end())
        {
            // Name is unique
            database[name] = 1;
            cout << "OK" << endl;
        }
        else
        {
            // Name already exists, find the next unique name
            int count = database[name];
            string newName = name + to_string(count);
            while (database.find(newName) != database.end())
            {
                count++;
                newName = name + to_string(count);
            }
            database[name] = count + 1;
            database[newName] = 1;
            cout << newName << endl;
        }
    }
}

void tPrimeNumber(int n, vector<int> varr)
{

    for (int i = 0; i < n; i++)
    {
        int idx = i * i;

        for (int j = 0; j < n; j++)
        {
            if (idx == varr[j])
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
    }
}

// Palindrome String
bool isPalindrome(const string &s)
{
    int left = 0, right = s.size() - 1;
    while (left < right)
    {
        if (s[left] != s[right])
            return false;
        left++;
        right--;
    }
    return true;
}

// Function to find the longest palindrome that can be formed
string longestpalindrome(vector<string> &str)
{
    int n = str.size();
    unordered_set<string> strSet;
    unordered_map<string, string> reverseMap;
    string leftpart = "";
    string centralpart = "";
    string rightpart = "";

    // Populate the set and reverse map
    for (const string &s : str)
    {
        strSet.insert(s);
        reverseMap[s] = string(s.rbegin(), s.rend());
    }

    for (const string &s : str)
    {
        string reversedStr = reverseMap[s];

        if (strSet.find(reversedStr) != strSet.end() && reversedStr != s)
        {
            leftpart += s;
            rightpart = reversedStr + rightpart;
            strSet.erase(s);
            strSet.erase(reversedStr);
        }
        else if (isPalindrome(s) && s.size() > centralpart.size())
        {
            centralpart = s;
        }
    }
    return leftpart + centralpart + rightpart;
}

int minimumTaxReport(int n, int d, vector<int> &varr)
{
    int totalSalary = accumulate(varr.begin(), varr.end(), 0);

    int maxExclusion = 0;

    for (int i = 1; i <= n; ++i)
    {
        int currentExclusion = (n / i) * (i / d);
        maxExclusion = max(maxExclusion, currentExclusion);
    }

    int finalTaxReport = totalSalary - maxExclusion;
    return finalTaxReport;
}

// max Ribbon Pieces
int maxRibbonPiecesHelper(int n, int a, int b, int c, vector<int> dp)
{
    if (n == 0)
    {
        return 0;
    }

    if (n < 0)
    {
        return INT_MIN;
    }

    if (dp[n] != -1)
    {
        return dp[n];
    }

    int cutA = maxRibbonPiecesHelper(n - a, a, b, c, dp) + 1;
    int cutB = maxRibbonPiecesHelper(n - b, a, b, c, dp) + 1;
    int cutC = maxRibbonPiecesHelper(n - c, a, b, c, dp) + 1;

    dp[n] = max({cutA, cutB, cutC});
    return dp[n];
}

int maxRibbonPieces(int n, int a, int b, int c)
{
    vector<int> dp(n + 1, -1);
    return maxRibbonPiecesHelper(n, a, b, c, dp);
}

// Sort the Array
bool isSorted(const vector<int> &varr)
{
    for (int i = 0; i < varr.size() - 1; ++i)
    {
        if (varr[i] > varr[i + 1])
        {
            return false;
        }
    }
    return true;
}

void sortArrayoneway(vector<int> &varr)
{
    int n = varr.size();

    if (isSorted(varr))
    {
        cout << "yes" << endl;
        cout << "1 1" << endl;
        return;
    }

    int l = 0;
    int r = n - 1;

    while (l < n - 1 && varr[l] < varr[l + 1])
    {
        ++l;
    }

    while (r > 0 && varr[r] > varr[r - 1])
    {
        --r;
    }

    reverse(varr.begin() + l, varr.begin() + r + 1);

    if (isSorted(varr))
    {
        cout << "yes" << endl;
        cout << l + 1 << " " << r + 1 << endl;
    }
    else
    {
        cout << "no" << endl;
    }
}

// Pashmak and Flowers
void maxbeauties(vector<int> &beauties)
{
    int max_beauty = *max_element(beauties.begin(), beauties.end());
    int min_beauty = *min_element(beauties.begin(), beauties.end());

    long long max_diff = max_beauty - min_beauty;

    long long count_max = count(beauties.begin(), beauties.end(), max_beauty);
    long long count_min = count(beauties.begin(), beauties.end(), min_beauty);

    long long ways;
    if (max_diff == 0)
    {
        ways = (count_max * (count_max - 1)) / 2;
    }
    else
    {
        ways = count_max * count_min;
    }
    cout << max_diff << " " << ways << endl;
}

int main()
{
    // int t;
    // cin >> t;
    // while (t--)
    // {
    //     maxoftwoOperations();
    // }

    // // IQtestEvenness();

    // vector<string> names = {"abc", "abc", "abc", "def", "def", "abc1"};
    // RegistrationSystem(names.size(), names);

    // vector<int> varr = {4, 5, 6};
    // tPrimeNumber(varr.size(), varr);

    // vector<string> input = {"aplpw", "racecar", "qokos", "racecar", "amkxjo", "qjoww"};
    // string result = longestpalindrome(input);
    // cout << result << endl;

    // int n = 4;
    // int d = 2;
    // vector<int> varr = {4, 4, 5, 4};
    // cout << "Val: " << minimumTaxReport(n, d, varr) << endl;

    // int n, a, b, c;
    // cin >> n >> a >> b >> c;

    // cout << maxRibbonPieces(n, a, b, c) << endl;
    // vector<int> varr = {3, 2, 1};
    // sortArrayoneway(varr);

    vector<int> beauties = {3, 1, 2, 3, 1};
    maxbeauties(beauties);

    return 0;
}