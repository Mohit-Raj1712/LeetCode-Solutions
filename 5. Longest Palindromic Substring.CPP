class Solution {
public:
    string longestPalindrome(string s) {
        
        int l = s.length();
        int start_index = -1, end_index = -1, palindrome_length = 0;
        vector<vector<bool>> dp (l, vector<bool>(l, false));
        
        for (int diagonal = 0; diagonal < l; diagonal ++)
        {
            for (int i = 0, j = diagonal; j < l; i++, j++)
            {
                if (diagonal == 0)
                    dp[i][j] = true;
                
                else if (diagonal == 1)
                    dp[i][j] = s[i] == s[j] ? true : false;
                
                else
                    dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]) ? true : false;
                
                
                if (dp[i][j] && j - i + 1 > palindrome_length)
                {
                    start_index = i;
                    end_index = j + 1;
                    palindrome_length = j - i + 1;
                }
            }
        }
        
        string output = s.substr(start_index, end_index - start_index);
        return output;
    }
};