class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        int l = s.length(), m = t.length();
        
        if (l > m)
            return false;
        
        int i = 0, j = -1;

        while (i < l && ++j < m)
            if (s[i] == t[j])
                i ++;
  
        
        return i == l;
    }
};