#include <iostream>
#include <vector>
using namespace std;

// Approach: Here we are iterating from index to array size - 1, and swapping ith and indexth 
// element, and calling the function with index + 1 and when our index exceeds the size of the 
// array we store the state of the array inside the answer, and fianlly doing backtracking by swapping
// again. 

// TC: O(N! * N)

void permutations(vector<vector<int> > &ans, vector<int> &arr, int index) {
    if (index >= arr.size()) {
        ans.push_back(arr);
        return;
    }
    for (int i = index; i < arr.size(); ++i) {
        swap(arr[i], arr[index]);
        permutations(ans, arr, index + 1);
        swap(arr[i], arr[index]);
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<vector<int> > ans;
    for (auto &it : arr)
        cin >> it;
    permutations(ans, arr, 0);
    for (auto it = ans.begin(); it != ans.end(); it++) {
        for (auto itr = it->begin(); itr != it->end(); ++itr)
            cout << *itr << " ";
        cout << endl;
    }
}