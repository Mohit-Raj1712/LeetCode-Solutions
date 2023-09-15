class Solution {
public:
    int lengthOfLastWord(string s) {
        
        int l = s.length();
        int output = 0, index = l - 1;
        bool flag = false;
        
        while (index >= 0)
        {
            if (s[index] == ' ' && flag)
                return output;
            
            if (s[index] != ' ')
            {
                output += 1;
                flag = true;
            }
            
            index --;
        }
        
        return output;
    }
};