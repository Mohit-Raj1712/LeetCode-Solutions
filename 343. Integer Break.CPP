// Recursive Memoization Approach

class Solution {
private:
    vector<int> dp;
    int output;
    
public:
    int integerBreak(int N) {
        
        dp.resize(N + 1);
        dp[1] = 1;
        
        output = break_integer(N);
        return output;
    }
    
private:
    int break_integer(int N) {
        
        if (dp[N])
            return dp[N];
        
        int max_product = 1, partition = N / 2;
        
        for (int i = 1; i <= partition; i++)
        {
            int x = i, y = N - i;
            max_product = max(max_product, max(x * y, x * break_integer(y)));
        }
        
        return dp[N] = max_product;
    }
};

// Iterative Tabulation Method

class Solution {
private:
    vector<int> dp;
    int output;
    
public:
    int integerBreak(int N) {
        
        dp.resize(N + 1);
        dp[1] = 1;
        
        for (int i = 2; i <= N; i++)
        {
            if (i < N) dp[i] = i;
            
            int partition = i / 2;
            for (int j = 1; j <= partition; j++)
            {
                int val = dp[j] * dp[i - j];
                dp[i] = max(dp[i], val);
            }
        }
        
        output = dp[N];
        return output;
    }
};