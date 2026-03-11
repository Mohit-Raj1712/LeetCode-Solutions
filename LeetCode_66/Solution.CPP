class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        const int N = digits.size();
        int index = N - 1;

        while (index >= 0)
        {
            if (digits[index] < 9)
            {
                digits[index] ++;
                return digits;
            }

            digits[index] = 0;
            index --;
        }

        digits.resize(N + 1);
        digits[0] = 1;

        return digits;
    }
};