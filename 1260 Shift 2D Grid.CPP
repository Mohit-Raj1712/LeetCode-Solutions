class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        
        int rows    = grid.size();
        int columns = grid[0].size();
        
        int N = rows * columns;
        k = k % N;
        
        vector<vector<int>> Output(rows, vector<int>(columns));
        
        for(int i = 0; i < N; i++) {
            int j = (i + k) % N;
            Output[j / columns][j % columns] = grid[i / columns][i % columns];
        }
        
        return Output;
    }
};