// Painter's Partition Problem
// https://www.codingninjas.com/codestudio/problems/painter's-partition-problem_1089557

// Approach: Same as allocate books
// Why Binary Search?
// In this situation we found a sorted search space and for checking for a solution inside
// Search space we can say that a part can be neglected or not, so we can apply BS.

bool isPossibleToAllocate(vector<int> arr, int n, int m, int pagesToAllocate)
{
    int students = 1, sumOfPages = 0;
    for (auto it : arr)
    {
        if (sumOfPages + it <= pagesToAllocate)
        {
            sumOfPages += it;
        }
        else
        {
            students++;
            if (it > pagesToAllocate || students > m)
                return false;
            sumOfPages = it;
        }
    }
    return true;
}

int findLargestMinDistance(vector<int> &arr, int m)
{
    //    Write your code here.
    int low = 0, hi = 0, mid = 0, ans = 0;
    for (auto it : arr)
        hi += it;

    while (low <= hi)
    {
        mid = low + (hi - low) / 2;
        //  cout << "mid = " << mid << endl;
        if (isPossibleToAllocate(arr, arr.size(), m, mid))
        {
            ans = mid;
            hi = mid - 1;
        }
        else
            low = mid + 1;
    }
    return ans;
}