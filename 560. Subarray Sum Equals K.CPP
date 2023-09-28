class Solution {
public:
    int subarraySum(vector<int>& array, int k) {
        
        int N = array.size();
        int output = 0, prefix_sum = 0;
        unordered_map<int, int> map {{0, 1}};
        
        for (int i = 0; i < N; i++)
        {
            int val = array[i];
            prefix_sum += val;
            
            if (map.find(prefix_sum - k) != map.end())
                output += map[prefix_sum - k];
            
            map[prefix_sum] ++;
        }
        
        return output;
    }
};