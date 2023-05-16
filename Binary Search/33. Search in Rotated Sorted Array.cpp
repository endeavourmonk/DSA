// Search in Rotated Sorted Array
// Link: https://leetcode.com/problems/search-in-rotated-sorted-array/description/

// Approach: First we need to find the pivot index(Pivot element is the min element).
// As the array was sorted before and after rotation it was divided into two sorted parts.
// At last we need to figure out in which portion we need to search for a target, we use pivot index for that

// TC: O(log N)
// SC: O(1)

// Binary Search Function
int binary_search(int st, int end, vector<int> &nums, int target)
{
    while (st <= end)
    {
        int mid = st + (end - st) / 2;
        if (nums[mid] == target)
            return mid;
        else if (nums[mid] < target)
            st = mid + 1;
        else
            end = mid - 1;
    }
    return -1;
}

int search(vector<int> &nums, int target)
{
    // finding the pivot index
    int N = nums.size();
    int pivot_ind = -1, st = 0, end = N - 1;
    while (st < end)
    {
        int mid = st + (end - st) / 2;
        if (nums[mid] >= nums[0])
            st = mid + 1;
        else
            end = mid;
    }
    pivot_ind = st;

    // If target is on right portion of pivot index
    int target_ind = -1;
    if (target >= nums[pivot_ind] && target <= nums[N - 1])
        target_ind = binary_search(pivot_ind, N - 1, nums, target);

    // If target is in the left portion of the pivot index
    else
        target_ind = binary_search(0, pivot_ind - 1, nums, target);
    return target_ind;
}