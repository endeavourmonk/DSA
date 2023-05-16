//  Duplicate In Array
//  Topics: Arrays, Bit Manipulation
//  Link: https://www.codingninjas.com/codestudio/problems/duplicate-in-array_893397?source=youtube&campaign=love_babbar_codestudio1&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio1&leftPanelTab=1

//  Approach 1:- Using XOR

//  As given in the problem that array contains all the elements from 1 - (N-1) so that applying XOR with
//  all the elements and then from 1 - (N -1) because all the xor of same elements will become 0.

//  TC: O(N)
int findDuplicate(vector<int> &arr)
{
    // Write your code here
    int ans = 0;
    for (int i = 0; i < arr.size(); ++i)
        ans ^= arr.at(i);
    int N = arr.size();
    for (int i = 1; i < N; ++i)
        ans ^= i;
    return ans;
}