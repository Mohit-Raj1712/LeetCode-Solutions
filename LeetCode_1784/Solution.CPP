class Solution {
public:
    bool checkOnesSegment(string s) {
        
        const int l = s.length();
        int consecutive_ones = 0, count = 0;

        for (int i = 0; i < l; i++)
        {
            if (s[i] == '1')
                consecutive_ones ++;
            else {
                
                if (consecutive_ones > 0)
                    count ++;
                
                consecutive_ones = 0;

                if (count > 1)
                    return false;
            }
        }

        if (consecutive_ones > 0)
            count ++;

        return count == 1;
    }
};