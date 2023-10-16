class Solution {
public:
    vector<int> getRow(int rowIndex) {
        
        vector<int> output {1};
        
        long long int val = 1;
        for (int i = 0; i < rowIndex; i++)
        {
            val = (val * (rowIndex - i)) / (i + 1);
            output.push_back((int)val);
        }
        
        return output;
    }
};