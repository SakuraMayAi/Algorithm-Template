/**
 * @brief Get the next array of the string s.
 * 
 * Make sure that the size of the array next is equivalent to the length of s.
 * 
 * @param next	The prefix array. next[i] means the length of the longest common prefix-suffix. in the subinterval of [0, i].
 * @param s    	Pattern string.
 */
void getNext(vector<int>& next, const string& s)
{
    int j = 0;    // The j points to the last character of the prefix. 
    next[0] = 0;
    for (int i = 1; i < s.size(); ++i)    // The i points to the last character of the suffix. 
    {
        while (j > 0 && s[j] != s[i])
            j = next[j - 1];
        if (s[j] == s[i]) ++j;
        next[i] = j;
    }
}

/**
 * @brief Find and return the index of the first occurrence of s1 in s2, or -1 if s1 is not part of s2.
 * 
 * @param s1	Main string.
 * @param s2    Pattern string.
 * @return The index of the first occurrence of s1 in s2, or -1 if s1 isn't in s2.
 */
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
