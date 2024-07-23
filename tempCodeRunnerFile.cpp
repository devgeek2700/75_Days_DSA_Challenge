bool compareJobs(Job a, Job b)
{
    return a.profit > b.profit;
}

vector<int> JobScheduling(Job arr[], int n) // TC --> O(nlogn+n*maxDeadline) SC --> O(maxDeadline)
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
        for (int j = arr[i].dead; j >= 0; j--)
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