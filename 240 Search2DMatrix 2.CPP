class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int r = 0;
        int c = matrix[0].size() - 1;
        int rows = matrix.size();

        while(r < rows && c >= 0)
        {
            if(target == matrix[r][c])
                return true;
            
            else if(target < Matrix[r][c]) 
                c -= 1;

            else if(target > Matrix[r][c]) 
                r += 1;
        }

        return false;
    }

};