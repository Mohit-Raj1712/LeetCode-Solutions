class Solution {
public:
    void rotate(vector<vector<int>>& grid) 
    {
        int N = grid.size();
        
        for(int i = 0; i < N; i++)
        {
            for(int j = i + 1; j < N; j++)
               swap(grid[i][j], grid[j][i]);
            
            int left_pointer = 0, right_pointer = N - 1;
            
            while (left_pointer < right_pointer)
            {
                swap(grid[i][left_pointer], grid[i][right_pointer]);
                left_pointer ++;
                right_pointer --;
            }
        }

        return;
    }
};