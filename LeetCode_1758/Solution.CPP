class Solution {
public:
    int minOperations(string s) {
        
        const int l = s.length();
        if (l == 1)
            return 0;

        int min_operations = l;
        int operation1 = 0, operation2 = 0;

        for (int i = 0; i < l; i++)
        {
            char zero = (i % 2 == 0) ? '0' : '1';
            char one  = (i % 2 == 0) ? '1' : '0';

            if (s[i] != zero)
                operation1 ++;

            if (s[i] != one)
                operation2 ++;   
        }

        min_operations = fmin(operation1, operation2);

        return min_operations;
    }
};