class Solution {
public:
    bool isMonotonic(vector<int>& array) {
        
        int N = array.size();
        
        if (N == 1)
            return true;
        
        bool is_decreasing = false;
        bool is_increasing = false;
        
        for (int i = 1; i < N; i++)
        {
            if (!is_increasing && array[i] > array[i - 1])
                is_increasing = true;
            
            else if (!is_decreasing && array[i] < array[i - 1])
                is_decreasing = true;                    
        }
        
        if (is_decreasing && is_increasing)
            return false;
            
        return true;
    }
};