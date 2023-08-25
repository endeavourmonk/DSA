// 85. Maximal Rectangle

// Intuition:
// We have to return the maximum size(area) of the rectangle formed by the ones.

// Approach:
// Break the matrix into 1-D arrays rows no. of times.
// Just creating a 1-D vector of 0's, nums for storing the values(heights) for every rows.
// add the every row element to the respective element in nums if the row element is not 0 otherwise the nums respective element will be = 0.
// For each state of get the max Area of the nums using the max area histogram.
// And return the max area from the function.

// for ex: we have 4 X 5 matrix.
//         1 X 5: nums = [1, 0, 1, 0, 0] , max_area = 1
//         2 X 5: nums = [2, 0, 2, 1, 1] , max_area = 3
//         3 X 5: nums = [3, 1, 3, 3, 2] , max_area = 6
//         4 X 5: nums = [4, 0, 0, 3, 0] , max_area = 4

//     Out of these all areas the maximum is 6 which is the ans.

// TC: O(rows * 2cols) => O(rows * cols)
// SC: O(cols)

int MaxAreaHistogram(vector<int> &nums) {
    int len = nums.size();
    vector<int> left(len, -1), right(len, len);
    stack<pair<int, int>> st; // st<{idx, val}>
    for (int idx = 0; idx < len; ++idx) {
        if (!st.empty() && st.top().second < nums[idx])
            left[idx] = st.top().first;
        else if (!st.empty() && st.top().second >= nums[idx]) {
            while (!st.empty() && st.top().second >= nums[idx])
                st.pop();
            if (!st.empty())
                left[idx] = st.top().first;
        }
        st.push({idx, nums[idx]});
    }

    st = stack<pair<int, int>>();

    for (int idx = len - 1; idx >= 0; --idx) {
        if (!st.empty() && st.top().second < nums[idx])
            right[idx] = st.top().first;
        else if (!st.empty() && st.top().second >= nums[idx]) {
            while (!st.empty() && st.top().second >= nums[idx])
                st.pop();
            if (!st.empty())
                right[idx] = st.top().first;
        }
        st.push({idx, nums[idx]});
    }
    int max_area = 0;
    for (int idx = 0; idx < len; ++idx) {
        int area = nums[idx] * (right[idx] - left[idx] - 1);
        max_area = max(area, max_area);
    }
    return max_area;
}

int maximalRectangle(vector<vector<char>> &matrix) {
    int rows = matrix.size(), cols = matrix[0].size(), max_area = 0;
    vector<int> nums(cols, 0);

    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < cols; ++col) {
            int height = matrix[row][col] - 48;
            if (!height)
                nums[col] = 0;
            else
                nums[col] += height;
        }
        int area = MaxAreaHistogram(nums);
        max_area = max(max_area, area);
    }
    return max_area;
}