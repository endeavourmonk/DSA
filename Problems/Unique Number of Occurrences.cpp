// Unique Number of Occurrences
// Link: https://leetcode.com/problems/unique-number-of-occurrences/description/

// Approach: store all the elements in hashmap then store freq of elements in a
// hashset. If size of the hashmap and hashset are same then true otherwise false.
// TC- O(N)	SC: O(N)

bool uniqueOccurrences(vector<int> &arr)
{
    map<int, int> mp;
    for (auto it : arr)
        mp[it]++;

    set<int> freq;
    for (auto [key, val] : mp)
        freq.insert(val);

    return ((mp.size() == freq.size())) ? true : false;
}