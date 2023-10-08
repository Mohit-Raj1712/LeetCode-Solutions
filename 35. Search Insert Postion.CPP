class Solution {
public:
    int searchInsert(vector<int>& array, int target) {
        
        int N = array.size();
        int left_pointer = 0, right_pointer = N - 1;
        
        while (left_pointer <= right_pointer)
        {
            int mid = left_pointer + (right_pointer - left_pointer) / 2;
            
            if (array[mid] == target)
                return mid;
            
            if (array[mid] < target)
                left_pointer = mid + 1;
            else
                right_pointer = mid - 1;
        }
        
        return left_pointer;
    }
};