#include <iostream>
#include <vector>
using namespace std;


// TC: O(N log N)
// SC: O(N)
void merge(vector<int> &arr, int begin, int mid, int end) {
    int first = mid - begin + 1, second = end - mid;    // sizes of subarrays
    vector<int> firstArray(first), secondArray(second); 

    // copying array contents into subarrays
    for (int i = 0; i < first; ++i)
        firstArray[i] = arr[begin + i];
    for (int i = 0; i < second; ++i)
        secondArray[i] = arr[mid + 1 + i];

    // merging both subarrays into arr
    int firstInd = 0, secondInd = 0, mergeInd = begin;  // indexes of both subarrays and merge array
    while (firstInd < first && secondInd < second)
    {
        if (firstArray[firstInd] <= secondArray[secondInd])
            arr[mergeInd++] = firstArray[firstInd++];
        else
            arr[mergeInd++] = secondArray[secondInd++];
    }

    // copy remaining elements of the left subarray into merged array
    while (firstInd < first)
        arr[mergeInd++] = firstArray[firstInd++];
    // copy remaining elements of the right subarray into merged array
    while (secondInd < second)
        arr[mergeInd++] = secondArray[secondInd++];
}

void merge_sort(vector<int> &arr, int begin, int end) {
    if (begin >= end)
        return;
    int mid = begin + (end - begin) / 2;
    merge_sort(arr, begin, mid);
    merge_sort(arr, mid + 1, end);
    merge(arr, begin, mid, end);
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto &it : arr)
        cin >> it;

    merge_sort(arr, 0, n - 1);

    for (auto it : arr)
        cout << it << " ";
}