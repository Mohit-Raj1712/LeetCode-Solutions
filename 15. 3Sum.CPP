class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& array) {
        
        int N = array.size();
        vector<vector<int>> output;
        
        if (N < 3)
            return output;
        
        sort(array.begin(), array.end());
        
        for (int i = 0; i < N - 2; i++)
        {
            if (i != 0 && (array[i] == array[i - 1]))
                continue;
            
            int left_pointer = i + 1, right_pointer = N - 1;
            int target = 0 - array[i];
            
            while (left_pointer < right_pointer)
            {
                if (array[left_pointer] + array[right_pointer] == target)
                {
                    output.push_back({ array[i], array[left_pointer], array[right_pointer ]});
                    
                    left_pointer ++;
                    right_pointer --;
                    
                    while (left_pointer < right_pointer && array[left_pointer] == array[left_pointer - 1])
                        left_pointer ++;
                    
                    while (left_pointer < right_pointer && array[right_pointer] == array[right_pointer + 1])
                        right_pointer --;
                }
                
                else if (array[left_pointer] + array[right_pointer] < target)
                    left_pointer ++;
                
                else
                    right_pointer --;
            }
        }
        
        return output;
    }
};