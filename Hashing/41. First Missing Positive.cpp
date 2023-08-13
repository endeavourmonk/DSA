// 41. First Missing Positive - Hard
// https://leetcode.com/problems/first-missing-positive/description/

// Approach: Unordered_set Insert all the elements of the nums
// inside the unordered set. Then look for elements from 1 to the
// size of nums. If the current element from 1 - size is not found
// in the set then that's our answer. Otherwise our answer is nums
// size + 1.
// TC: O(n) in average case
// SC: O(n)

int firstMissingPositive(vector<int> &nums) {
    unordered_set<int> s(nums.begin(), nums.end());
    for (int i = 1; i <= nums.size(); ++i)
        if (s.find(i) == s.end())
            return i;
    return nums.size() + 1;
}