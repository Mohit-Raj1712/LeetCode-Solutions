class Solution {
public:
    int maxSubArray(vector<int>& array) {

        // Kadane's Algorithm
        
        int N = array.size();
        int output = array[0];
        int subarray_sum = array[0];
        
        for (int i = 1; i < N; i++)
        {
            subarray_sum += array[i];
            subarray_sum = max(subarray_sum, array[i]);
            output = max(output, subarray_sum);
        }
        
        return output;
    }
};