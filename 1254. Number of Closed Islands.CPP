class Solution {
private:
    int n, m;
    
public:
    int numEnclaves(vector<vector<int>>& grid) {
        
        this -> n = grid.size(); this -> m = grid[0].size();
        
         for (int i = 0; i < m; i++)
             if (grid[0][i] == 1)
                 dfs(grid, 0, i);
        
        for (int i = 0; i < m; i++)
            if (grid[n - 1][i] == 1)
                dfs(grid, n - 1, i);
        
        for (int i = 0; i < n; i++)
            if (grid[i][0] == 1)
                dfs(grid, i, 0);
        
        for (int i = 0; i < n; i++)
            if (grid[i][m - 1] == 1)
                dfs(grid, i, m - 1);
        
        int output = 0;
        for (auto x : grid)
            for (auto y : x)
               if (y == 1)
                   output ++;
        
        return output;;
    }

private:
    void dfs(vector<vector<int>>& grid, int i, int j) {
        
        if (i < 0 || i == n || j < 0 || j == m || grid[i][j] == 0)
            return;
        
        grid[i][j] = 0;
        
        dfs(grid, i, j + 1);
        dfs(grid, i, j - 1);
        dfs(grid, i - 1, j);
        dfs(grid, i + 1, j);
        
        return;
    }
};