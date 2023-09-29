// Bottom Up Approach, Dynamic Programming

class Solution {
private:
    int N, M;
    vector<vector<int>> dp;
    
public:
    int minPathSum(vector<vector<int>>& grid) {
        
        int output = 0;
        this -> N = grid.size();
        this -> M = grid[0].size();
        
        dp.resize(N, vector<int>(M, 0));
        
        for (int i = N - 1; i >= 0; i--)
        {
            for (int j = M - 1; j >= 0; j--)
            {
                if (i == N - 1 && j == M - 1)
                    dp[i][j] = grid[i][j];
                
                else if (i == N - 1)
                    dp[i][j] = dp[i][j + 1] + grid[i][j];
                
                else if (j == M - 1)
                    dp[i][j] = dp[i + 1][j] + grid[i][j];
                
                else
                    dp[i][j] = min(dp[i + 1][j], dp[i][j + 1]) + grid[i][j];
            }
        }
        
        output = dp[0][0];
        
        return output;
    }
};

// Top Down Approach, Dynamic Programming

class Solution {
private:
    int N, M;
    vector<vector<int>> dp;
    
public:
    int minPathSum(vector<vector<int>>& grid) {
        
        int output = 0;
        this -> N = grid.size();
        this -> M = grid[0].size();
        
        dp.resize(N, vector<int>(M, 0));
        
        output = minPathSum(grid, 0, 0);
        
        return output;
    }
    
private:
    int minPathSum(vector<vector<int>>& grid, int x, int y) {
        
        if (x == N || y == M)
            return INT_MAX;
        
        if (x == N - 1 && y == M - 1)
            return grid[x][y];
        
        if (dp[x][y])
            return dp[x][y];
        
        return dp[x][y] = grid[x][y] + min(minPathSum(grid, x + 1, y), minPathSum(grid, x, y + 1));
    }
};