class NumArray {
private:
    vector<int> prefix_array;
    
public:
    NumArray(vector<int>& array) {
        
        calculate_prefix_sum(array);
    }
    
    int sumRange(int left, int right) {
        
        int output = prefix_array[right + 1] - prefix_array[left]; 
        return output;
    }
    
private:
    
    void calculate_prefix_sum(vector<int>& array) {
        
        int N = array.size();
        prefix_array.resize(N + 1);
        
        for (int i = 0; i < N; i++)
        {
            if (i == 0)
                prefix_array[i + 1] = array[i];
            else 
                prefix_array[i + 1] = array[i] + prefix_array[i];
            
        }
        
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */