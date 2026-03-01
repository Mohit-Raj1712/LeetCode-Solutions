class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        const int N = nums.size();
        vector<vector<int>> triplets;

        if (N < 3)
            return triplets;
        
        sort(nums.begin(), nums.end());

        for (int i = 0; i < N - 2; i++)
        {
            if (i != 0 && nums[i - 1] == nums[i])
                continue;
            
            int target = 0 - nums[i];
            int left_index = i + 1, right_index = N - 1;

            while (left_index < right_index)
            {
                int sum = nums[left_index] + nums[right_index];

                if (target == sum)
                {
                    triplets.push_back({nums[i], nums[left_index], nums[right_index]});

                    left_index ++;
                    right_index --;

                    while (left_index < right_index && nums[left_index] == nums[left_index - 1])
                        left_index ++;
                    
                    while (left_index < right_index && nums[right_index] == nums[right_index + 1])
                        right_index --;
                }
                else if (target < sum)
                    right_index --;
                
                else
                    left_index ++;
            }
        }

        return triplets;
    }
};