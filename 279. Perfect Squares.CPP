class Solution {
public:
    int numSquares(int n) {
        
        vector<int> dp (n + 1);
        dp[1] = 1;
        
        for(int i = 2; i <= n; i++)
        {
            int min = INT_MAX;
            for(int j = 1; j * j <= i; j++)
            {
                int seen = i - j * j;
                if(dp[seen] < min)
                    min = dp[seen];
            }
            
            dp[i] = min + 1;
        }
        
        return dp[n];
    }
};