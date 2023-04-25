#include <iostream>
#include <vector>
using namespace std;

void subsets(vector<int> &arr, vector<vector<int>> &ans, vector<int> output, int in) {
    if (in >= arr.size()) {
        ans.push_back(output);
        return;
    }
    // excluding arr[in]
    subsets(arr, ans, output, in + 1);

    // including arr[in]
    output.push_back(arr[in]);
    subsets(arr, ans, output, in + 1);
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n), output;
    vector<vector<int>> ans;
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    subsets(arr, ans, output, 0);
    // for(int i = 0; i < ans.size(); ++i) {
    //     for(int j = 0; j < ans[i].size(); ++j)
    //         cout << ans[i][j] << ", ";
    //     cout << "\n";
    // }
    return 0;
}