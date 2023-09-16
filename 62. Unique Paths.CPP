// Iterative Approach

class Solution {
public:
    int uniquePaths(int M, int N) {
        
        int output = 0;
        vector<vector<int>> dp (M, vector<int> (N, 0));
        
        for (int i = M - 1; i >= 0; i--)
        {
            for (int j = N - 1; j >= 0; j--)
            {
                if (i == M - 1 && j == N - 1)
                    dp[i][j] = 1;
                
                else if (i == M - 1)
                    dp[i][j] = dp[i][j + 1];
                
                else if (j == N - 1)
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
    vector<vector<int>> dp;
    int M, N;
    
public:
    int uniquePaths(int M, int N) {
        
        this -> M = M;
        this -> N = N;
        dp.resize(M, vector<int>(N, 0));
        
        return total_paths(0, 0);
    }
    
private:
    int total_paths(int row, int column) {
        
        if (row == M || column == N)
            return 0;
        
        if (row == M - 1 && column == N - 1)
            return 1;
        
        if (dp[row][column])
            return dp[row][column];
        
        return dp[row][column] = total_paths(row + 1, column) + total_paths(row, column + 1);
    }
};