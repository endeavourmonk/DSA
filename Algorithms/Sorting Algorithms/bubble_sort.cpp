#include<iostream>
using namespace std;

// Bubble Sort
// TC: O(n^2)

void bubble_sort(int *arr, int len) {
    for (int i = 0; i < len - 1; i++) {
        for (int j = 0; j < len - i -1; j++)
            if (arr[j] > arr[j+1])
                swap(arr[j], arr[j+1]);
    }
}

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
    int n = 10;
    int arr[] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
    bubble_sort(arr, n);
    for(int i = 0; i < n; i++)  cout << arr[i] << " ";
}