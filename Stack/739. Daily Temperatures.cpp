// 739. Daily Temperatures

// Approach:
// Created a vector of size input and initialized it with 0.
// traverse the input array:
//     1. If the stack is empty, then their is not greater element than current.
//     2. If the stack is not empty and the temperatures[top] is greater then ans[it] = stack.top() - it.
//         which is the distance between the current and the next greater. we are storing the
//         index of the nearest greater.
//     3. If the stack is not empty and the temperatures[top] element is not greater then pop till the top is less
//         than current or the stack becomes empty, finally check if the stack is not empty then
//         assign the difference in the ans as in step 2.
// Push the it in the stack.

// TC: O(N)
// SC: O(N)

vector<int> dailyTemperatures(vector<int> &temperatures) {
    int size = temperatures.size();
    vector<int> ans(size, 0);
    stack<int> stack;

    for (int it = size - 1; it >= 0; --it) {
        if (!stack.empty() && temperatures[stack.top()] > temperatures[it]) {
            ans[it] = stack.top() - it;
        } else if (!stack.empty() && temperatures[stack.top()] <= temperatures[it]) {
            while (!stack.empty() && temperatures[stack.top()] <= temperatures[it]) {
                stack.pop();
            }
            if (!stack.empty()) {
                ans[it] = stack.top() - it;
            }
        }
        stack.push(it);
    }
    return ans;
}