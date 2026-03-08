class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {

        const int N = nums.size();        
        vector<vector<int>> power_set;

        int total_subsets = (int) pow(2, N);

        for (int i = 0; i < total_subsets; i++)
        {
            vector<int> subset;

            for (int j = 0; j < N; j++)
            {
                if ((1 << j) & i)
                    subset.push_back(nums[j]);
            }

            power_set.push_back(subset);
        }

        return power_set;
    }
};