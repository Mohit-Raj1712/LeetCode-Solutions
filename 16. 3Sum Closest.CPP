class Solution {
public:
    int threeSumClosest(vector<int>& array, int target) {
        
        int N = array.size();
        int output = array[0] + array[1] + array[2];
        
        sort(array.begin(), array.end());
        
        for (int i = 0; i < N - 2; i++)
        {
            int left_pointer = i + 1;
            int right_pointer = N - 1;
            
            while (left_pointer < right_pointer)
            {
                int sum = array[i] + array[left_pointer] + array[right_pointer];
                
                if (sum == target)
                    return output = sum;
                
                if (sum > target)
                    right_pointer --;
                else
                    left_pointer ++;
                
                if (abs(output - target) > abs(sum - target))
                    output = sum;
            }
        }
        
        return output;
    }
};