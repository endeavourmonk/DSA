#include<iostream>
using namespace std;

// Selection Sort
// TC: O(n^2)

// Find min-element index and swap it with ith form left.

void  selection_sort(int *arr, int n){
    for(int i = 0; i < n - 1; ++i){
        int minIn = i;
        for(int j = i + 1; j < n; ++j)
            if(arr[j] < arr[minIn])
                minIn = j;
        swap(arr[i], arr[minIn]);
    }
}

int  main(){
    int n = 10;
    int arr[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    selection_sort(arr, n);
    for(int i = 0; i < n; ++i)  cout << arr[i] << " ";
}