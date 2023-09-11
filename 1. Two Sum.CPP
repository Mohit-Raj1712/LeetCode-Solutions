class Solution {
public:
    vector<int> twoSum(vector<int>& array, int target) {
        
        int N = array.size();
        vector<int> output {-1, -1};
        unordered_map<int, int> map;
        
        for (int i = 0; i < N; i++)
        {
            int number = array[i];
            int complement_number = target - number;
            
            if (map.find(complement_number) == map.end())
                map[number] = i;
            else {
                
                output[0] = i;
                output[1] = map[complement_number];
                break;
            }
        }
        
        return output;
    }
};