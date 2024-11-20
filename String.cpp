#include <bits/stdc++.h>
using namespace std;

// sort the string --> lexicographically

string sortlexicographically(string str) // TC --> O(2*N)  SC --> O(256)
{
    int n = str.length();
    vector<int> freq(26, 0);

    for (int i = 0; i < n; i++)
    {
        freq[str[i] - 'a']++;
    }

    int j = 0;
    for (int i = 0; i < freq.size(); i++)
    {
        while (freq[i]--)
        {
            str[j] = i + 'a';
            j++;
        }
    }
    return str;
}


bool checkAnagram(string str, string t) // TC --> O(2*N)  SC --> O(1)
{
    int n = str.length();
    int m = t.length();
    int count = 0;
    map<char, int> freq;

    if (m != n)
    {
        return false;
    }

    for (char c : str)
    {
        freq[c]++;
    }

    for (char c : t)
    {
        if (freq.find(c) == freq.end() || freq[c] == 0)
        {
            return false;
        }
        freq[c]--;
    }

    return true;
}

// Check Isomorphic --> 1 to 1 mapping
bool checkIsomorphic(string str, string t) // TC --> O(N) SC --> O(1)
{
    int n = str.length();
    int m = t.length();
    vector<int> s1(128, -1);
    vector<int> s2(128, -1);

    if (m != n)
    {
        return false;
    }

    for (int i = 0; i < n; i++)
    {
        if (s1[str[i]] != s2[t[i]])
        {
            return false;
        }
        s1[str[i]] = i;
        s2[t[i]] = i;
    }
    return true;
}

// longest common prefix string among array
// bructe force
string longestCommonPrefix1(vector<string> str) // TC --> O(Nlogn*m) + O(min(firtsstr, laststr))  SC --> O(1)
{
    int n = str.size();
    sort(str.begin(), str.end());

    string firstStr = str[0];
    string lastStr = str[n - 1];

    int i = 0;
    int j = 0;
    string ans = "";

    while (i < firstStr.size() && j < lastStr.size())
    {
        if (firstStr[i] == lastStr[j])
        {
            ans += lastStr[j];
            i++;
            j++;
        }
        else
        {
            break;
        }
    }
    return ans;
}

// Better approach
string longestCommonPrefix(vector<string> &str) // TC --> O(n*m)  SC --> O(1)
{
    int n = str.size();
    if (n == 0)
        return "";

    string mainStr = str[0];
    int count = mainStr.size();

    for (int i = 1; i < n; i++)
    {
        int j = 0;
        while (j < mainStr.size() && j < str[i].size() && mainStr[j] == str[i][j])
        {
            j++;
        }
        count = min(count, j);
    }

    string ans = mainStr.substr(0, count);
    return ans;
}

// Encoding and Decoding
string encodedDecoded(string str) // TC --> O(N)  SC --> O(N)
{
    int n = str.length();
    string ans = "";

    for (int i = 0; i < n; i++)
    {
        if (str[i] != ']')
        {
            ans.push_back(str[i]);
        }
        else
        {
            string reversedStr = "";
            while (!ans.empty() && ans.back() != '[')
            {
                reversedStr.push_back(ans.back());
                ans.pop_back();
            }

            // Pop the '[' character
            if (!ans.empty() && ans.back() == '[')
            {
                ans.pop_back();
            }

            // Reverse the string to get the correct order
            reverse(reversedStr.begin(), reversedStr.end());

            string num = "";
            while (!ans.empty() && isdigit(ans.back()))
            {
                num.push_back(ans.back());
                ans.pop_back();
            }

            // Reverse the number string to get the correct order
            reverse(num.begin(), num.end());
            int int_num = stoi(num);

            // Repeat the reversedStr `int_num` times
            string temp = reversedStr;
            for (int j = 1; j < int_num; j++)
            {
                reversedStr += temp;
            }

            // Append the repeated string back to ans
            ans += reversedStr;
        }
    }
    return ans;
}

// Maximum consecutive 1's fliped k times

int maxConsecutive1sKtimes(string str, int k) // TC --> O(N^2) SC --> O(1)
{
    int n = str.length();
    int maxLen = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        int currZero = 0;
        for (int j = i; j < n; j++)
        {
            if (str[j] == '0')
            {
                currZero++;
            }

            if (currZero <= k)
            {
                int curLen = j - i + 1;
                maxLen = max(curLen, maxLen);
            }
        }
    }
    return maxLen;
}

// Remove Outermost Parentheses
string removeOuterParentheses(string s) // TC --> O(N) TC --> O(ans)
{
    int n = s.length();
    string ans = "";
    int balance = 0;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
        {
            if (balance > 0)
            {
                ans += s[i];
            }
            balance++;
        }
        else if (s[i] == ')')
        {
            balance--;
            if (balance > 0)
            {
                ans += s[i];
            }
        }
    }
    return ans;
}

// Reverse Words in a String
string reverseWords(string s) // TC --> O(N) SC --> O(N)
{
    int n = s.length();
    string ans = "";
    string finalAns = "";

    for (int i = n - 1; i >= 0; i--)
    {
        if (s[i] != ' ')
        {
            ans += s[i];
        }
        else
        {
            if (!ans.empty())
            {
                reverse(ans.begin(), ans.end());
                if (!finalAns.empty())
                {
                    finalAns += " ";
                }
                finalAns += ans;
                ans = "";
            }
        }
    }

    if (!ans.empty())
    {
        reverse(ans.begin(), ans.end());
        if (!finalAns.empty())
        {
            finalAns += " ";
        }
        finalAns += ans;
    }

    return finalAns;
}

// Largest Odd Number in String
string largestOddNumber(string str) // TC --> O(N) SC --> O(1)
{
    int n = str.length();
    string largestOdd = "";

    for (int i = n - 1; i >= 0; i--)
    {
        if ((str[i] - '0') % 2 != 0)
        {
            largestOdd = str.substr(0, i + 1);
            break;
        }
    }
    return largestOdd;
}

// Rotate String
bool rotateString(string str, string goal)
{
    int n = str.length();
    int m = goal.length();

    if (n != m)
    {
        return false;
    }

    string doubleStr = str + str;

    return (doubleStr.find(goal) != string::npos);
}
int main()
{
    // string str = "NehaSingh";
    // string s(5, 's');
    // cout << "S: " << s << endl;

    // string fname = "neha";
    // string midname = "vinod";
    // string lname = "singh";
    // string surame = fname + " " + lname;
    // string fullname = surame.append(midname);

    // cout << "surame: " << surame << endl;
    // cout << "fullname: " << fullname << endl;

    // string x = "10";
    // string y = "20";
    // cout << "add(x+y): " << x + y << endl;

    // string txt = "NehaSingh";
    // cout << "length of txt: " << txt.length() << endl;
    // cout << "size of txt: " << txt.size() << endl;

    // string word = "specificcharacter";
    // cout << "Access word: " << word[6] << endl;

    // // Replace the character
    // word[6] = 'O';
    // cout << "Replace char: " << word << endl;

    // // Strings - Special Characters
    // string txt1 = "We are the so-called \"Vikings\" from the north.";
    // cout << "Special Characters: " << txt1 << endl;

    // // User Input Strings
    // string firstName;
    // string MiddleName;
    // string lastName;
    // cout << "Type your first name: ";
    // cin >> firstName;
    // cout << "Type your Middle Name : ";
    // cin >> MiddleName;
    // cout << "Type your last Name: ";
    // cin >> lastName;

    // cout << "Your Full Name is: " << firstName + " " + MiddleName + " " + lastName << endl;
    // ;

    // string str9;
    // getline(cin, str9);
    // cout << "fullname: " << str9 << endl;

    // // Index
    // for (int i = 0; i < str9.length(); i++)
    // {
    //     cout << str9[i] << " ";
    // }
    // cout << endl;

    // // ASCII Values
    // // A-Z --> 65 - 90
    // // a-z --> 97 - 122
    // char ch = 'z';
    // cout << "ASCII Values: " << int(ch) << endl;

    // String v/s character array
    // - string is class
    // - string varibales are object of this class (str, s, etc...)
    // - string str_name
    // - Dynamic Memory Allocation
    // - No Memory waste

    // - array of char data type
    // - char array_name[size]
    // - Static Memory Allocation
    // - Memory waste
    // Faster

    // In-built Functions
    // - Reverse()
    // - Substr()
    // - '+' Opertaor()
    // - strcat()
    // - push_back()
    // - size()
    // - to_string()

    // - Reverse() --> O(len(str))
    // string str = "Foundation";
    // reverse(str.begin(), str.end());
    // cout << "string: " << str << endl;
    // string str1 = "Foundation";
    // reverse(0, 2);
    // cout << "string range: " << str1 << endl;

    // - Substr() --> substr of given string  --> O(len(str))
    // string str = "Foundation";
    // string substr = str.substr(4, 9);
    // cout << "string substr range: " << substr << endl;
    // string substrall = str.substr(2);
    // cout << "string substr: " << substrall << endl;

    // - '+' Opertaor()  --> contact strings
    // string str = "Foundation";
    // string str1 = "Course";
    // str += str1; // apeended to str
    // // str = str + str1; // copy is created
    // cout << "'+' Opertaor string: " << str << endl;

    // - strcat() --> contact character array
    // char s1[10] = "confusion";
    // char s2[12] = "differences";
    // strcat(s1, s2);
    // cout << "string: " << s1 << endl;

    // - push_back() --> insert the element back
    // string s1 = "immaculate";
    // s1.push_back('A');
    // cout << "string: " << s1 << endl;

    // - size()
    // string s1 = "immaculate";
    // cout << "string: " << s1.size() << endl;
    // cout << "string: " << s1.length() << endl;

    // - to_string() -->convert to string
    // int num = 122;
    // string str = to_string(num);
    // cout << "to string: " << str << endl;
    // str += '1';
    // cout << "to string: " << str << endl;
    // cout << "to string[2]: " << str[2] << endl;

    // sort the string --> lexicographically

    // string str = "aacc";
    string str = "bank";
    string goal = "atom";
    // string t = "ccac";
    // vector<string> str = {"microscope", "microphone", "microbial"};

    // cout << "Original string: ";
    // for (int i = 0; i < str.size(); i++)
    // {
    //     cout << str[i] << " ";
    // }
    // cout << endl;
    cout << "String: " << str << endl;
    cout << "Goal: " << goal << endl;

    // auto result = sortlexicographically(str);
    // cout << "Sorted string: " << result << endl;

    // auto result = checkAnagram(str, t);
    // cout << "checkAnagram or not?: " << result << endl;

    // auto result = checkIsomorphic(str, t);
    // cout << "Isomorphic or not?: " << result << endl;

    // string result = longestCommonPrefix(str);
    // cout << "longest common prefix string among array: " << result << endl;

    // string result = encodedDecoded(str);
    // cout << "Encoding and Decoding String: " << result << endl;

    // auto result = maxConsecutive1sKtimes(str, 2);
    // cout << "Max no of consecutive 1s: " << result << endl;

    // auto result = removeOuterParentheses(str);
    // cout << "Remove Outermost Parentheses: " << result << endl;

    // auto result = reverseWords(str);
    // cout << "Reverse Words in a String: " << result << endl;

    // auto result = largestOddNumber(str);
    // cout << "Largest Odd Number in String: " << result << endl;

    auto result = rotateString(str, goal);
    cout << "Rotate String: " << result << endl;

    return 0;
}