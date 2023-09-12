class Solution {
public:
    bool isValid(string s) {
        
        int l = s.length();
        
        if (l % 2 == 1)
            return false;
    
        stack<char> Stack;
        
        for (int i = 0; i < l; i++)
        {
            char c = s[i];
            
            if (Stack.empty() || (c == '(' || c == '{' || c == '['))
                Stack.push(c);
            
            else {
                
                if (c == '}' && Stack.top() == '{')
                    Stack.pop();
                
                else if (c == ')' && Stack.top() == '(')
                    Stack.pop();
                
                else if (c == ']' && Stack.top() == '[')
                    Stack.pop();
                
                else
                    return false;
            }
        }
        
        return Stack.empty();
    }
};