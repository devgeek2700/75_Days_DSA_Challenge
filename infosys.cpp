#include <bits/stdc++.h>
using namespace std;

vector<long long> printFibb(int n)
{
    vector<long long> ans(n);

    if (n >= 1)
    {
        ans[0] = 1;
    }

    if (n >= 2)
    {
        ans[1] = 1;
    }

    for (int i = 2; i < n; i++)
    {
        ans[i] = ans[i - 1] + ans[i - 2];
    }
    return ans;
}

string FirstNonRepeating(string A)
{
    int n = A.length();
    string ans = "";
    vector<char> v;
    map<char, int> freq;

    for (int i = 0; i < n; i++)
    {
        freq[A[i]]++;
        v.push_back(A[i]);

        while (v.size() != 0 && freq[v.front()] > 1)
        {
            v.erase(v.begin());
        }

        if (v.size() != 0)
        {
            ans += v.front();
        }
        else
        {
            ans += '#';
        }
    }
    return ans;
}

int getPairsCount(const vector<int> &arr, int k)
{
    int n = arr.size();
    map<int, int> mpp;
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        int complement = k - arr[i];
        if (mpp.find(complement) != mpp.end())
        {
            count += mpp[complement];
        }
        mpp[arr[i]]++;
    }
    return count;
}

// Remove Duplicates from Sorted Array

int removeDuplicates(vector<int> &nums) // TC --> O(nlogn) SC --> O(n)
{
    set<int> unique_values(nums.begin(), nums.end());
    nums.assign(unique_values.begin(), unique_values.end());
    return unique_values.size();
}

vector<int> removeDuplicatesg(const vector<int> &nums)
{
    unordered_map<int, int> freq;
    vector<int> ans;

    // Count frequencies of each element
    for (int num : nums)
    {
        freq[num]++;
    }

    // Collect elements with frequency of 1
    for (const auto &pair : freq)
    {
        if (pair.second == 1)
        {
            ans.push_back(pair.first);
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}

bool sentencePalindrome(string s)
{
    string filterstr;
    for (char c : s)
    {
        if (isalnum(c))
        {
            filterstr += tolower(c);
        }
    }

    int n = filterstr.length();
    int start = 0;
    int end = n - 1;

    // Check if the string is a palindrome
    while (start <= end)
    {
        if (filterstr[start] == filterstr[end])
        {
            start++;
            end--;
        }
        else
        {
            return false;
        }
    }
    return true;
}

void Addition(vector<vector<int>> &matrixA, vector<vector<int>> &matrixB)
{
    int n = matrixA.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matrixA[i][j] += matrixB[i][j];
        }
    }
}

int binarysearch(vector<int> &arr, int k)
{
    int n = arr.size();
    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == k)
        {
            return mid;
        }
        else if (arr[mid] > k)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;
}

string armstrongNumber(int n)
{
    int hundreds = n / 100;
    int tens = (n / 10) % 10;
    int unit = n % 10;

    int sumofcubes = (hundreds * hundreds * hundreds) + (tens * tens * tens) + (unit * unit * unit);
    if (sumofcubes == n)
    {
        return "true";
    }
    else
    {
        return "false";
    }
}

vector<int> getAreas(int L, int W, int B, int H, int R)
{
    vector<int> ans;

    int areaRectangle = L * W;
    ans.push_back(areaRectangle);

    int areaTriangle = 0.5 * B * H;
    ans.push_back(areaTriangle);

    int areaCircle = 3.14 * R * R;
    ans.push_back(areaCircle);

    return ans;
}

int areMatricesIdentical(int N, vector<vector<int>> Grid1,
                         vector<vector<int>> Grid2)
{

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (Grid1[i][j] != Grid2[i][j])
            {
                return false;
            }
        }
    }
    return true;
}

int decimalEquivalent(string N, int b)
{
    int decVal = 0;
    int n = N.length();

    for (int i = 0; i < n; i++)
    {
        char digit = N[n - 1 - i];
        int digitValue;

        if (digit >= '0' && digit <= '9')
        {
            digitValue = digit - '0';
        }
        else if (digit >= 'A' && digit <= 'Z')
        {
            digitValue = digit - 'A' + 10;
        }
        else
        {
            return -1;
        }

        if (digitValue >= b)
        {
            return -1;
        }

        decVal += digitValue * pow(b, i);
    }
    return decVal;
}

void printTillN(int n)
{
    if (n <= 0)
    {
        return;
    }

    printTillN(n - 1);
    cout << n << " ";
}

int middle(int A, int B, int C)
{
    if ((A > B) != (A > C))
    {
        return A;
    }
    else if ((B > A) != (B > C))
    {
        return B;
    }
    else
    {
        return C;
    }
}

string getBinaryRep(int N)
{
    bitset<30> binary(N);
    string binaryStr = binary.to_string();
    return binaryStr;
}

int greatestOfThree(int A, int B, int C)
{
    if ((A > B) && (A > C))
    {
        return A;
    }
    else if ((B > A) && (B > C))
    {
        return B;
    }
    else
    {
        return C;
    }
}

int noOfOpenDoors(long long N)
{
    int res = sqrt(N);
    return res;
}

long long MaxSum(long long int A[], long long int B[], long long int N)
{
    sort(A, A + N);
    sort(B, B + N);

    long long sum = 0;

    for (int i = 0; i < N; i++)
    {
        sum += A[i] * B[i];
    }
    return sum;
}

int doOverlap(int L1[], int R1[], int L2[], int R2[])
{
    // check rectangle is left
    if (R1[0] < L2[0] || R2[0] < L1[0])
    {
        return 0;
    }

    // check rectangle is above
    if (R1[1] > L2[1] || R2[1] > L1[1])
    {
        return 0;
    }

    return 1;
}

bool isPrime(int num)
{
    if (num <= 1)
        return false;
    if (num == 2)
        return true;
    if (num % 2 == 0)
        return false;

    for (int i = 3; i * i <= num; i += 2)
    {
        if (num % i == 0)
            return false;
    }

    return true;
}

// Function to compute the sum of all prime numbers up to N
long long int prime_Sum(int n)
{
    long long int sum = 0;

    for (int i = 2; i <= n; i++)
    { // Iterate from 2 to n
        if (isPrime(i))
        {
            sum += i;
        }
    }

    return sum;
}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}