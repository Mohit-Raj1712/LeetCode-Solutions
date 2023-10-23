class Solution {
public:
    int numTrees(int n) {
        
        if (n == 1 || n == 2)
            return n;

        vector<int> dp (n + 1);
        dp[0] = dp[1] = 1;

        for (int i = 2; i <= n; i++)
        {
            int possible_arrangements = 0;
            int left_pointer = 0, right_pointer = i - 1;

            while (left_pointer <= i - 1 && right_pointer >= 0) 
            {
                possible_arrangements += dp[left_pointer] * dp[right_pointer];
                left_pointer += 1;
                right_pointer -= 1;
            }

            dp[i] = possible_arrangements;
        }
        
        return dp[n];
    }
};