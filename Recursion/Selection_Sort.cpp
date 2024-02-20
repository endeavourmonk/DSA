#include <iostream>
#include <vector>
using namespace std;

// TC: O(N^2)
void InsertionSort(vector<int> &arr, int n) {
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    InsertionSort(arr, n);
    cout << "After Sorting:"
         << "\n";
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
}