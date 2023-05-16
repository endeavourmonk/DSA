//  Pair Sum
//  Arrays
//  Link: https://www.codingninjas.com/codestudio/problems/pair-sum_697295?source=youtube&campaign=love_babbar_codestudio1&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio1

//  Approach: Traverse both array and look for pairs required.

//  TC: O(N^2)

vector<vector<int>> pairSum(vector<int> &arr, int s)
{
    // Write your code here.
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    for (int j = 0; j < arr.size(); ++j)
    {
        for (int i = j + 1; i < arr.size(); ++i)
        {
            if (arr[i] + arr[j] == s)
            {
                vector<int> tem;
                tem.push_back(min(arr[i], arr[j]));
                tem.push_back(max(arr[i], arr[j]));
                ans.push_back(tem);
            }
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}