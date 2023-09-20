class Solution {
private:
    vector<vector<int>> output;
    vector<int> combination;
    int N;
    
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        this -> N = candidates.size();
        sort(candidates.begin(), candidates.end());
        
        generate_combinations(candidates, target, 0);
        
        return output;
    }
    
private:
    void generate_combinations(vector<int>& candidates, int target, int index) {
        
        if (target < 0)
            return;
        
        if (target == 0)
        {
            output.push_back(combination);
            return;
        }
        
        for (int i = index; i < N; i++)
        {
            combination.push_back(candidates[i]);
            generate_combinations(candidates, target - candidates[i], i + 1);
            combination.pop_back();
            
            while (i + 1 < N && candidates[i] == candidates[i + 1])
                i ++;
        }
    }
};