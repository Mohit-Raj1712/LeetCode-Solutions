class Solution {
public:
    int findMaxLength(vector<int>& array) {
        
        int output = 0;
        int N = array.size(), count = 0;
        unordered_map<int, int> map {{0, -1}};
        
        for (int i = 0; i < N; i++)
        {
            int val = array[i];
            
            val == 0 ? count -- : count ++;
            
            if (map.find(count) != map.end())
                output = fmax(output, i - map[count]);
            else
                map[count] = i;
        }
        
        return output;
    }
};