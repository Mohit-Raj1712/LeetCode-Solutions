class Solution {
private:
    int l;
    string combination;
    vector<string> output;
    unordered_map<char, string> dictionary =  {
        
        { '2', "abc" },
        { '3', "def" },
        { '4', "ghi" },
        { '5', "jkl" },
        { '6', "mno" },
        { '7', "pqrs"},
        { '8', "tuv" },
        { '9', "wxyz"}
    };
    
public:
    vector<string> letterCombinations(string digits) {
        
        this -> l = digits.length();
        
        if (l == 0)
            return output;
        
        letterCombinations(digits, 0);
        
        return output;
    }
    
private:
    void letterCombinations(string digits, int index) {
        
        if (combination.length() == l)
        {
            output.push_back(combination);
            return;
        }
        
        if (index > l)
            return;
        
        for (int i = index; i < l; i++)
        {
            char c = digits[i];
            string s = dictionary[c];
            int n = s.length();
            
            for (int j = 0; j < n; j++)
            {
                combination.push_back(s[j]);
                letterCombinations(digits, i + 1);
                combination.pop_back();
            }
        }
    }
};