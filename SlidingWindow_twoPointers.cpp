#include <bits/stdc++.h>
using namespace std;

int solve(string str) {

  if(str.size()==0)
      return 0;
  int maxans = INT_MIN;
  for (int i = 0; i < str.length(); i++) // outer loop for traversing the string
  {
    unordered_set < int > set;
    for (int j = i; j < str.length(); j++) // nested loop for getting different string starting with str[i]
    {
      if (set.find(str[j]) != set.end()) // if element if found so mark it as ans and break from the loop
      {
        maxans = max(maxans, j - i);
        break;
      }
      set.insert(str[j]);
    }
  }
  return maxans;
}

int consecutiveOnes(vector<int>& arr) {
    int max_length = 0;
    int current_length = 0;

    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] == 1) {
            current_length++;
            max_length = max(max_length, current_length);
        } else {
            current_length = 0;
        }
    }

    return max_length;
}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}