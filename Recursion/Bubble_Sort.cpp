#include <iostream>
#include <vector>
using namespace std;

// TC: O(N^2)
void recursiveBubbleSort(vector<int> &arr, int n) {
    if(n <= 1)
        return;
    // largest element is set to the last
    for(int i = 0; i < n - 1; ++i)
        if(arr[i] > arr[i + 1])
            swap(arr[i], arr[i + 1]);

    recursiveBubbleSort(arr, n - 1);
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    recursiveBubbleSort(arr, n);
    cout << "After Sorting:" << "\n";
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
}