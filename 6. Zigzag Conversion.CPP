class Solution {
public:
    string convert(string s, int numRows) {
        
        if (numRows == 1)
            return s;
        
        int l = s.length(), count = 0;
        bool flag = true;
        unordered_map<int, string> map; 
        string output;
        
        for (int i = 0; i < l; i++)
        {
            char c = s[i];
            
            if (count == 0)
                flag = true;
            
            if (count == numRows - 1)
                flag = false;
            
            map[count].push_back(c);
            
            if (flag)
                count += 1;
            
            if (!flag)
                count -= 1;
        }
        
        for (int i = 0; i < numRows; i++)
            output += map[i];
        
        return output;
    }
};