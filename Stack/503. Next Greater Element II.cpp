// 503. Next Greater Element II

// Approach:
//  Created the vector of size nums and initialized with -1.
// Because we are expected to get the next greater circularly so that pushing all the elements of nums from end int the stack.
// then iterating the nums from the end and look for cases:
// 1. if stack is not empty and the top > current element then that's the next greater.
// 2. if stack is not empty and the top < current element then pop the stack till the stack is not empty and top is smaller than top.
// finally check if stak is still not empty then the top is the nearest greater.

// and push the current element in the stack.

// TC: O(N)
// SC: O(N)

vector<int> nextGreaterElements(vector<int> &nums) {
    int len = nums.size();
    vector<int> ans(len, -1);
    stack<int> stack;

    for (int it = len - 1; it >= 0; --it) {
        stack.push(nums[it]);
    }

    for (int it = len - 1; it >= 0; --it) {
        if (!stack.empty() && stack.top() > nums[it]) {
            ans[it] = stack.top();
        } else if (!stack.empty() && stack.top() <= nums[it]) {
            while (!stack.empty() && stack.top() <= nums[it])
                stack.pop();

            if (!stack.empty())
                ans[it] = stack.top();
        }
        stack.push(nums[it]);
    }
    return ans;
}
