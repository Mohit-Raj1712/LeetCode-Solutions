class Solution {
public:
    int hammingWeight(uint32_t N) {
        
        int output = 0;
        
        while (N)
        {
            int right_most_setbit = N & -N;
            N -= right_most_setbit;
            
            output ++;
        }
        
        return output;
    }
};