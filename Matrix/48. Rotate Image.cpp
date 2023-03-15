48. Rotate Image
https://leetcode.com/problems/rotate-image/description/

// Approach 1: first reverse the matrix then swap the symmetry.
// TC: O(N2)
// SC: O(1)
void rotate(vector<vector<int>>& matrix) {
    reverse(matrix.begin(), matrix.end());
    for(int i = 0; i < matrix.size(); ++i)
        for(int j = i + 1; j < matrix.size(); ++j)
            swap(matrix[i][j], matrix[j][i]);
}

// Approach 2: First transpose matrix then reverse each row
// TC: O(N2)
// SC: O(1)

void rotate(vector<vector<int>>& matrix) {
    // making transpose
    for(int i = 0; i < matrix.size(); ++i)
        for(int j = i + 1; j < matrix.size(); ++j)
            swap(matrix[i][j], matrix[j][i]);
    // Now reversing each row
    for(int i = 0; i < matrix.size(); ++ i)
        reverse(matrix[i].begin(), matrix[i].end());
}