#include <iostream>
#include <vector>
using namespace std;

// TC: O(N^2)
void recursiveInsertionSort(vector<int> &arr, int n) {
    if(n <= 1)
        return;
    recursiveInsertionSort(arr, n - 1);
    int val = arr[n - 1], j = n - 2;
    for(j = n - 2; j >= 0 && arr[j] > val; --j)
        arr[j + 1] = arr[j];
    arr[j + 1] = val;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    recursiveInsertionSort(arr, n);
    cout << "After Sorting:" << "\n";
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
}