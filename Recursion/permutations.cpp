#include <iostream>
#include <vector>
using namespace std;

// Approach: Here we are iterating over the array and maintaining a frequency map, if element 
// is not used then we push it in ans. 

// TC: O(N! * N)
// SC: O(N)

void permutations(vector<vector<int> > &ans, vector<int> &ds, vector<int> &arr, int *freq) {
    if (ds.size() >= arr.size()) {
        ans.push_back(ds);
        return;
    }

    for (int i = 0; i < arr.size(); ++i) {
        if (!freq[i]) {
            ds.push_back(arr[i]);
            freq[i] = 1;
            permutations(ans, ds, arr, freq);
            // backtracking
            ds.pop_back();
            freq[i] = 0;
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n), ds;
    vector<vector<int> > ans;
    int freq[n] = {0};
    for (auto &it : arr)
        cin >> it;
    permutations(ans, ds, arr, freq);
    for (auto it = ans.begin(); it != ans.end(); it++) {
        for (auto itr = it->begin(); itr != it->end(); ++itr)
            cout << *itr << " ";
        cout << endl;
    }
}