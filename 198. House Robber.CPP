// Recursive Approach
class Solution {
private:
    int N;
    vector<int> dp;
    
public:
    int rob(vector<int>& array) {
        
        this -> N = array.size();
        dp.resize(N, -1);
        
        return house_robber(array, 0);
    }
    
private:
    int house_robber(vector<int>& array, int index) {
        
        if (index >= N)
            return 0;
        
        if (dp[index] != -1)
            return dp[index];
        
        int steal = array[index] + house_robber(array, index + 2);
        int skip  = house_robber(array, index + 1);
        
        return dp[index] = max(steal, skip);
    }
};

// Iterative Approach

class Solution {
private:
    vector<int> dp;
    
public:
    int rob(vector<int>& array) {
        
        int N = array.size();
        dp.resize(N, -1);
        
        for (int i = 0; i < N; i++)
        {
            if (i == 0)
                dp[i] = array[0];
            
            else if (i == 1)
                dp[i] = max(array[0], array[1]);
            
            else
                dp[i] = max(dp[i - 2] + array[i], dp[i - 1]);
        }
        
        return dp[N - 1];
    }
};