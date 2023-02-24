// 283. Move Zeroes
// https://leetcode.com/problems/move-zeroes/description/

// Appraoch: two pointer method. Putting one pointer at 0th index and another at 1st index and traversing till both < n. if both elements are 0 then move 2nd pointer and if one zero or none zero moving both pointers.

// TC: O(N)
// SC: O(1)

    void moveZeroes(vector<int>& nums) {
        for(int i = 0, j = 1; ((i != nums.size()) && (j != nums.size()));){
            if(nums[i] == 0 && nums[j] != 0){
                swap(nums[i], nums[j]);
                i++; 
                j++;
            }
            else if(nums[i] == 0 && nums[j] == 0)
                 j++;
            else{
                    i++;
                    j++;
            }
        }
    }