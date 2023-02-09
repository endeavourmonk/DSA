// Sqrt(x)
// Link: https://leetcode.com/problems/sqrtx/description/

// Approach: Sq root will be in the range of 0 to x, and the range is sorted so we can apply binary search on it and just store if mid * mid is less than x because it can be the required nearest value if x is not a perfect sq.
// TC: O(log N)
// SC: O(1)

int mySqrt(int x)
{
    int low = 0, high = x, ans = 0;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if ((1LL * mid * mid) == x)
            return mid;
        else if ((1LL * mid * mid) > x)
            high = mid - 1;
        else
        {
            ans = mid;
            low = mid + 1;
        }
    }
    return ans;
}