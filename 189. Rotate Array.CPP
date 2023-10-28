class Solution {
public:
    void rotate(vector<int>& array, int k) {
        
        int N = array.size();
        int left_pointer = 0, right_pointer = N;
        
        k = k % N;
        
        rotate_array(array, left_pointer, right_pointer - 1);
        rotate_array(array, left_pointer, k - 1);
        rotate_array(array, k, right_pointer - 1);
        
        return;
    }
    
private:
    void rotate_array(vector<int>& array, int i, int j) {
        
        int left_pointer = i, right_pointer = j;
        
        while (left_pointer < right_pointer)
        {
            swap(array[left_pointer], array[right_pointer]);
            
            left_pointer ++;
            right_pointer --;
        }
        
        return;
    }
};