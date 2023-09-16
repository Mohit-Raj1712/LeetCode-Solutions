// Iterative Tabulation Approach

class Solution {
private:
    vector<int> dp;
    
public:
    int climbStairs(int N) {
        
        if (N == 1 || N == 2)
            return N;
        
        dp.resize(N + 1);
        dp[1] = 1; dp[2] = 2;
        
        for (int i = 3; i <= N; i++)
            dp[i] = dp[i - 2] + dp[i - 1];
            
        return dp[N];
    }
};

// Recursive Bottom Up Approach

class Solution {
private:
    vector<int> dp;
    
public:
    int climbStairs(int N) {
        
        dp.resize(N + 1);
        return total_ways(N);
    }
    
private:
    int total_ways(int N) {
        
        if (N == 1 || N == 2)
            return N;
        
        if (dp[N])
            return dp[N];
        
        return dp[N] = total_ways(N - 1) + total_ways(N - 2);
    }
};