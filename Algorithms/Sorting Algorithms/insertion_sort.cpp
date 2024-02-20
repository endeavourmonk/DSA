#include<iostream>
using namespace std;

// starting with index 1. storing val of that index and checking all element previous
// from this index till 0th index if previous elements are smaller then shifting them
// right and finally changing the value at j + 1th position to val.

// Insertion Sort
// TC: O(n^2)

void insertion_sort(int *arr, int n) {
    for(int i = 1; i < n; ++i){
        int val = arr[i];
        int j = i - 1;
        while((j >= 0) && (arr[j] > val)) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = val;
    }
}

void recursiveInsertionSort(vector<int> &arr, int n) {
    if (n <= 1)
        return;
    recursiveInsertionSort(arr, n - 1);
    int val = arr[n - 1], j = n - 2;
    for (j = n - 2; j >= 0 && arr[j] > val; --j)
        arr[j + 1] = arr[j];
    arr[j + 1] = val;
}


int  main() {
    int n;
    cin >> n;
    int *arr = new int(n);
    for(int i = 0; i < n; i++)  cin >> arr[i];
    insertion_sort(arr, n);
    for(int i = 0; i < n; ++i)  cout << arr[i] << " ";
}