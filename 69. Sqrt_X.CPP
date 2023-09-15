class Solution {
public:
    int mySqrt(int N) {
        
        if (N == 0 || N == 1)
            return N;
        
        long long int output = 0;
        long long int left_pointer = 0;
        long long int right_pointer = N;
        
        while (left_pointer <= right_pointer)
        {
            long long int mid = left_pointer + (right_pointer - left_pointer) / 2;
            
            if (mid * mid == N)
                return output = (int)mid;
            
            if (mid * mid < N)
            {
                output = mid;
                left_pointer = mid + 1;
            }
            else {
                
                right_pointer = mid - 1;
            }
        }
    
        return (int)output;
    }
};