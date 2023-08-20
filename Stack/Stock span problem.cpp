// Stock span problem gfg

// Intuition: Find the distance between the current and the first greater left.

// Approach: Traverse the input array from 0 to N. Maintain a stack of indices.
// For every index check:
// case 1: if the stack is empty then there is no greater in the left.
// case 2: if stack is not empty and the price[st.top()] is greater than the
// current element then that's our nearest greater left. Update the ans[index] with
// the distance between the indices.
// case 3: if stack is not empty and the price[st.top()] <= current element then pop
// till the stack become empty or you found nearest greater.
// if stack become empty then no greater in the left, update ans[i] with i + 1.
// otherwise update ans[i] = i - stack.top() + 1.

// TC: O(N)
// SC: O(N)

vector<int> calculateSpan(int price[], int n) {
    // Your code here
    stack<int> st;
    vector<int> ans(n, 1);
    for (int in = 0; in < n; ++in) {
        if (!st.empty() && price[st.top()] > price[in]) {
            ans[in] = in - st.top();
        } else if (!st.empty() && price[st.top()] <= price[in]) {
            while (!st.empty() && price[st.top()] <= price[in])
                st.pop();

            if (!st.empty())
                ans[in] = in - st.top(); // no of elements between the current and the first greatest left including current
            else
                ans[in] = in + 1; // if stack is empty means we don't have greater element in the left
        }
        st.push(in);
    }
    return ans;
}