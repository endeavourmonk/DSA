#include<iostream>
using namespace std;

// TC: O(lon N)

// algorithm to search data in ascending order arranged array
int binary_search_asc(int *arr, int len, int key){
    int start = 0, mid, end = len - 1;
    while(end >= start){
        mid = start + ((end - start) / 2);
        if(arr[mid] == key) return mid;
        else if(key < arr[mid])  end = mid - 1;
        else start = mid + 1;
    }
    return -1;
}

// algorithm to search data in descending order arranged array
int binary_search(int *arr, int len, int key){
    int start = 0, mid, end = len - 1;
    while(end >= start){
        mid = start + ((end - start) / 2);
        if(arr[mid] == key) return mid;
        else if(key > arr[mid])  end = mid - 1;
        else start = mid + 1;
    }
    return -1;
}

int main(){
    int arr[] = {1, 3, 5, 6, 8, 9, 12, 15};
    int len = sizeof(arr)/sizeof(int);
    int key = 5;
    int index = binary_search(arr, len, key);
    if(index == -1) cout << "Element not found.";
    else cout << "Element found at index " << index;
}
