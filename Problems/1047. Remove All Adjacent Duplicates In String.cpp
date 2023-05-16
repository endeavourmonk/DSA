// 1047. Remove All Adjacent Duplicates In String
// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/

// Approach: Stack
// Traverse the string and look if current element is present in the stack,
// if it is present then pop it else push it inside the stack.
// TC: O(N);
// SC: (N)
string removeDuplicates(string s)
{
    string res = "";
    for (char &ch : s)
    {
        if (res.size() && ch == res.back())
            res.pop_back();
        else
            res.push_back(ch);
    }
    return res;
}