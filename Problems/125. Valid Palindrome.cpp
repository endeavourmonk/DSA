// 125. Valid Palindrome
// https://leetcode.com/problems/valid-palindrome/description/

// Approach: putting two pointers on string one at front and another at end.
// then skipping all non alpha-numeric characters from both ends.
// then converting all occurences to uppercase and then comparing them if anytime they are not equal means the string is not a palindrome.

// TC: O(N)
// SC: O(1)

    bool isPalindrome(string s) {
       for(int i = 0, j = s.length() - 1; i < j; ++i, --j){
            while(!isalnum(s[i]) && i < j)  ++i;
            while(!isalnum(s[j]) && i < j)  --j;
            if(toupper(s[i]) != toupper(s[j]))   return false;
        }
        return true;
    }