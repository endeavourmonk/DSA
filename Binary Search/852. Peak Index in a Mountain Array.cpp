// Peak Index in a Mountain Array
// Link: https://leetcode.com/problems/peak-index-in-a-mountain-array/description/

// Approach: we want to look in that side of mid where mid + 1 element is greater than
// 	Mid element.
// if arr[mid]< arr[mid+1] then low = mid + 1 else high = mid. Because
// mid can be a peak element.
// TC: O(log N)		SC: O(1)

int peakIndexInMountainArray(vector<int> &arr)
{
    int l = 0, h = arr.size() - 1;
    while (l < h)
    {
        int mid = l + (h - l) / 2;
        if (arr[mid] < arr[mid + 1])
            l = mid + 1;
        else
            h = mid;
    }
    return l;
}