#include <iostream>
#include <vector>
using namespace std;

void __print(vector<int> , int , int );

int partitioner(vector<int> &arr, int low, int high) {
    int pivot = arr[low];
    int i = low, j = high;
    while (i < j) {
        while (arr[i] <= pivot && i < high)
            ++i;
        while (arr[j] >= pivot && j > low)
            --j;
        if (i < j)
            swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);
    return j;
}

void quick_sort(vector<int> &arr, int low, int high) {
    if(low >= high)
        return;
    int pivInd = partitioner(arr, low, high);
    quick_sort(arr, low, pivInd);
    quick_sort(arr, pivInd + 1, high);
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto &it : arr)
        cin >> it;

    quick_sort(arr, 0, n - 1);
    __print(arr, 0, n - 1);
}

void __print(vector<int> arr, int low, int hi) {
    for (int i = low; i <= hi; ++i)
        cout << arr[i] << " ";
    cout << endl;
}