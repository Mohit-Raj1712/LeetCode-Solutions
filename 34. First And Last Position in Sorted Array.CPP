class Solution {
public:
    vector<int> searchRange(vector<int>& array, int target) {
        
        int N = array.size();
        vector<int> output {-1, -1};
        int left_pointer = 0, right_pointer = N - 1;
        
        while (left_pointer <= right_pointer)
        {
            int mid = (left_pointer + right_pointer) / 2;
            
            if (array[mid] == target) 
            {
                right_pointer = mid - 1;
                output[0] = mid;
            }
            
            else if (array[mid] < target)
                left_pointer = mid + 1;
            
            else
                right_pointer = mid - 1;
        }
        
        left_pointer = 0; right_pointer = N - 1;
        
        while (left_pointer <= right_pointer)
        {
            int mid = (left_pointer + right_pointer) / 2;
            
            if (array[mid] == target)
            {
                output[1] = mid;
                left_pointer = mid + 1;
            }
            
            else if (array[mid] < target)
                left_pointer = mid + 1;
            
            else
                right_pointer = mid - 1;
        }
        
        return output;
    }
};