#include <iostream>
#include <vector>
using namespace std;

void print(vector<int> &arr) {
    for (auto it : arr)
        cout << it << " ";
    cout << "\n";
}

void insert(vector<int> &arr, int tmp) {
    cout << "insert ";
    print(arr);
    if (tmp >= arr[arr.size() - 1] || arr.size() == 0) {
        arr.push_back(tmp);
        return;
    }
    int val = arr[arr.size() - 1];
    arr.pop_back();
    insert(arr, tmp);
    arr.push_back(val);
}

void sort(vector<int> &arr) {
    cout << "sort";
    print(arr);
    // base case
    if (arr.size() == 0)
        return;
    int val = arr[arr.size() - 1];
    arr.pop_back();
    sort(arr);
    insert(arr, val);
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto &it : arr)
        cin >> it;

    sort(arr);
    cout << "Sorted Array: ";
    print(arr);
    return 0;
}