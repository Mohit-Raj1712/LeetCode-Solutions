class Solution {
public:
    bool isPerfectSquare(int N) {
        
        long long int left_pointer = 1;
        long long int right_pointer = N;
        
        while (left_pointer <= right_pointer)
        {
            long long int mid = left_pointer + (right_pointer - left_pointer) / 2;
            
            if (mid * mid == (long long int)N)
                return true;
            
            else if (mid * mid < (long long int)N)
                left_pointer = mid + 1;
            
            else
                right_pointer = mid - 1;
        }
        
        return false;
    }
};