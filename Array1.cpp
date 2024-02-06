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

//  Check Sorted Array
int isSorted(int n, vector<int> a)
{
    for (int i = 1; i < n; i++)
    {
        if (a[i] < a[i - 1])
        {
            return false;
        }
    }
    return true;
}

//  Remove Duplicates from Sorted Array
// int removeDuplicates(vector<int> &arr, int n)
// {
//     for(int i = 0; i < n; i++){
//         for(int j = 1; j < n; j++){
//             if(arr[i])
//         }
//     }
// }

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

    vector<int> varr = {4, 5, 4, 4, 4};

    cout << "Vectors Values: ";
    for (auto it : varr)
    {
        cout << it << " ";
    }

    // auto result = getSecondOrderElements(5, varr);
    auto answer = isSorted(5, varr);
    // auto result = removeDuplicates(varr, 5);

    // Accessing the result vector of pairs
    // cout << "\nSecond smallest and second largest: " << result[0] << " and " << result[1] << endl;
    cout << endl;
    cout << " Check Sorted Array: " << (answer ? "Yes" : "No") << endl;
    // cout << "Remove Duplicates from Sorted Array: " <<result<< endl;

    return 0;
}