class Solution {
private:
    vector<vector<int>> output;
    vector<int> permutation;
    
    int n;
    
public:
    vector<vector<int>> permuteUnique(vector<int>& array) {
        
        this -> n = array.size();
        vector<bool> visited(n);
        
        sort(array.begin(), array.end());
        
        generate_permutations(array, visited);
        return output;
    }
    
private:
    
    void generate_permutations(vector<int>& array, vector<bool>& visited) {
        
        if (permutation.size() == n)
        {
            output.push_back(permutation);
            return;
        }
        
        for (int i = 0; i < n; i++)
        {
            if (visited[i] == false)
            {
                visited[i] = true;
                permutation.push_back(array[i]);
                
                generate_permutations(array, visited);
                
                permutation.pop_back();
                visited[i] = false;
                
                while (i + 1 < n && array[i] == array[i + 1])
                    i += 1;
            }
        }
    }
};