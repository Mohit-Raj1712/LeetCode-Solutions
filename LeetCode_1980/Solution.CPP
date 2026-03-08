class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        
        const int N = nums.size();
        unordered_set<string> lookup (nums.begin(), nums.end());
        
        int total_binary_substrings = (int) pow(2, N);

        for (int i = 0; i < total_binary_substrings; i++)
        {
            string binary_string;

            for (int j = 0; j < N; j++)
                binary_string.push_back((1 << j) & i ? '1' : '0');

            if (lookup.find(binary_string) == lookup.end())
                return binary_string;
        }

        return "-1";
    }
};