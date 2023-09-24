class Solution {
public:
    int search(vector<int>& array, int target) {
        
        int output = -1;
        int N = array.size();
        int left_pointer = 0, right_pointer = N - 1;
        
        while (left_pointer <= right_pointer)
        {
            int mid = left_pointer + (right_pointer - left_pointer) / 2;
            
            if (array[mid] == target)
            {
                output = mid;
                break;
            }
            
            if (array[left_pointer] <= array[mid])
            {
                if (array[left_pointer] <= target && target < array[mid])
                    right_pointer = mid - 1;
                else
                    left_pointer = mid + 1;
            }
            else {
                
                if (array[mid] < target && target <= array[right_pointer])
                    left_pointer = mid + 1;
                else
                    right_pointer = mid - 1;
            }
        }
        
        return output;
    }
};