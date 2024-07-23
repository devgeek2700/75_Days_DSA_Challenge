#include <bits/stdc++.h>
using namespace std;
struct Item
{
    int value;
    int weight;
};

struct Data
{
    int start;
    int end;
    int position;
};

struct Job
{
    int id;     // Job Id
    int dead;   // Deadline of job
    int profit; // Profit if job is over before or on deadline
};

// Assign Cookies

int findContentChildren(vector<int> &g, vector<int> &s) // TC --> O(nlogn+nlogn+m) SC --> O(1)
{
    int n = g.size();
    int m = s.size();
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int left = 0;
    int right = 0;

    while (left < m && right < n)
    {
        if (s[left] >= g[right])
        {
            right++;
        }
        left++;
    }
    return right;
}

// Fractional Knapsack
bool compare(Item val1, Item val2)
{
    double r1 = (double)val1.value / val1.weight;
    double r2 = (double)val2.value / val2.weight;
    return r1 > r2;
}

double fractionalKnapsack(int w, Item arr[], int n) // TC -->O(nlogn+n) SC -> O(1)
{
    // greedy approach per wght
    // taking value per weight
    // 20w --> 100v
    // 1w --> 100v/20w = 5v

    sort(arr, arr + n, compare);

    // sort(arr, arr + n, [](Item a, Item b)
    //      {
    //     double r1 = (double)a.value / a.weight;
    //     double r2 = (double)b.value / b.weight;
    //     return r1 > r2; });

    double totalval = 0.0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i].weight <= w)
        {
            totalval += arr[i].value;
            w -= arr[i].weight;
        }
        else
        {
            totalval += ((double)arr[i].value / arr[i].weight) * w;
            break;
        }
    }
    return totalval;
}

// Find minimum number of coins to make a given value
int minCoins(int coins[], int m, int V) // TC --> O(mlogm +V/m) SC --> O(1)
{
    sort(coins, coins + m);
    int numCoinsCount = 0;

    for (int i = m - 1; i >= 0; i--)
    {
        while (V >= coins[i])
        {
            V -= coins[i];
            numCoinsCount++;
        }
    }
    if (V != 0)
    {
        return -1;
    }

    return numCoinsCount;
}

// Lemonade Change
bool lemonadeChange(vector<int> &bills) // TC -> O(n) SC --> O(1)
{
    int n = bills.size();
    int fives = 0;
    int tens = 0;

    for (int i = 0; i < n; i++)
    {
        if (bills[i] == 5)
        {
            fives++;
        }
        else if (bills[i] == 10)
        {
            if (fives)
            {
                tens++;
                fives--;
            }
            else
            {
                return false;
            }
        }
        else
        {
            if (fives && tens)
            {
                fives--;
                tens--;
            }
            else if (fives >= 3)
            {
                fives -= 3;
            }
            else
            {
                return false;
            }
        }
    }
    return true;
}

// Valid Parenthesis String
bool checkValidString(string s) // TC --> O(n) SC --> O(3*n +1 )
{
    int n = s.length();
    int min = 0;
    int max = 0;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
        {
            min++;
            max++;
        }
        else if (s[i] == ')')
        {
            min--;
            max--;
        }
        else
        {
            min--;
            max++;
        }

        if (min < 0)
        {
            min = 0;
        }
        if (max < 0)
        {
            return false;
        }
    }
    return (min == 0);
}

// N meetings in one room
bool compareMeet(Data val1, Data val2) // based on end time
{
    return val1.end < val2.end;
}

int maxMeetings(int start[], int end[], int n) // TC --> O(2*N + nlogn) SC --> O(1)
{
    Data arr[n];

    for (int i = 0; i < n; i++)
    {
        arr[i].start = start[i];
        arr[i].end = end[i];
        arr[i].position = i + 1;
    }

    sort(arr, arr + n, compareMeet);

    int count = 1;
    int freetime = arr[0].end;

    for (int i = 1; i < n; i++)
    {
        if (arr[i].start > freetime)
        {
            count++;
            freetime = arr[i].end;
        }
    }
    return count;
}

// Jump Game
bool canJump(vector<int> &nums) // TC --> O(n) SC --> O(1)
{
    int n = nums.size();
    int maxIdx = 0;

    for (int i = 0; i < n; i++)
    {
        if (i > maxIdx)
        {
            return false;
        }
        maxIdx = max(maxIdx, nums[i] + i);
    }
    return true;
}

//  Jump Game 2
int jump(vector<int> &nums) // TC --> O(N) SC --> O(1)
{
    int n = nums.size();
    if (n == 1)
    {
        return 0;
    }

    int jumps = 0;
    int currEnd = 0;
    int farthest = 0;

    for (int i = 0; i < n - 1; i++)
    {
        farthest = max(farthest, i + nums[i]);

        if (i == currEnd)
        {
            jumps++;
            currEnd = farthest;

            if (currEnd >= n - 1)
            {
                break;
            }
        }
    }
    return jumps;
}

// Minimum Platforms
int minimumPlatforms(int arr[], int dep[], int n) // TC = O(n+m) O(1)
{
    sort(arr, arr + n);
    sort(dep, dep + n);
    int a = 0;
    int d = 0;
    int count = 0;
    int maxCount = 0;

    while (a < n)
    {
        if (arr[a] <= dep[d])
        {
            count++;
            a++;
        }
        else
        {
            count--;
            d++;
        }
        maxCount = max(count, maxCount);
    }
    return maxCount;
}

// Job Sequencing Problem
bool compareJobs(Job a, Job b)
{
    return a.profit > b.profit;
}

vector<int> JobScheduling(Job arr[], int n)
// TC --> O(nlogn+n*maxDeadline) SC --> O(maxDeadline)
{
    sort(arr, arr + n, compareJobs); // --> O(nlogn)
    int maxProfit = 0;
    int maxDeadline = -1;
    int noOfJobs = 0;

    for (int i = 0; i < n; i++) // --> O(n)
    {
        maxDeadline = max(maxDeadline, arr[i].dead);
    }

    vector<int> slot(maxDeadline + 1, -1);

    for (int i = 0; i < n; i++) // --> O(n*maxDeadline)
    {
        for (int j = arr[i].dead; j > 0; j--)
        {
            if (slot[j] == -1)
            {
                slot[j] = arr[i].id;
                noOfJobs++;
                maxProfit += arr[i].profit;
                break;
            }
        }
    }

    return {noOfJobs, maxProfit};
}

// Candy --> Slope Approach Intuition Based
int candy(vector<int> &ratings) // TC --> O(2*n) SC --> O(1)
{
    int n = ratings.size();
    if (n == 0)
    {
        return 0;
    }

    vector<int> candies(n, 1);

    // Left to right pass
    for (int i = 0; i < n; i++)
    {
        if (ratings[i] > ratings[i - 1])
        {
            candies[i] = candies[i - 1] + 1;
        }
    }

    // Right to left pass
    for (int i = n - 2; i >= 0; i--)
    {
        if (ratings[i] > ratings[i + 1])
        {
            candies[i] = max(candies[i], candies[i + 1] + 1);
        }
    }
    return accumulate(candies.begin(), candies.end(), 0);
}

// Shortest Job first
long long solve(vector<int> &bt) // TC --> O(N) SC --> O(1)
{
    sort(bt.begin(), bt.end());
    int n = bt.size();
    int starttime = 0;
    int waitingtime = 0;

    for (int i = 0; i < n; i++)
    {
        waitingtime += starttime;
        starttime += bt[i];
    }

    return (waitingtime / n);
}

// Page Faults in LRU

int pageFaults(int N, int C, int pages[]) // TC --> O(N) SC-->O(1)
{
    int pageFaultCount = 0;
    vector<int> frames;

    for (int i = 0; i < N; i++)
    {
        auto it = find(frames.begin(), frames.end(), pages[i]);

        // If memory is full
        if (it == frames.end())
        {
            if (frames.size() == C)
            {
                frames.erase(frames.begin());
            }

            // Add the recent element into memory
            frames.push_back(pages[i]);
            pageFaultCount++;
        }
        else
        {
            frames.erase(it);
            frames.push_back(pages[i]);
        }
    }
    return pageFaultCount;
}

// Insert Interval
vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
// TC --> O(3*n) O(N)
{
    vector<vector<int>> ans;
    int n = intervals.size();

    int i = 0;
    //  separated the non overlap right part
    while (i < n && intervals[i][1] < newInterval[0])
    {
        ans.push_back(intervals[i]);
        i++;
    }

    // creating the overlaping part
    while (i < n && intervals[i][0] <= newInterval[1])
    {
        newInterval[0] = min(newInterval[0], intervals[i][0]);
        newInterval[1] = max(newInterval[1], intervals[i][1]);
        i++;
    }
    ans.push_back(newInterval);

    //  separated the non overlap left part
    while (i < n)
    {
        ans.push_back(intervals[i]);
        i++;
    }

    return ans;
}

// Merge Intervals
vector<vector<int>> merge(vector<vector<int>> &intervals)
{
}
int main()
{
    // vector<int> g = {1, 5, 3, 3, 4};
    // vector<int> s = {4, 2, 1, 2, 1, 3};
    // cout << " Assign Cookies: " << findContentChildren(g, s) << endl;

    // int n = 2;
    // int w = 50;
    // Item arr[] = {{60, 100}, {10, 20}};
    // cout << "Fractional Knapsack total value: " << fractionalKnapsack(w, arr, n) << endl;

    // int coins[] = {9, 6, 5, 1};
    // int m = sizeof(coins) / sizeof(coins[0]);
    // int V = 11;
    // cout << "Minimum coins required is "
    //      << minCoins(coins, m, V);

    // vector<int> bills = {5, 5, 10, 10, 20};
    // cout << "Lemonade Change: " << lemonadeChange(bills) << endl;

    // string s = "()*)*()";
    // cout << "Valid Parenthesis String: " << checkValidString(s) << endl;

    // int n = 3;
    // int start[] = {10, 12, 20};
    // int end[] = {20, 25, 30};
    // cout << " Maximum meetings: " << maxMeetings(start, end, n) << endl;

    // vector<int> nums = {2, 3, 1, 1, 4};
    // cout << "Jump Game: " << canJump(nums) << endl;

    // vector<int> nums = {2, 3, 0, 1, 4};
    // cout << "Jump Game 2: " << jump(nums) << endl;

    // int n = 3;
    // int arr[] = {1000, 935, 1100};
    // int dep[] = {1200, 1240, 1130};
    // cout << "Minimum Platforms: " << minimumPlatforms(arr, dep, n) << endl;

    // int n = 5;
    // Job jobs[] = {{1, 2, 100}, {2, 1, 19}, {3, 2, 27}, {4, 1, 25}, {5, 1, 15}};

    // vector<int> result = JobScheduling(jobs, n);
    // cout << "Job Sequencing Problem: Jobs done = " << result[0] << ", Total profit = " << result[1] << endl;

    // vector<int> ratings = {1, 2, 2};
    // cout << "Candy ratings: " << candy(ratings) << endl;

    // vector<int> bt = {1, 2, 3, 4};
    // cout << "Shortest Job first: " << solve(bt) << endl;

    // int pages[] = {1, 2, 1, 4, 2, 3, 5};
    // int n = 7;
    // int C = 3;
    // cout << "Page Faults in LRU: " << pageFaults(n, C, pages) << endl;

    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};

    vector<vector<int>> result = merge(intervals);

    cout << "Merged Intervals: ";
    for (const auto &interval : result)
    {
        cout << "[" << interval[0] << "," << interval[1] << "] ";
    }
    cout << endl;
    return 0;
}