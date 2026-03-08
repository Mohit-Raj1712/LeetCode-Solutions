class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        const int l = s.length();
        int len = 0; // length of longest substring without duplicate characters

        unordered_set<char> lookup;

        int left_index = 0, right_index = 0;

        while (right_index < l)
        {
            char c = s[right_index];

            if (lookup.find(c) == lookup.end())
            {
                lookup.insert(c);
                right_index ++;
                
                len = fmax(len, right_index - left_index);
            }
            else {

                while (s[left_index] != c)
                {
                    lookup.erase(s[left_index]);
                    left_index ++;
                }

                lookup.erase(c);
                left_index ++;
            }
        }

        return len;   
    }
};