class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& array) {
        
        int N = array.size();
        int left_pointer = 0, right_pointer = N - 1;
        
        while (left_pointer < right_pointer)
        {
            while (left_pointer < right_pointer && array[right_pointer] % 2 == 1)
                right_pointer --;
            
            while (left_pointer < right_pointer && array[left_pointer] % 2 == 0)
                left_pointer ++;
            
            swap(array[left_pointer], array[right_pointer]);
            
            left_pointer ++;
            right_pointer --;
        }
        
        return array;
    }
};