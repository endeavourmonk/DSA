// 17. Letter Combinations of a Phone Number
// https://leetcode.com/problems/letter-combinations-of-a-phone-number/

// Approach: Recursion, Backtracking
// First Created a map of all the symbols for the respective keys. Then calling out recursive function and whenever index >= size of digits then save the output inside ans. Again getting each digit using the index and obtaining its resultant mapping. And for each character of the mapping get all the combinations of all the digits using the index and store in ans. Whenever the function returns remove the previous character from the output to avoid duplicacy and pass the next character.
    void generateCombinations(string digits, vector<string> &ans, string output, string *map, int in) {
        if (in >= digits.length()) {
            ans.push_back(output);
            return;
        }
        
        int dig = digits[in] - '0';
        string values = map[dig];

        for (int i = 0; i < values.length(); ++i) {
            output.push_back(values[i]);
            generateCombinations(digits, ans, output, map, in + 1);
            output.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
       vector<string> ans;
       string map[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        if (digits.length() != 0)
            generateCombinations(digits, ans, "", map, 0);
        return ans;
    }