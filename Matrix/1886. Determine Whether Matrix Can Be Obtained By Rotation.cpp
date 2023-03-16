1886. Determine Whether Matrix Can Be Obtained By Rotation
https://leetcode.com/problems/determine-whether-matrix-can-be-obtained-by-rotation/description/

// Approach: We need to check if the matrix is equal to the target after rotating 0, 90, 180 and 270 degrees. 
// TC: O(N^2)
// SC: O(1)

bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int sz = mat.size(), n = 3;
        if(mat == target)   return true;    // for 0 deg

        while(n--){ 
            // transposing the matrix   
            for(int i = 0; i < sz; ++i)
                for(int j = i + 1; j < sz; ++j)
                    swap(mat[i][j], mat[j][i]);
            
            // reversing each rows to obtain 90 deg rotation
            for(int i = 0; i < sz; ++i)
                reverse(mat[i].begin(), mat[i].end());
            if(mat == target)   return true;
        }
        return false;
}