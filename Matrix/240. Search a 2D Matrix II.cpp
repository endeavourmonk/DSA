240. Search a 2D Matrix II
https://leetcode.com/problems/search-a-2d-matrix/description/

// Approach: iterating over the rows, as the rows and cols are sorted,
// look if the target is less than the starting element then target
// cannot be found. Again if the target is greater than the ending
// element of the row then look into another row. finally apply
// binary search over the current row.

// TC: O(m * log n)
// SC: O(1)

bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size(), col = matrix[0].size();
        for(int i = 0; i < row; ++i){
                if(target < matrix[i][0])   return false;
                if(target > matrix[i][col - 1]) continue;
                // looking for target in the ith row
                int st = 0, end = col - 1;
                while(st <= end){
                    int mid = st + (end - st)/2;
                    if(matrix[i][mid] == target)    return true;
                    if(matrix[i][mid] > target) end = mid - 1;
                    else    st = mid + 1;
                }
        }
        return false;
    }