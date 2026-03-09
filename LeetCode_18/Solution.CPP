class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        const int N = nums.size();
        vector<vector<int>> quadruplets;

        if (N < 4)
            return quadruplets;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < N - 3; i++)
        {
            if (i != 0 && nums[i] == nums[i - 1])
                continue;
            
            for (int j = i + 1; j < N - 2; j++)
            {
                if (j != i + 1 && nums[j] == nums[j - 1])
                    continue;
                
                long long int new_target = target - (long long int) nums[i] - (long long int) nums[j];
                int left_index = j + 1, right_index = N - 1;

                while (left_index < right_index)
                {
                    long long int sum = (long long int) nums[left_index] + (long long int) nums[right_index];
                    if (sum == new_target)
                    {
                        quadruplets.push_back({ nums[i], nums[j], nums[left_index], nums[right_index] });
                        left_index ++;
                        right_index --;
                        
                        while (left_index < right_index && nums[left_index] == nums[left_index - 1])
                            left_index ++;

                        while (left_index < right_index && nums[right_index] == nums[right_index + 1])
                            right_index --;

                    }
                    else if (sum < new_target)
                        left_index ++;
                    else
                        right_index --;
                }
            }
        }

        return quadruplets;
    }
};