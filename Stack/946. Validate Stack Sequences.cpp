// 946. Validate Stack Sequences

// Approach:
// Just traverse the pushed and keep pushing the element in the stack.
// After pushing every time keep chacking if the top is equals to the popped[j], if yes then keep popping till the stack or the popped become empty.
// If the stack is empty at the end then the given operations is possible otherwise not.

// TC: O(N)
// SC: O(N)

bool validateStackSequences(vector<int> &pushed, vector<int> &popped) {
    int top = -1, i = 0, j = 0;
    stack<int> st;

    for (i = 0, j = 0; i < pushed.size(); i++) {
        st.push(pushed[i]);
        while (!st.empty() && j < popped.size() && st.top() == popped[j]) {
            st.pop();
            j++;
        }
    }

    return st.empty();
}