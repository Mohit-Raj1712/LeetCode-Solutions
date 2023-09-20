class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        int N = digits.size();
        
        for(int i = N - 1; i >= 0; i--)
        {
            if(digits[i] <= 8)
            {
                digits[i] += 1;
                return digits;
            }
            else {
                digits[i] = 0;
            }
        }

        digits.insert(digits.begin(), 1);
        return digits;
    }
};