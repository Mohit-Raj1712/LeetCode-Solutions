class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        const int N = matrix.size();
        const int M = matrix[0].size();

        vector<int> spiral_order;

        int start_row = 0, start_column = 0, end_row = N - 1, end_column = M - 1;

        while (start_row <= end_row || start_column <= end_column)
        {
            if (start_row <= end_row)
            for (int j = start_column; j <= end_column; j++)
                spiral_order.push_back(matrix[start_row][j]);
            
            start_row ++;
            
            if (start_column <= end_column)
            for (int i = start_row; i <= end_row; i ++)
                spiral_order.push_back(matrix[i][end_column]);
            
            end_column --;

            if (start_row <= end_row)
            for (int j = end_column; j >= start_column; j--)
                spiral_order.push_back(matrix[end_row][j]);
            
            end_row --;

            if (start_column <= end_column)
            for (int i = end_row; i >= start_row; i--)
                spiral_order.push_back(matrix[i][start_column]);
            
            start_column ++;
        }

        return spiral_order;
    }
};