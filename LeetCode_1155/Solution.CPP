const int MOD = pow(10, 9) + 7;

class Solution {
public:
    vector<vector<int>> dp;

    int numRollsToTarget(int n, int k, int target) {

        this -> dp.resize(n + 1, vector<int>(target + 1, -1));

        return calculate_total_ways(k, n, target) % MOD;
    }

private:
    int calculate_total_ways(int faces, int dice_count, int target) {
        
        if (target < 0)
            return 0;
        
        if (dp[dice_count][target] != -1)
            return dp[dice_count][target];
            
        if (dice_count == 0)
            return target == 0;
        
        int ways = 0;
        
        for (int i = 1; i <= faces; i++)
            ways = (ways + calculate_total_ways(faces, dice_count - 1, target - i) % MOD) % MOD;
    
        return dp[dice_count][target] =  ways;
    }
};