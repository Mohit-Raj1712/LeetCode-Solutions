class Solution {
private:
    int n;
    
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        
        n = days.size();
        vector<int> dp (n);
        
        return mincostTickets(days, costs, dp, 0);
    }

private:
    int mincostTickets(vector<int>& days, vector<int>& costs, vector<int>& dp, int index) {
        
        if (index >= n)
            return 0;
        
        if (dp[index] > 0)
            return dp[index];
        
        int option1 = costs[0] + mincostTickets(days, costs, dp, index + 1);
        
        int j = index;
        for (; j < n; j++)
            if (days[j] >= days[index] + 7)
                break;
        
        int option2 = costs[1] + mincostTickets(days, costs, dp, j);
        
        j = index;
        for (; j < n; j++)
            if (days[j] >= days[index] + 30)
                break;
        
        int option3 = costs[2] + mincostTickets(days, costs, dp, j);
        
        return dp[index] = fmin(option1, fmin(option2, option3));
    }
};