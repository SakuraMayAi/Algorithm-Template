/**
 * @brief Get the prefix array of the s.
 * 
 * Assume that we pass an array whose size is the length of s.
 * 
 * @param next	The prefix array.
 * @param s    	Pattern string.
 */
void getNext(vector<int>& next, const string& s);

/**
 * @brief Find and return the index of the first occurrence of s1 in s2, or -1 if s1 is not part of s2.
 * 
 * @param s1	Main string.
 * @param s2    Pattern string.
 * @return The index of the first occurrence of s1 in s2, or -1 if s1 isn't in s2.
 */
int KMP(const string& s1, const string& s2);
