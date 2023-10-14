class Solution {
public:
    string convertToTitle(int N) {
        
        string output;
        
        while (N != 0)
        {
            int num = N;
            int remainder = (num - 1) % 26;
            char c = (char) ('A' + remainder);
            output.push_back(c);
            
            N = (N - 1) / 26;
        }
        
        reverse(output.begin(), output.end());
        return output;
    }
};