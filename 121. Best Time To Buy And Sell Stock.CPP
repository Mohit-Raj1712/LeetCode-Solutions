class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        int max_profit = 0;
        int buy = 0;
        
        for (int i = n - 1; i >= 0; i--)
        {
            buy = max(buy, prices[i]);
            max_profit = max(max_profit, buy - prices[i]);
        }
        
        return max_profit;
    }
};