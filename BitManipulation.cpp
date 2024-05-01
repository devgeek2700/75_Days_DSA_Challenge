#include <bits/stdc++.h>
using namespace std;

// convert the decimal num to binary nums

string convertdecimaltobinary(int n) // TC --> O(logn)  SC --> O(logn)
{
    string remainder = "";
    while (n != 0)
    {
        if (n % 2 == 1)
        {
            remainder += '1';
        }
        else
        {
            remainder += '0';
        }
        n = n / 2;
    }

    reverse(remainder.begin(), remainder.end());

    return remainder;
}

// convert the binary num to decimal nums

int convertbinarytodecimal(string str) // TC --> O(len)  SC --> O(1)
{
    int len = str.size();
    int num = 0;
    int p2 = 1;

    for (int i = len - 1; i >= 0; i--)
    {

        if (str[i] == '1')
        {
            num = num + p2;
        }
        p2 = p2 * 2;
    }
    return num;
}

// int --> 32 bits
// 13 --> 1101 --> 4 bits rest is store as 00...00 --> 28 bits

// 1's complement --> opposite the bit
// 2's complement --> add 1 to the 1's complement

// Operators
// AND --> a*b --> 0 * 0 = 0, 0 * 1 = 0, 1 * 0 = 0, 1 * 1 = 1
// OR  --> a+b --> 0 + 0 = 0, 0 + 1 = 1, 1 + 0 = 1, 1 + 1 = 1
// XOR --> even 1's ---> 0 ||  odd 1's ---> 1 --> 0*0= 0, 0*1 = 1, 1*0 = 1, 1*1=0
// NOT --> ( ~ )
// SHIFT
// - RIGHT SHIFT ( >> || --> ) --> x >> k --> x / 2^k
// - LEFT SHIFT ( << || <-- ) --> x << k --> x * 2^k

// sign store in computer 0 --> +ve && 1 --> -ve
// x = 13 --> 0.....01101 --> 31st bit is for sign
// x = -13 --> 2's complement -->  1.....110011 --> 31st bit is for sign

// largest num store in int --> 01111...111 --> (21^31 - 1) = INT_MAX
// smallest num store in int --> 1000...000  --> (-21^31 - 1) = INT_MIN

// Swap two nums --> without temp variables that is --> XOR Opertors

void SwapXOR(int x, int y)
{
    x = x ^ y;
    y = x ^ y;
    x = x ^ y;

    cout << "Swapping: " << x << " " << y << endl;
}

// Check whether K-th bit is set or not

bool isKthBitSet(int n, int k) //  using LEFT SHIFT
{
    if ((n & (1 << (k - 1))) != 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isKthBitSetright(int n, int k) //  using RIGHT SHIFT
{
    if ((n & (1 >> (k - 1))) != 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Set K-th bit

int setKthBit(int n, int k) //  using LEFT SHIFT
{
    return ((n | (1 << k)));
}

// Clear K-th bit

int clearKthBit(int n, int k) //  using LEFT SHIFT
{
    return ((n & ~(1 << k)));
}

// Toggle K-th bit

int ToggleKthBit(int n, int k) //  using LEFT SHIFT
{
    return ((n ^ (1 << k)));
}

// Remove last set bit(rightmost)

int Removelastset(int n) //  using RIGHT SHIFT
{
    return (n ^ (n - 1));
}

// Check whether Power of Two or not

bool isPowerOfTwo(int n)
{
    if (n & (n - 1) == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//  Count set bits
// Mtd - 1
int countSetBits(int n)
{
    int count = 0;
    while (n > 1)
    {
        count += n & 1; // (n & 1) odd checks
        n = n >> 1;     // divide by 2
    }

    if (count == 1)
    {
        count++;
    }

    return count;
}

// Mtd - 2

int countSetBits2(int n)
{
    int count = 0;
    while (n != 0)
    {
        n = n & (n - 1);
        count++;
    }
    return count;
}

// Count total no. of set bits
int counttotalSetBits(int n)
{
    int totalcount = __builtin_popcount(n);
    return totalcount;
}

// Count total  binary representation
int counttotalSetBitsbinary(int N)
{
    int count = 0;
    for (int i = 1; i <= N; i <<= 1)
    {
        count += (N / (i << 1)) * i + min(max(N % (i << 1) - i + 1, 0), i);
    }
    return count;
}

//  Odd Even using Bit Manipulation
string oddEven(int N)
{
    if (N & 1)
    {
        return "ODD";
    }
    else
    {
        return "EVEN";
    }
}

//  Divide Two Integers
int divideTwoInteger(int dividend, int divisor) // TC --> O(logn)^2  SC --> O(1)
{
    if (dividend == divisor)
    {
        return 1;
    }

    bool sign = true;

    if (dividend >= 0 && divisor < 0)
    {
        sign = false;
    }
    if (dividend < 0 && divisor > 0)
    {
        sign = false;
    }

    int n = abs(dividend);
    int d = abs(divisor);
    int ans = 0;

    while (n >= d)
    {
        int count = 0;
        while (n >= (d << (count + 1)))
        {
            count++;
        }
        ans += (1 << count);
        n = n - (d * (1 << count));
    }

    if (ans == (1 << 31) && sign)
    {
        return INT_MAX;
    }
    if (ans == (1 << 31) && sign)
    {
        return INT_MIN;
    }

    return sign ? ans : -ans;
}

//  Flip Bits
int flipBits(int A, int B) // TC --> O(start ^ goal)
{
    int ans = A ^ B;
    int count = 0;

    while (ans > 0)
    {
        if (ans & 1)
        {
            count++;
        }
        ans >>= 1;
    }
    return count;
}

//  One Odd Occurring
int missingNumberodd(int n, vector<int> &arr) // TC --> O(n)  SC --> O(1)
{
    int XORans = 0;
    for (int i = 0; i < n; i++)
    {
        XORans ^= arr[i];
    }
    return XORans;
}

//  Subsequences of String
vector<string> subsequences(string str) // TC --> O(n * 2^n)  SC -->  nearly O(n * 2^n)

{
    vector<string> ans;
    int n = str.length();
    int noofSubsets = 1 << n;

    for (int num = 0; num < noofSubsets; num++)
    {
        string list = "";
        for (int i = 0; i < n; i++)
        {
            if (num & (1 << i))
            {
                list.push_back(str[i]);
            }
        }
        ans.push_back(list);
    }
    return ans;
}

//  in Range XOR
int findXORRange(int R) // TC --> O(1)  SC --> O(1)
{
    if (R % 4 == 0)
    {
        return R;
    }
    else if (R % 4 == 1)
    {
        return 1;
    }
    else if (R % 4 == 2)
    {
        return R + 1;
    }
    else
    {
        return 0;
    }
}

//  L to R XOR

int findXOR(int L, int R)
{
    return findXORRange(L - 1) ^ findXORRange(R);
}

// Find the two numbers appearing odd number of times

vector<int> twoOddNum(vector<int> arr)
{
    int XORans = 0;
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        XORans ^= arr[i];
    }

    int Rightmostbit = XORans & -XORans;
    int b1 = 0, b2 = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] & Rightmostbit)
        { // if non zero number then b1
            b1 ^= arr[i];
        }
        else
        {
            b2 ^= arr[i];
        }
    }

    if (b1 > b2)
        return {b1, b2};
    else
        return {b2, b1};
}

int main()
{
    int n;
    cout << "Num: ";
    cin >> n;

    string result = convertdecimaltobinary(n);
    cout << "Number is: " << n << endl;
    cout << "Decimal 2 binary is: " << result << endl;

    int resultbinary = convertbinarytodecimal(result);

    cout << "Bianry is: " << result << endl;
    cout << "Decimal 2 binary is: " << resultbinary << endl;

    SwapXOR(40, 4);

    int ans = isKthBitSetright(128, 7);
    cout << "Check whether K-th bit is set or not: " << ans << endl;

    int bitans = setKthBit(13, 2);
    cout << "Set K-th bit is: " << bitans << endl;

    int clearans = clearKthBit(13, 2);
    cout << "Clear K-th bit is: " << clearans << endl;

    int Toggleans = ToggleKthBit(13, 1);
    cout << "Toggle K-th bit is: " << Toggleans << endl;

    int isPowerOfTwoans = isPowerOfTwo(16);
    cout << "Check whether  Power of Two or not: " << isPowerOfTwoans << endl;

    // int countSetBitsans = countSetBits(12);
    int countSetBitsans = countSetBits2(12);
    cout << "Count set bits: " << countSetBitsans << endl;

    int counttotalSetBitsans = counttotalSetBits(5);
    cout << "Count total set bits: " << counttotalSetBitsans << endl;

    int counttotalSetBitsbinaryans = counttotalSetBitsbinary(5);
    cout << "Count total  binary representation: " << counttotalSetBitsbinaryans << endl;

    string oddEvenans = oddEven(n);
    cout << "Odd or Even?: " << oddEvenans << endl;

    int divideTwoIntegerans = divideTwoInteger(10, 3);
    cout << "Divide Two Integers: " << divideTwoIntegerans << endl;

    int flipBitsans = flipBits(10, 3);
    cout << "Flip Bits: " << flipBitsans << endl;

    vector<int> arr = {1, 1, 1, 1, 1};

    int missingNumberoddans = missingNumberodd(arr.size(), arr);
    cout << "One Odd Occurring: " << missingNumberoddans << endl;

    string str = {'1', '2', '3'};
    vector<string> subsequencesans = subsequences(str);

    cout << "Subsequences of String: ";
    for (string s : subsequencesans)
    {
        cout << s << " ";
    }
    cout << endl;

    int findXORRangeans = findXORRange(8);
    cout << "In Range XOR: " << findXORRangeans << endl;

    int findXORans = findXOR(96, 129);
    cout << "L to R XOR: " << findXORans << endl;

    vector<int> varr = {57, 41, 46, 42, 46, 19, 54, 57, 19, 54, 53, 41};

    vector<int> twoOddNumans = twoOddNum(varr);
    cout << "Find the two numbers appearing odd number of times: " << twoOddNumans[0] << " " << twoOddNumans[1] << endl;

    return 0;
}