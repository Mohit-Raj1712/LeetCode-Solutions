class Solution {
public:
    string addBinary(string a, string b) {
        
        if (a == "0" && b == "0")
            return "0";
        
        if (a == "0") return b;

        if (b == "0") return a;

        string sum;
        int l = a.length(), m = b.length();
        int i = l - 1, j = m - 1, carry = 0;

        while (i >= 0 || j >= 0 || carry)
        {
            int bit1 = i >= 0 ? a[i] - '0' : 0;
            int bit2 = j >= 0 ? b[j] - '0' : 0;

            int bit = bit1 + bit2 + carry;
            carry = bit / 2;

            sum.push_back((char)('0' + (bit % 2) ));

            i --;
            j --;
        }

        reverse(sum.begin(), sum.end());

        return sum;
    }
};