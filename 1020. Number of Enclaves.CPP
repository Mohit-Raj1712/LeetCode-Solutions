class Solution {
private:
    int N, M;
    int output = 0;
    
public:
    int numEnclaves(vector<vector<int>>& grid) {
        
        this -> N = grid.size();
        this -> M = grid[0].size();
        
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                if (i == 0 || i == N - 1 || j == 0 || j == M - 1)
                    dfs(grid, i, j);
        
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                if (grid[i][j] == 1)
                    output ++;
        
        return output;
    }
    
private:
    void dfs(vector<vector<int>>& grid, int x, int y) {
        
        if (x < 0 || x == N || y < 0 || y == M)
            return;
            
        if (grid[x][y] == 0 || grid[x][y] == 2)
            return;
            
        grid[x][y] = 2;
        
        dfs(grid, x, y - 1);
        dfs(grid, x, y + 1);
        dfs(grid, x - 1, y);
        dfs(grid, x + 1, y);
        
        return;
    }
};