void getNext(vector<int>& next, const string& s)
{
    int prefixLen = 0;    // The length of longest common prefix-suffx (LCPS).
    next[0] = 0;
    for (int i = 1; i < s.size(); ++i)
    {
        while (prefixLen > 0 && s[prefixLen] != s[i])
            prefixLen = next[prefixLen - 1];
        if (s[prefixLen] == s[i]) ++prefixLen;
        next[i] = prefixLen;
    }
}

int KMP(const string& s1, const string& s2)
{
    if (s2.size() == 0) return 0;
    vector<int> next(s2.size());
    getNext(next, s2);
    int j = 0;
    for (int i = 0; i < s1.size(); ++i)
    {
        while (j > 0 && s1[i] != s2[j])
            j = next[j - 1];
        if (s1[i] == s2[j]) ++j;
        if (j == s2.size())
            return (i - s2.size() + 1);
    }

    return -1;
}
