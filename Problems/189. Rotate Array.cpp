// 189. Rotate Array
// https://leetcode.com/problems/rotate-array/
// TC: O(N)
// SC: O(1)
void rotate(vector<int> &nums, int k)
{
    int n = nums.size();
    k %= n;
    if (k == 0)
        return;
    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), (nums.end() - (n - k)));
    reverse(nums.begin() + k, nums.end());
}
