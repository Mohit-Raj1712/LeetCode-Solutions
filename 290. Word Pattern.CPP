class Solution {
public:
    bool wordPattern(string pattern, string s) {
        
        int l = pattern.length();
        int number_of_spaces = count(s.begin(), s.end(), ' ');
        int number_of_words = number_of_spaces + 1;

        if(pattern.length() != number_of_words)
            return false;

        vector<string> words;
        int i = 0, j = 0;

        s.push_back(' ');

        for(int index = 0; i < s.length(); index ++)
        {
            if(s[index] == ' ')
            {
                j = index;
                words.push_back(s.substr(i, j - i));

                i = index + 1;
            }
        }


        unordered_map<char, string> map;
        unordered_set<string> set;

        for(i = 0; i < l; i++)
        {
            char c = pattern[i];
            if(map.find(c) == map.end()) // character not in Map
            {
                if(set.find(words[i]) != set.end())
                    return false;

                map[c] = words[i];
                set.insert(words[i]);
            }
            else {
                if(map[c] != words[i])
                    return false;
            }
        }

        return true;
    }

};