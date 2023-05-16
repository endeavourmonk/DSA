// Allocate Books
// https://www.codingninjas.com/codestudio/problems/allocate-books_1090540?leftPanelTab=0
// Approach: We define the search space possible which is min - 0 and max - sum of all elements. then applied binary search on the search space and checked if it is possible to allocate the ss[mid] to students. if it is possible then try to minimise it by changing hi to mid - 1. and for every possible store ans = mid of search space.
// For checking is possible to allocate ss[mid] books sum from the starting till <= mid and not out of students.

// Why Binary Search?
// In this situation we found a sorted search space and for checking for a solution inside
// Search space we can say that a part can be neglected or not, so we can apply BS.

// TC: O(n + log(sum elements) * log n)		SC: O(1)

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

int allocateBooks(vector<int> arr, int n, int m)
{
    // Write your code here.
    int low = 0, hi = 0, mid = 0, ans = 0;
    for (auto it : arr)
        hi += it;

    while (low <= hi)
    {
        mid = low + (hi - low) / 2;
        //  cout << "mid = " << mid << endl;
        if (isPossibleToAllocate(arr, n, m, mid))
        {
            ans = mid;
            hi = mid - 1;
        }
        else
            low = mid + 1;
    }
    return ans;
}