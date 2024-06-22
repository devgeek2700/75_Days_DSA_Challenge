#include <bits/stdc++.h>
using namespace std;

// Generate all binary strings without consecutive 1’s

void generateAllStringsfuther(char str[], int k, int currStart)
{

    if (currStart == k)
    {
        str[currStart] = '\0';
        cout << str << " ";
        return;
    }

    // currStart - 1 --> 1 0 _

    if (str[currStart - 1] == '1')
    {
        str[currStart] = '0';
        generateAllStringsfuther(str, k, currStart + 1);
    }

    if (str[currStart - 1] == '0')
    {
        // currStart - 0 --> 0 0 _
        str[currStart] = '0';
        generateAllStringsfuther(str, k, currStart + 1);

        // currStart - 0 --> 0 1 _

        str[currStart] = '1';
        generateAllStringsfuther(str, k, currStart + 1);
    }
}

void generateAllStrings(int k)
{
    if (k == 0)
    {
        cout << "";
        return;
    }

    char str[k];

    // start with 0 _ _
    str[0] = '0';
    generateAllStringsfuther(str, k, 1);

    // start with  1 _ _

    str[0] = '1';
    generateAllStringsfuther(str, k, 1);
}

int main()
{
    int k = 5;

    cout << "Binary strings of size " << k << " without consecutive 1's: ";
    generateAllStrings(k);
    cout << endl;

    return 0;
}