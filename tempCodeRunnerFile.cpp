int maxDepth(string s)
{
    int n = s.length();
    int maxDepth = INT_MIN;
    int currDepth = 0;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
        {
            currDepth++;
            maxDepth = max(maxDepth, currDepth);
        }
        else if (s[i] == ')')
        {
            currDepth--;
        }
    }
    return maxDepth;
}