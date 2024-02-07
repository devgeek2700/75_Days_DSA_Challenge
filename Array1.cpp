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

//  Remove Duplicates from Sorted Array with extra space
// int removeDuplicates(vector<int> &arr, int n)
// {
//     vector<int> temp;
//     for(int i = 0; i < n; i++){
//         for(int j = 1; j < n; j++){
//             if(arr[i] == arr[j] && i != j){
//                 arr.erase(arr.begin() +1);
//                 j--;
//                 n--;
//             }
//         }
//         temp.push_back(arr[i]);
//     }
//     cout<<endl;
//     cout << "arr array: ";
//     for (auto it : temp)
//     {
//         cout << it << " ";
//     }

//     return temp.size();
// }

//  Remove Duplicates from Sorted Array with extra space
int removeDuplicates(vector<int> &arr, int n)
{
    int tempindex = 1;
    if (n == 0)
    {
        return 0;
    }

    for (int i = 1; i < n; i++)
    {
        if (arr[i] != arr[i - 1])
        {
            arr[tempindex++] = arr[i];
        }
    }

    arr.resize(tempindex);

    return tempindex;
}

//  Left Rotate an Array by One

vector<int> rotateArrayleft(vector<int> &arr, int n)
{
    if (n == 0 || n == 1)
        return arr;

    int firstVal = arr[0];

    for (int i = 1; i < n; i++)
    {
        arr[i - 1] = arr[i];
    }

    arr[n - 1] = firstVal;

    return arr;
}

//  Rotate array by k times

vector<int> rotateArraybyktimes(vector<int> arr, int k)
{
    int n = arr.size();
    if (n == 0 || n == 1 || k == 0)
        return arr;

    for (int i = 1; i <= k; i++)
    {
        int firstvalue = arr[0];
        for (int j = 1; j < n; j++)
        {
            arr[j - 1] = arr[j];
        }
        arr[n - 1] = firstvalue;

        cout << endl;
        cout << "arr array " << i << " times: ";
        for (auto it : arr)
        {
            cout << it << " ";
        }
    }

    return arr;
}

//  Move Zero's to End

vector<int> moveZeros(int n, vector<int> a)
{
    int tempidx = 0;
    if (n == 0 || n == 1)
        return a;

    for (int i = 0; i < n; i++)
    {
        if (a[i] != 0)
        {
            a[tempidx++] = a[i];
        }
    }

    a.resize(tempidx);

    for (int i = tempidx; i < n; i++)
    {
        a.push_back(0);
    }

    return a;
}

//  Linear Search

int linearSearch(int n, int num, vector<int> &arr)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == num)
        {
            return i;
        }
    }
    return -1;
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

    vector<int> varr = {2, 5, 6, 2};

    cout << "Vectors Values: ";
    for (auto it : varr)
    {
        cout << it << " ";
    }

    // auto result = getSecondOrderElements(5, varr);
    // auto answer = isSorted(5, varr);
    // auto result = removeDuplicates(varr, 9);
    // auto result = rotateArrayleft(varr, 5);
    // int k = 3;
    // auto result = rotateArraybyktimes(varr, k);
    // auto result = moveZeros(5, varr);
    int num = 20;
    auto result = linearSearch(4, num, varr);

    // Accessing the result vector of pairs
    // cout << "\nSecond smallest and second largest: " << result[0] << " and " << result[1] << endl;
    cout << endl;
    // cout << " Check Sorted Array: " << (answer ? "Yes" : "No") << endl;
    // cout << "Remove Duplicates from Sorted Array: " <<result<< endl;
    // cout << "Rotate array K Times: ";

    // for (auto it : result)
    // {
    //     cout << it << " ";
    // }

    // cout << "Move Zero's to End: ";
    // for (auto it : result)
    // {
    //     cout << it << " ";
    // }

    cout << "Linear Search: " << result << endl;
    return 0;
}