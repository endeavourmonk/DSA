75. Sort Colors
https://leetcode.com/problems/sort-colors/description/

// Approach: Three Pointers
// First set low and mid to the 0th index and high to last.
// Then check if the midth element is 1 then swap low and mid
// element and increment both, if it is 2 then swap high and 
// mid element or if it is 1 then increment mid. Do these 
// tasks until the mid <= high.

// TC: O(N)
// SC: O(1)

    void sortColors(vector<int>& nums) {
        if(nums.size() < 2)
            return;
        int low = 0, mid = 0, high = nums.size() - 1;
        while(mid <= high){
            if(nums[mid] == 0){
                swap(nums[low], nums[mid]);
                low++; 
                mid++;
            }
            else if(nums[mid] == 2){
                swap(nums[high], nums[mid]);
                high--; 
            }
            else if(nums[mid] == 1){
                mid++;
            }
        }
    }