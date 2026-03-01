class Solution {
public:
    int minPartitions(string s) {
        
        char max_char = *max_element(s.begin(), s.end());

        return max_char - '0';
    }
};