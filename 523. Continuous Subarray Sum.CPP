class Solution {
public:
    bool checkSubarraySum(vector<int>& array, int k) {
        
        int N = array.size(), prefix_sum = 0;
        unordered_map<int, int> map {{0, -1}};
        
        for (int i = 0; i < N; i++)
        {
            int val = array[i];
            prefix_sum += val;
            
            int remainder = prefix_sum % k;
            
            if (map.find(remainder) != map.end())
            {
                if (i - map[remainder] >= 2)
                    return true;
            }
            else
                    map[remainder] = i;
        }
        
        return false;
    }
};