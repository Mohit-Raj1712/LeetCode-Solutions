class Solution {
private:
    int n;
    vector<int> permutation;
    vector<vector<int>> output;
    
public:
    vector<vector<int>> permute(vector<int>& array) {
        
        this -> n = array.size();
        vector<bool> visited(n);
        
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
            if(visited[i] == false)
            {
                visited[i] = true;
                permutation.push_back(array[i]);
                
                generate_permutations(array, visited);
                
                visited[i] = false;
                permutation.pop_back();
            }
        }
    }
};