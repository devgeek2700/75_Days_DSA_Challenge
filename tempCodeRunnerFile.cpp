void subsetSumsHelper(vector<int> &arr, vector<int> &ans, int currIdx, int sum)
{
    if (currIdx == arr.size())
    {
        ans.push_back(sum);
        return;
    }

    // Include the current element
    subsetSumsHelper(arr, ans, currIdx + 1, sum + arr[currIdx]);

    // Exclude the current element
    subsetSumsHelper(arr, ans, currIdx + 1, sum);
}

vector<int> subsetSums(vector<int> arr, int n)
{
    vector<int> ans;
    subsetSumsHelper(arr, ans, 0, 0);
    sort(ans.begin(), ans.end());
    return ans;
}