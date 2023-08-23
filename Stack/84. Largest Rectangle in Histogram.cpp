// 84. Largest Rectangle in Histogram

// Intuition: Need to maximize the area formed by a rectangle of combining rectangles from left and right.

// If the heights of the rectangles in the left/right sides are more than or equlal to the lenght of the current rectangle we can combine those to calc the area and the resultant area will be the height of current rect * width.

// Width can be calculated by the distance between the indices of the choosen rightmost and the leftmost rect.

// Approach:
// To choose the leftmost rect we can find the nearest smaller left and similarly nearest smaller right using the stack in O(N).
// Store their index in two vectors, say left and right.
// If there is no smaller rect in the left we can use -1 as index and for right len as index.
// Width will be equal to the right - left - 1.
// Now traverse the heights array and calculate the area for every rect and store the max_area.

// TC: O(N)
// SC: O(N)

int largestRectangleArea(vector<int> &heights) {
    int len = heights.size();
    vector<int> left(len, -1), right(len, len);
    stack<pair<int, int>> st;

    // storing the indices of nearest smaller left for each element
    for (int in = 0; in < len; ++in) {
        if (!st.empty() && st.top().second < heights[in]) {
            left[in] = st.top().first;
        } else if (!st.empty() && st.top().second >= heights[in]) {
            while (!st.empty() && st.top().second >= heights[in])
                st.pop();
            if (!st.empty())
                left[in] = st.top().first;
        }
        st.push({in, heights[in]});
    }

    st = stack<pair<int, int>>();

    // storing the indices of nearest right element for each element
    for (int in = len - 1; in >= 0; in--) {
        if (!st.empty() && st.top().second < heights[in]) {
            right[in] = st.top().first;
        } else if (!st.empty() && st.top().second >= heights[in]) {
            while (!st.empty() && st.top().second >= heights[in])
                st.pop();
            if (!st.empty())
                right[in] = st.top().first;
        }
        st.push({in, heights[in]});
    }

    // calculate area for every rectangle by combining the nearer left and rigt and store the maximum area.
    int max_area = 0;
    for (int in = 0; in < len; ++in) {
        int area = heights[in] * (right[in] - left[in] - 1);
        max_area = max(max_area, area);
    }
    return max_area;
}