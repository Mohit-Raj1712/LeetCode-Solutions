class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        unordered_set<char> set;
        int l = s.length();
        
        if(l == 1) 
            return l;

        int left_Pointer = 0;
        int right_Pointer = 0;
        int output = 0;

        while(right_Pointer < l)
        {
            char c = s[right_Pointer];

            if(set.find(c) == set.end()) // Not present in set
            {
                set.insert(c);
                right_Pointer += 1;

                output = max(output, right_Pointer - left_Pointer);
            }
            else {


                while(s[left_Pointer] != c)
                {
                    set.erase(s[left_Pointer]);
                    left_Pointer += 1;
                }

                set.erase(c);
                left_Pointer += 1;
            }
        }

        return output;
    }
};
