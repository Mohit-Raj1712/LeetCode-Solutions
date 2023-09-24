// Iterative Approach

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        
        int output = 0;
        int N = grid.size(), M = grid[0].size();
        
        vector<vector<long long int>> dp(N, vector<long long int>(M, 0));
        
        if (grid[N - 1][M - 1] == 1)
            return output;
        
        for (int i = N - 1; i >= 0; i--)
        {
            for (int j = M - 1; j >= 0; j--)
            {
                if (grid[i][j] == 1)
                    dp[i][j] = 0;
                
                else if (i == N - 1 && j == M - 1)
                    dp[i][j] = 1;
                
                else if (i == N - 1)
                    dp[i][j] = dp[i][j + 1];
                
                else if (j == M - 1)
                    dp[i][j] = dp[i + 1][j];
                
                else
                    dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
            }
        }
        
        output = dp[0][0];
        
        return output;
    }
};

// Recursive Approach

class Solution {
private:
    vector<vector<long long int>> dp;
    long long int N, M, output;
    
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        
        this -> output = 0;
        this -> N = grid.size();
        this -> M = grid[0].size();
        dp.resize(N, vector<long long int>(M, 0));
        
        if (grid[N - 1][M - 1] == 1)
            return output;
        
        output = uniquePaths(grid, 0, 0);
        
        return (int)output;
    }
    
private:
    int uniquePaths(vector<vector<int>>& grid, int x, int y) {
        
        if (x == N || y == M)
            return 0;
        
        if (x == N - 1 && y == M - 1)
            return 1;
        
        if (grid[x][y] == 1)
            return 0;

        if (dp[x][y])
            return dp[x][y];
        
        return dp[x][y] = uniquePaths(grid, x + 1, y) + uniquePaths(grid, x, y + 1);
    }
};