// 88. Merge Sorted Array
// https://leetcode.com/problems/merge-sorted-array/

// Two pointers approach

// Approach: set two pointers in nums1, one at end and another at m - 1. Start traversing the nums2 from end and check if nums2[k] < nums1[i]. because both arrays are sorted in ascending order then shift the ith element to the jth position and continue looking till you not reached the 0th index of nums1.
// or if the kth element >= the ith of the nums1 then put at jth position.

// if you reached the 0th index of nums1 check if there is any element remaining to put if yes then put them all in nums 1 from the jth location.

// TC: O(N + M)
// SC: O(1)

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int i = m - 1, j = (m + n - 1), k = n - 1;
    while (k >= 0 && i >= 0)
    {
        if (nums2[k] >= nums1[i])
            nums1[j--] = nums2[k--];
        else
            nums1[j--] = nums1[i--];
    }
    while (k >= 0)
        nums1[j--] = nums2[k--];
}
