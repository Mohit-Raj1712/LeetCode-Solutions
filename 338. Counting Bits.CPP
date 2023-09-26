class Solution {
public:
    vector<int> countBits(int N) {
        
        vector<int> dp(N + 1);
        
        for (int i = 1; i <= N; i++)
            dp[i] = i % 2 == 0 ? dp[i / 2] : dp[i / 2] + 1;
        
        return dp;
    }
};