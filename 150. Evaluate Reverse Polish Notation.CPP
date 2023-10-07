class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
        int output;
        stack<long long int> Stack;
        
        for (string token : tokens)
        {
            if(token == "+")
            {
                long long int operand1 = Stack.top(); Stack.pop();
                long long int operand2 = Stack.top(); Stack.pop();
                Stack.push(operand1 + operand2);
            }
            else if(token == "-")
            {
                long long int operand1 = Stack.top(); Stack.pop();
                long long int operand2 = Stack.top(); Stack.pop();
                Stack.push(operand2 - operand1);
            }
            else if(token == "*")
            {
                long long int operand1 = Stack.top(); Stack.pop();
                long long int operand2 = Stack.top(); Stack.pop();
                Stack.push(operand1 * operand2);
            }
            else if(token == "/")
            {
                long long int operand1 = Stack.top(); Stack.pop();
                long long int operand2 = Stack.top(); Stack.pop();
                Stack.push(operand2 / operand1) ;
            }
            else {
                Stack.push(stoi(token));
            }
            
        }
        
        output = (int)Stack.top(); Stack.pop();
        return output;
    }
};