#include <bits/stdc++.h>
using namespace std;

//  Aggressive Cows  --> min distance between 2 cows is max
// min --> always between adjacent stalls
bool canweplacecows(vector<int> &stalls, int mid, int k)
{
    int countCows = 1;
    int lastplaceCows = stalls[0];

    for (int i = 1; i < stalls.size(); i++)
    {
        if (stalls[i] - lastplaceCows >= mid)
        {
            countCows++;
            lastplaceCows = stalls[i];
        }
    }

    return countCows >= k;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    int n = stalls.size();
    sort(stalls.begin(), stalls.end());   // Sort the stalls for binary search
    int low = 1;                          // Minimum possible distance
    int high = stalls[n - 1] - stalls[0]; // Maximum possible distance
    int ans = -1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (canweplacecows(stalls, mid, k))
        {
            ans = mid; // Try for a larger minimum distance
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return ans;
}

// Allocate Books

int maxminumPagesAllocate(vector<int> &arr, int mid)
{
    int pagesHold = 0;
    int currStudent = 1;

    for (int i = 0; i < arr.size(); i++)
    {
        if (pagesHold + arr[i] <= mid)
        {
            pagesHold += arr[i];
        }
        else
        {
            currStudent++;
            pagesHold = arr[i];
        }
    }
    return currStudent;
}

int findPages(vector<int> &arr, int n, int m)
{
    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    int ans = -1;

    if (m > n)
    {
        return ans;
    }

    while (low <= high)
    {
        int mid = (low + high) / 2;
        int noOfStudents = maxminumPagesAllocate(arr, mid);

        if (noOfStudents > m)
        {
            low = mid + 1;
        }
        else
        {
            ans = mid;
            high = mid - 1;
        }
    }
    return ans;
}

// Split Array Largest Sum --> same Book Allocation, Painter's partition

int SubarrayDivide(vector<int> &arr, int mid)
{
    int CurrentSubArr = 1;
    int SubArrnxt = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        if (SubArrnxt + arr[i] <= mid)
        {
            SubArrnxt += arr[i];
        }
        else
        {
            CurrentSubArr += 1;
            SubArrnxt = arr[i];
        }
    }

    return CurrentSubArr;
}

int splitArrayHelper(vector<int> &arr, int n, int m)
{
    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    int ans = -1;

    if (m > n)
    {
        return ans;
    }

    while (low <= high)
    {
        int mid = (low + high) / 2;
        int noOfStudents = SubarrayDivide(arr, mid);

        if (noOfStudents > m)
        {
            low = mid + 1;
        }
        else
        {
            ans = mid;
            high = mid - 1;
        }
    }
    return ans;
}

int splitArray(vector<int> &nums, int k)
{
    return splitArrayHelper(nums, nums.size(), k);
}

// Painter's Partition Problem --> same Book Allocation, Split Array Largest Sum

int paintersubarray(vector<int> &arr, int mid)
{
    int CurrentSubArr = 1;
    int SubArrnxt = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        if (SubArrnxt + arr[i] <= mid)
        {
            SubArrnxt += arr[i];
        }
        else
        {
            CurrentSubArr += 1;
            SubArrnxt = arr[i];
        }
    }

    return CurrentSubArr;
}

int PainterPartitionHelper(vector<int> &arr, int n, int m)
{
    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    int ans = -1;

    if (m > n)
    {
        return ans;
    }

    while (low <= high)
    {
        int mid = (low + high) / 2;
        int noOfStudents = paintersubarray(arr, mid);

        if (noOfStudents > m)
        {
            low = mid + 1;
        }
        else
        {
            ans = mid;
            high = mid - 1;
        }
    }
    return ans;
}

int PainterPartition(vector<int> &nums, int k)
{
    return PainterPartitionHelper(nums, nums.size(), k);
}

//  Minimize Max Distance to Gas Station  --> Min on Max
int noofGasStationsrequired(vector<int> &arr, long double mid)
{
    int n = arr.size();
    int count = 0;
    for (int i = 1; i < n; i++)
    {
        int numberInBetween = ((arr[i] - arr[i - 1]) / mid);
        count += numberInBetween;
    }
    return count;
}

double minimiseMaxDistance(vector<int> &arr, int k)
{
    long double low = 0;
    long double high = *max_element(arr.begin(), arr.end()) - *min_element(arr.begin(), arr.end());
    long double ans = -1;
    long double diff = 1e-6;

    while (high - low > diff)
    {
        long double mid = (low + high) / (2.0);
        int countofGasStn = noofGasStationsrequired(arr, mid);
        if (countofGasStn > k)
        {
            low = mid;
        }
        else
        {
            ans = mid;
            high = mid;
        }
    }
    return ans;
}

// Median of Two Sorted Arrays
double findMedianSortedArrays1(vector<int> &nums1, vector<int> &nums2)
{
    int n1 = nums1.size();
    int n2 = nums2.size();

    if (n1 > n2)
    {
        return findMedianSortedArrays1(nums2, nums1);
    }
    int low = 0;
    int high = n1;
    int left = (n1 + n2 + 1) / 2;
    int n = n1 + n2;

    while (low <= high)
    {
        int mid1 = (low + high) >> 1;
        int mid2 = left - mid1;
        int l1 = (mid1 == 0) ? INT_MIN : nums1[mid1 - 1];
        int l2 = (mid2 == 0) ? INT_MIN : nums2[mid2 - 1];
        int r1 = (mid1 == n1) ? INT_MAX : nums1[mid1];
        int r2 = (mid2 == n2) ? INT_MAX : nums2[mid2];
        if (l1 <= r2 && l2 <= r1)
        {
            if (n % 2 == 1)
            {
                return max(l1, l2);
            }
            return (double)(max(l1, l2) + min(r1, r2)) / 2.0;
        }
        else if (l1 > r2)
        {
            high = mid1 - 1;
        }
        else
        {
            low = mid1 + 1;
        }
    }
    return 0;
}

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    int n1 = nums1.size();
    int n2 = nums2.size();
    int i = 0, j = 0;
    int n = n1 + n2;
    int index1 = n / 2;
    int index2 = index1 - 1;
    int count = 0;
    int ele1 = -1, ele2 = -1;

    while (i < n1 && j < n2)
    {
        if (nums1[i] < nums2[j])
        {
            if (count == index1)
            {
                ele1 = nums1[i];
            }
            if (count == index2)
            {
                ele2 = nums1[i];
            }
            count++;
            i++;
        }
        else
        {
            if (count == index1)
            {
                ele1 = nums2[j];
            }
            if (count == index2)
            {
                ele2 = nums2[j];
            }
            count++;
            j++;
        }
    }

    // If there are remaining elements in nums1
    while (i < n1)
    {
        if (count == index1)
        {
            ele1 = nums1[i];
        }
        if (count == index2)
        {
            ele2 = nums1[i];
        }
        count++;
        i++;
    }

    // If there are remaining elements in nums2
    while (j < n2)
    {
        if (count == index1)
        {
            ele1 = nums2[j];
        }
        if (count == index2)
        {
            ele2 = nums2[j];
        }
        count++;
        j++;
    }

    // If the total number of elements is odd, return the middle element
    if (n % 2 == 1)
    {
        return ele1;
    }

    // If the total number of elements is even, return the average of the two middle elements
    return (double)(ele1 + ele2) / 2.0;
}

// K-th element of two Arrays
int kthElement(int k, vector<int> &arr1, vector<int> &arr2)
{
    int n1 = arr1.size();
    int n2 = arr2.size();

    // Ensure that arr1 is the smaller array
    if (n1 > n2)
    {
        return kthElement(k, arr2, arr1);
    }

    int low = max(0, k - n2); // If k > n2, adjust the low bound
    int high = min(k, n1);    // If k < n1, adjust the high bound

    while (low <= high)
    {
        int mid1 = (low + high) / 2;
        int mid2 = k - mid1;

        // Left and right boundaries for arr1 and arr2
        int l1 = (mid1 == 0) ? INT_MIN : arr1[mid1 - 1];
        int l2 = (mid2 == 0) ? INT_MIN : arr2[mid2 - 1];
        int r1 = (mid1 == n1) ? INT_MAX : arr1[mid1];
        int r2 = (mid2 == n2) ? INT_MAX : arr2[mid2];

        // Check if we have found the k-th element
        if (l1 <= r2 && l2 <= r1)
        {
            return max(l1, l2);
        }
        else if (l1 > r2) // Reduce mid1 if l1 is greater than r2
        {
            high = mid1 - 1;
        }
        else // Increase mid1 if l2 is greater than r1
        {
            low = mid1 + 1;
        }
    }

    return -1; // Fallback case (should not be reached)
}

int main()
{

    vector<int> nums1 = {2, 3, 6, 7, 9};
    vector<int> nums2 = {1, 4, 8, 10};
    int k = 5;
    // int m = 2;
    // cout << "The largest minimum distance is: " << aggressiveCows(nums, k) << endl;
    // cout << "The largest minimum distance is: " << findPages(nums, n, m) << endl;
    // cout << "The splitArray is: " << splitArray(arr1, k) << endl;
    // cout << "The Painter's Partition Problem is: " << PainterPartition(arr1, k) << endl;
    // cout << "The Minimize Max Distance to Gas Station is: " << minimiseMaxDistance(arr1, k) << endl;
    // double median = findMedianSortedArrays(nums1, nums2);
    // cout << "The median is: " << median << endl;

    int result = kthElement(k, nums1, nums2);
    cout << "The " << k << "-th element is: " << result << endl;

    return 0;
}