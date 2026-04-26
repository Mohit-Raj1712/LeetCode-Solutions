class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        const int N = nums.size();
        int subarray_sum = 0;
        int max_subarray_sum = INT_MIN;

        for (int i = 0; i < N; i++)
        {
            int val = nums[i];
            subarray_sum += val;
            subarray_sum = fmax(subarray_sum, val);

            max_subarray_sum = fmax(max_subarray_sum, subarray_sum);
        }

        return max_subarray_sum;
    }
};