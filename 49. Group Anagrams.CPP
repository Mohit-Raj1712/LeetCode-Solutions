class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strings) {
        
        unordered_map<string,vector<string>> map;
        
        for(string &s : strings)
        {
            string t = s;
            sort(t.begin(),t.end());
            map[t].push_back(s);
        }
        
        vector<vector<string>> output;
        
        for(auto itr : map)
            output.push_back(itr.second);
        
        return output;
    }
};