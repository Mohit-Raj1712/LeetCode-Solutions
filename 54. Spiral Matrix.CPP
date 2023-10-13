class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        vector<int> output;
        
        int start_row = 0, start_column = 0;
        int end_row = matrix.size(), end_column = matrix[0].size();
        
        while (start_row < end_row || start_column < end_column)
        {
            if (start_row < end_row)
            for (int i = start_column; i < end_column; i++)
                output.push_back(matrix[start_row][i]);
            
            start_row ++;
            
            if (start_column < end_column)
            for (int i = start_row; i < end_row; i++)
                output.push_back(matrix[i][end_column - 1]);
            
            end_column --;
            
            if (start_row < end_row)
            for (int i = end_column - 1; i >= start_column; i--)
                output.push_back(matrix[end_row - 1][i]);
            
            end_row --;
            
            if (start_column < end_column)
            for (int i = end_row - 1; i >= start_row; i--)
                output.push_back(matrix[i][start_column]);
            
            start_column ++;
            
        }
        
        return output;
    }
};