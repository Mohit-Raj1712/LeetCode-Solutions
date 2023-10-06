class Solution {
public:
    string reverseWords(string s) {

        string output;

        int l = s.length();
        int i = 0;

        while(i < l) {

            while(i < l && s[i] == ' ') i ++;

            if(i >= l) break;

            int j = i + 1;

            while(j < l && s[j] != ' ') j ++;

            string substring = s.substr(i, j - i);

            if(output.size() == 0)
                output = substring;
            else
                output = substring + " " + output;

            i = j + 1;
        }

        return output;
    }
};