class Solution {
private:
    int MOD = 1e9 + 7;
public:
    int numSubseq(vector<int>& array, int target) {
        
        int n = array.size();
        vector<int> expression(n); expression[0] = 1;
        
        for (int i = 1; i < n; i++)
            expression[i] = (2 * expression[i - 1]) % MOD;
        
        sort(array.begin(), array.end());
        
        int i = 0, j = n - 1, count = 0;
        
        while (i <= j)
        {
            if (array[i] + array[j] > target)
                j --;
            else
                count = (count + expression[j - i++]) % MOD;
        }
        
        return count;
    }
};