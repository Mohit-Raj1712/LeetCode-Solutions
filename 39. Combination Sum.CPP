class Solution {
private:
    vector<vector<int>> output;
    vector<int> temp;
    int n;
    
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        this -> n = candidates.size();
        
        combinations(candidates, target, 0);
        return output;
    }
    
private:
    
    void combinations(vector<int>& candidates, int target, int index) {
        
        if (target == 0)
        {
            output.push_back(temp);
            return;
        }
        
        if (target < 0)
            return;
        
        for (int i = index; i < n; i++)
        {
            temp.push_back(candidates[i]);
            combinations(candidates, target - candidates[i], i);
            temp.pop_back();
        }
    }
};