438. Find All Anagrams in a String
https://leetcode.com/problems/find-all-anagrams-in-a-string/description/

// Approach: Sliding window, Two Pointers
// First create a frequency hash of both the strings of smaller ones size
// (this will create your window which you will slide after).
// Then start traversing and add the right element into freq hash and decrement the left element from freq hash.
// And Compare both the hashes and store the left index in ans.
// Finally compare both hashes(because when right exceeds and left element freq is updated we need to compare
// once more) and return ans.

// TC: O(N * 26)
// SC: O(1)

vector<int> findAnagrams(string s, string p)
{
    vector<int> ans;
    if (p.length() > s.length())
        return ans;
    vector<int> sHash(26, 0);
    vector<int> pHash(26, 0);
    int l = 0, r = 0;
    for (r = 0; r < p.length(); ++r)
    {
        sHash[s[r] - 'a']++;
        pHash[p[r] - 'a']++;
    }
    while (r < s.length())
    {
        if (sHash == pHash)
            ans.emplace_back(l);
        sHash[s[r] - 'a']++;
        r++;
        sHash[s[l] - 'a']--;
        l++;
    }
    if (sHash == pHash)
        ans.emplace_back(l);
    return ans;
}