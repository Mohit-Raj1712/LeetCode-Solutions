class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        
        const int N = grid.size();
        const int M = grid[0].size();

        vector<vector<int>> output(N - k + 1, vector<int>(M - k + 1));

        for (int i = 0; i < N - k + 1; i++)
        {
            for (int j = 0; j < M - k + 1; j++)
            {

                vector<int> nums;
                for (int r = i; r < i + k; r ++)
                    for (int c = j; c < j + k; c ++)
                        nums.push_back(grid[r][c]);
                
                int min_abs_diff = INT_MAX;
                sort(nums.begin(), nums.end());

                for (int index = 0; index < nums.size() - 1; index ++)
                    if (nums[index] != nums[index + 1] && fabs( nums[index] - nums[index + 1] ) < min_abs_diff )
                        min_abs_diff = fabs ( nums[index] - nums[index + 1] );
                
                output[i][j] = min_abs_diff == INT_MAX ? 0 : min_abs_diff;
            }
        }

        return output;
    }
};