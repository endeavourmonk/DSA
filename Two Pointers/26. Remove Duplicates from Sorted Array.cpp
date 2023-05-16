26. Remove Duplicates from Sorted Array
https://leetcode.com/problems/remove-duplicates-from-sorted-array/

// Approach: Two pointers
// Put two pointers lets say i, j at the beginning of the array 
// and check whenever value at both indexes are not same then 
// assign the (i + 1)th index with the value at the jth index till 
// the lenghth of array.

//     TC: O(N)
//     SC: O(1)
    int removeDuplicates(vector<int>& nums) {
       int ans = 1, n = nums.size();
       for(int i = 0, j = 0; i < n && j < n; ++j) {
            if(nums[i] != nums[j]) {
                nums[++i] = nums[j];
                ans++;
            }
       }
       return ans;
    }