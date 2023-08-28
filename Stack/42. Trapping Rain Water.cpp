// 42. Trapping Rain Water

// Intuition: Calculate the total water trapped between all bars.
// Approach:
// I am calculating water on each bar and then summing all.
// For every bar I need max left bar and max right bar, And the water height on that bar will be the min(maxL, maxR) - height of that bar.
// To calculate the maxLeft height for every bar. Initialize the maxL[0] with the first element and then iterate from 1 to len and assign the max of height[i] or maxL[i - 1]. Do similar for maxR from len - 2 to 0.

// TC: O(N)
// SC: O(N)

int trap(vector<int> &height) {
    int len = height.size(), sum = 0;
    vector<int> maxL(len), maxR(len), water(len);

    // calculating maximum left for every bar.
    maxL[0] = height[0];
    for (int idx = 1; idx < len; ++idx) {
        maxL[idx] = max(maxL[idx - 1], height[idx]);
    }
    // calculating maximum left for every bar.
    maxR[len - 1] = height[len - 1];
    for (int idx = len - 2; idx >= 0; --idx) {
        maxR[idx] = max(maxR[idx + 1], height[idx]);
    }
    // Calculating water on top of every bar
    for (int idx = 0; idx < len; ++idx) {
        water[idx] = min(maxR[idx], maxL[idx]) - height[idx];
        sum += water[idx];
    }
    return sum;
}