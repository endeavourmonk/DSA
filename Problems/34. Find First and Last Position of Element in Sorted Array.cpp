// Find First and Last Position of Element in Sorted Array
// Link:   https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/

// approach:
// 1st occurence: start looking for the target using Binary Search if target found start looking
// for the target in the left part of the array where the Ist time target  was found.
// 2nd Occurence: start looking for the target and when you find it start looking for the target in the right part of array where you found the target first time.

// TC: O(log n + log n) per testcase
// SC: O(1)

vector<int> searchRange(vector<int> &nums, int target)
{
    vector<int> ans(2, -1);
    // finding first occurence
    int st = 0, end = nums.size() - 1;
    int mid = st + (end - st) / 2;
    while (st <= end)
    {
        if (target == nums[mid])
        {
            ans[0] = mid;
            end = mid - 1;
        }
        else if (target > nums[mid])
            st = mid + 1;
        else
            end = mid - 1;
        mid = st + (end - st) / 2;
    }

    // finding the last occurence
    st = 0, end = nums.size() - 1;
    mid = (st + end) / 2;
    while (st <= end)
    {
        if (target == nums[mid])
        {
            ans[1] = mid;
            st = mid + 1;
        }
        else if (target > nums[mid])
            st = mid + 1;
        else
            end = mid - 1;
        mid = st + (end - st) / 2;
    }
    return ans;
}