class Solution {
private:
    int n;
    vector<vector<int>> output;
    vector<int> subset;
    
public:
    vector<vector<int>> subsetsWithDup(vector<int>& array) {
        
        this -> n = array.size();
        sort(array.begin(), array.end());
        
        generate_subsets(array, 0);
        return output;
    }
    
private:
    void generate_subsets(vector<int>& array, int index) {
        
        output.push_back(subset);
        
        for (int i = index; i < n; i++)
        {
            subset.push_back(array[i]);
            generate_subsets(array, i + 1);
            subset.pop_back();
            
            while (i + 1 < n && array[i] == array[i + 1])
                i += 1;
        }
    }
};