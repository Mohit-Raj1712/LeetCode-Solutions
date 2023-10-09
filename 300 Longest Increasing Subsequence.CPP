class Solution {
public:
    int lengthOfLIS(vector<int>& array) {
        
        int N = array.size(), output = 1;
        vector<int> dp(N);

        for (int i = 0; i < N; i++)
        {
            int key = array[i];
            int x = 0; 
            for (int j = 0; j < i; j ++)
                if (array[j] < key)
                    x = fmax(x, dp[j]);
                    
            dp[i] = x + 1;
            output = fmax(output, dp[i]);
        }

        return output;
    }
};