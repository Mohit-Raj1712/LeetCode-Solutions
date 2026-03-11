class Solution {
public:
    int mySqrt(int x) {
        
        int output = -1;
        int left_pointer = 0, right_pointer = x;
        
        while (left_pointer <= right_pointer)
        {
            long long int mid = left_pointer + (right_pointer - left_pointer) / 2;
            
            if ((long long int) mid * mid == x)
            {
                output = mid;
                break;
            }
            
            else if ((long long int) mid * mid < x)
            {
                output = mid;
                left_pointer = mid + 1;
            }
            
            else {
                
                right_pointer = mid - 1; 
            }
        }
        
        return output;
    }
};