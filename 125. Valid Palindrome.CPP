class Solution {
public:
    bool isPalindrome(string s) {
        
        int l = s.length();
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        
        int left_pointer = 0, right_pointer = l - 1;
        
        while (left_pointer < right_pointer)
        {
            
            while (left_pointer < right_pointer && !isalnum(s[left_pointer])) left_pointer ++;
            while (left_pointer < right_pointer && !isalnum(s[right_pointer])) right_pointer --; 
            
            if (s[left_pointer] != s[right_pointer])
                return false;
            
            left_pointer ++;
            right_pointer --;
        }
        
        return true;
    }
};