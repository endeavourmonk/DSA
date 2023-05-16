90. Subsets II
https://leetcode.com/problems/subsets-ii/


// Approach: 
class Solution {
public:

void subsets(vector<int> &arr, vector<vector<int>> &ans, vector<int> output, int in) {
     if (in >= arr.size()) {
        bool alreadyExists = false;
        for(int i = 0; i < ans.size(); ++i) {
            vector<int> tem = ans[i];
            sort(tem.begin(), tem.end());
            sort(output.begin(), output.end());
            if(tem == output) {
                alreadyExists = true;
                break;
            }
        }
        if(!alreadyExists)
            ans.push_back(output);
        return;
    }
    // excluding arr[in]
    subsets(arr, ans, output, in + 1);

    // including arr[in]
    output.push_back(arr[in]);
    subsets(arr, ans, output, in + 1);
}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> output;
        vector<vector<int>> ans;
        subsets(nums, ans, output, 0);
        return ans;
    }
};