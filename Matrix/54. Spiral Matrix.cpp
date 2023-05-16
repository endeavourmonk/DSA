54. Spiral Matrix
https://leetcode.com/problems/spiral-matrix/description/

// Approach: track starting row, ending row, starting col and ending col, count printed elements
// and total elements. First print starting row and increment starting row, then ending col 
// and decrement it, again ending row and decrement it and finally starting col and increment it.
// Do these things in a loop till your printed element count is less than the total count of 
// elements in the matrix.
    
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row = matrix.size(), col = matrix[0].size();
        int total_el = row * col, ct = 0;
        int st_row = 0, end_row = row - 1, st_col = 0, end_col = col - 1;
        vector<int> ans;
        while(ct < total_el){
            // starting row
            for(int i = st_col; ct < total_el && i <= end_col; ++i){
                ans.emplace_back(matrix[st_row][i]);
                ct++;
            }
            st_row++;

            // ending column
            for(int i = st_row; ct < total_el && i <= end_row; ++i){
                ans.emplace_back(matrix[i][end_col]);
                ct++;
            }
            end_col--;

            // ending row
            for(int i = end_col; ct < total_el && i >= st_col; --i){
                ans.emplace_back(matrix[end_row][i]);
                ct++;
            }
            end_row--;

            // starting column
            for(int i = end_row; ct < total_el && i >= st_row; --i){
                ans.emplace_back(matrix[i][st_col]);
                ct++;
            }
            st_col++;        
        }
        return ans;        
    }