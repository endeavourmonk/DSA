485. Max Consecutive Ones
https://leetcode.com/problems/max-consecutive-ones/description/

// Approach: Just traverse the array and count 1 and store the 
// maximum count inside ans. Whenever not found 1 change count to 
// zero.
// TC: O(N)
// SC:O(1)
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ct = 0, ans = 0;
        for(auto it : nums) {
            if(it == 1)
                ans = max(ans, ++ct);
            else 
                ct = 0;
        }
        return ans;
    }