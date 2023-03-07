// 1910. Remove All Occurrences of a Substring
// https://leetcode.com/problems/remove-all-occurrences-of-a-substring/description/
// Approach: Start inserting from 0th ele of s into res, and if size of res exceeds m then go back m steps and look if this substring is equal to part, if yes then decrement the j to m index back and continue till the last of s.
// Finally you got your result which is substring of res for 0 to j.

// TC: O(N)
// SC: O(N)

string removeOccurrences(string s, string part)
{
    int n = s.length(), m = part.length(), i = 0, j = 0;
    string res;
    res.resize(n);
    for (i = 0, j = 0; i < n; ++i)
    {
        res[j++] = s[i];
        if (j >= m)
            if (res.substr((j - m), m) == part)
                j -= m;
    }
    return res.substr(0, j);
}