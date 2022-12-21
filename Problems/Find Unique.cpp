//  Find Unique
//  Topics: Arrays, Bit Manipulation
//  Link: https://www.codingninjas.com/codestudio/problems/find-unique_625159?source=youtube&campaign=love_babbar_codestudio1&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio1&leftPanelTab=1

// Approach 1:- Using XOR

//  Using XOR because all the xor of same elements will become 0. And (0 ^ unique_ele) will be unique_ele.

//  TC: O(N)
int findUnique(int *arr, int size)
{
    // Write your code here
    int ans = 0;
    for (int i = 0; i < size; ++i)
        ans ^= arr[i];
    return ans;
}

//  Approach 2:- First Sorting and then traversing whole array.

//  TC: O(N)
int findUnique(int *arr, int size)
{
    // Write your code here
    sort(arr, arr + size);
    for (int i = 0; i < size; i += 2)
    {
        if (i == size - 1)
            return arr[i];
        if (arr[i] != arr[i + 1])
            return arr[i + 1];
    }
}