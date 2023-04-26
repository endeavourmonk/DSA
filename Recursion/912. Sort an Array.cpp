// 912. Sort an Array
// https : // leetcode.com/problems/sort-an-array/

// Approach: Merge Sort
// TC: O(log N)
// SC: O(N)


void merge(vector<int> &nums, int low, int mid, int high) {
    int first_size = mid - low + 1, second_size = high - mid;
    int first_subarr[first_size], second_subarr[second_size];
    for (int i = 0; i < first_size; ++i)
        first_subarr[i] = nums[low + i];
    for (int i = 0; i < second_size; ++i)
        second_subarr[i] = nums[mid + i + 1];
    int nums_ind = low, subarr1_ind = 0, subarr2_ind = 0;
    while (subarr1_ind < first_size && subarr2_ind < second_size) {
        if (first_subarr[subarr1_ind] < second_subarr[subarr2_ind])
            nums[nums_ind++] = first_subarr[subarr1_ind++];
        else
            nums[nums_ind++] = second_subarr[subarr2_ind++];
    }
    while (subarr1_ind < first_size)
        nums[nums_ind++] = first_subarr[subarr1_ind++];
    while (subarr2_ind < second_size)
        nums[nums_ind++] = second_subarr[subarr2_ind++];
}

void mergeSort(vector<int> &nums, int low, int high) {
    if (low >= high)
        return;
    int mid = low + (high - low) / 2;
    mergeSort(nums, low, mid);
    mergeSort(nums, mid + 1, high);
    merge(nums, low, mid, high);
}

vector<int> sortArray(vector<int> &nums) {
    mergeSort(nums, 0, nums.size() - 1);
    return nums;
}