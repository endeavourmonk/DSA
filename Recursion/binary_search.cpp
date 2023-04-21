#include <iostream>
#include <vector>
using namespace std;

// TC: O(log N)
int recursiveBinarySearch(vector<int> &arr, int st, int end, int key) {
    int mid = st + (end - st) / 2;
    if (arr[mid] == key)
        return mid;
    if (st > end)
        return -1;
    if (arr[mid] > key)
        return recursiveBinarySearch(arr, st, mid - 1, key);
    else
        return recursiveBinarySearch(arr, mid + 1, end, key);
}

int main() {
    int n, key;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    cin >> key;
    int idx = recursiveBinarySearch(arr, 0, n, key);
    if (idx == -1)
        cout << "Not Found";
    else
        cout << "Found at: " << idx;
}