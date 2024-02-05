#include <bits/stdc++.h>
using namespace std;

// 	Largest Element in an Array

int LargestElementArray(int arr[], int n)
{
    int maxval = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > maxval)
        {
            maxval = arr[i];
        }
    }
    return maxval;
}

//  Second Largest and Smallest Number in an Array

vector<int> getSecondOrderElements(int n, vector<int> a)
{
    vector<int> answer;

    sort(a.begin(), a.end());

    answer.push_back(a[n - 2]);
    answer.push_back(a[1]);

    return answer;
}

int main()
{
    // int n;
    // cout << "n: ";
    // cin >> n;

    // int arr[n];
    // cout << "Array Values: ";
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> arr[i];
    // }

    // cout << "Display Array Values: ";
    // for (int i = 0; i < n; i++)
    // {
    //     cout << arr[i] << " ";
    // }
    // cout << endl;

    // cout << "Largest Element in an Array: " << LargestElementArray(arr, n) << endl;

    vector<int> varr = {22, 55,66, 12,10};

    cout << "Vectors Values: ";
    for (auto it : varr)
    {
        cout << it << " ";
    }

    auto result = getSecondOrderElements(5, varr);

    // Accessing the result vector of pairs
    cout << "\nSecond smallest and second largest: " << result[0] << " and " << result[1] << endl;

    return 0;
}