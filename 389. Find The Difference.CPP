class Solution {
public:
    char findTheDifference(string s, string t) {
        
        s = s + t;
        
        char c = s[0];
        int l = s.length();
        
        for (int i = 1; i < l; i++)
            c ^= s[i];
        
        
        return c;
    }
};