// 442. Find All Duplicates in an Array
// https://leetcode.com/problems/find-all-duplicates-in-an-array/description/

// Approach:
// we map the elements with its frequency using a hash table. and then return all those elements whose frequeny is 2.

// TC: O(N)

vector<int> findDuplicates(vector<int> &nums)
{
    unordered_map<int, int> mp;
    for (auto it : nums)
        mp[it]++;
    vector<int> res;
    for (auto it : mp)
        if (it.second == 2)
            res.push_back(it.first);
    return res;
}