class Solution {
public:
    string removeDuplicateLetters(string s) {
        
        string output;
        
        vector<int> frequency(26);
        vector<bool> isExist(26, false);
        stack<char> Stack;
        
        for (char c : s)
            frequency[c - 'a'] ++;
        
        for (char c : s)
        {
            frequency[c - 'a'] --;
            
            if (isExist[c - 'a'])
                continue;
            
            while (!Stack.empty() && frequency[Stack.top() - 'a'] > 0 && Stack.top() > c)
            {
                isExist[Stack.top() - 'a'] = false;
                Stack.pop();
            }
            
            Stack.push(c);
            isExist[c - 'a'] = true;
        }
        
        while (!Stack.empty())
        {
            char c = Stack.top(); Stack.pop();
            output.push_back(c);
        }
        
        reverse(output.begin(), output.end());
        
        return output;
    }
};