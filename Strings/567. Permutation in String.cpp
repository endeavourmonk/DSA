// 567. Permutation in String
// https://leetcode.com/problems/permutation-in-string/description/

// Approach: Sliding Window, Two Pointers
// If the first string is larger then false.
// Else first create a hash of both strings of length s1(this will make a window of size s1.length())
// after this our right is pointing next to the length of s1.
// Now start hashing till right < s2.length(),
// and decreasing left element from start and check if at any point both hashes are the same return true.
// Finally check both hashes.
// TC: O(N * 26)
// SC: O(1)

bool checkInclusion(string s1, string s2)
{
    if (s2.length() < s1.length())
        return false;
    vector<int> s1hash(26, 0);
    vector<int> s2hash(26, 0);
    int left = 0, right = 0;
    // creating hash of both strings
    while (right < s1.length())
    {
        s1hash[s1[right] - 'a']++;
        s2hash[s2[right] - 'a']++;
        right++;
    }

    // now sliding the window and comparing hash
    while (right < s2.length())
    {
        if (s1hash == s2hash)
            return true;
        if (right < s2.length())
        {
            s2hash[s2[right] - 'a']++;
            right++;
        }
        s2hash[s2[left] - 'a']--;
        left++;
    }
    if (s1hash == s2hash)
        return true;
    return false;
}