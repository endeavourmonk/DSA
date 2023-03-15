151. Reverse Words in a String
https://leetcode.com/problems/reverse-words-in-a-string/description/

// Approach: First reverse whole string, then reverse each word by skipping spaces and words,
// finally remove leading, extra and trailing spaces from the string by shifting the characters
// and finally return the resulting substring.

// TC: O(N)
// SC: O(1)

string reverseWords(string s)
{
    reverse(s.begin(), s.end());
    int i = 0, j = 0, n = s.length();
    // reversing words
    while (i < n)
    {
        while (i < n && s[i] == ' ')
            ++i; // skip spaces
        j = i;
        while (j < n && s[j] != ' ')
            ++j; // skip words
        reverse(s.begin() + i, s.begin() + j);
        i = j;
    }
    // removing leading and trailing spaces
    i = 0, j = 0;
    while (j < n)
    {
        while (j < n && s[j] == ' ')
            ++j; // skip spaces
        while (j < n && s[j] != ' ')
            s[i++] = s[j++]; // skipping words and shifting
        while (j < n && s[j] == ' ')
            ++j; // skip spaces after words
        if (j < n)
            s[i++] = ' ';
    }
    return s.substr(0, i);
}