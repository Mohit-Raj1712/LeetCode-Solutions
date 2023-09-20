class Solution {
public:
    string addBinary(string a, string b) {
        
        if(a == "0") return b;
        if(b == "0") return a;
        
        int i = a.length() - 1, j = b.length() - 1;
        int carry = 0;
        
        string output;
        
        while(i >= 0 || j >= 0 || carry != 0)
        {
            int digit1 = i >= 0 ? a[i] - '0' : 0;
            int digit2 = j >= 0 ? b[j] - '0' : 0;
            
            int sum = digit1 + digit2 + carry;
            carry = sum / 2;
            sum  = sum % 2;
            
            output = to_string(sum) + output;
            
            i -= 1;
            j -= 1;
        }
        
        return output;
    }
};