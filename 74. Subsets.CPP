// Method 1: Recursive Method : Backtracking

class Solution {
private:
    vector<vector<int>> output;
    vector<int> subset;
    int N;
    
public:
    vector<vector<int>> subsets(vector<int>& array) {
        
        this -> N = array.size();
        subsets(array, 0);
        
        return output;
    }
    
private:
    void subsets(vector<int>& array, int index) {
        
        output.push_back(subset);
        
        for (int i = index; i < N; i++)
        {
            subset.push_back(array[i]);
            subsets(array, i + 1);
            subset.pop_back();
        }
    }
};

// Method 2 Iterative Approach : Bit Manipulation

class Solution {
private:
    int N;
    vector<vector<int>> output;
    
public:
    vector<vector<int>> subsets(vector<int>& array) {
        
        this -> N = array.size();
        int total_subsets = (int) pow(2, N);
        
        for (int i = 0; i < total_subsets; i++)
        {
            vector<int> subset;
            for (int j = 0; j < N; j++)
                if ((1 << j) & i)
                    subset.push_back(array[j]);
            
            output.push_back(subset);
        }
        
        return output;
    }
};

// Method 3 : Step by Step Combination Generation

class Solution {
private:
    int N;
    vector<vector<int>> output;
    
public:
    vector<vector<int>> subsets(vector<int>& array) {
        
        this -> N = array.size();
        output.push_back({});
        
        for (int i = 0; i < N; i++)
        {
            int val = array[i];
            int size = output.size();
            for (int j = 0; j < size; j++)
            {
                vector<int> subset = output[j];
                subset.push_back(val);
                output.push_back(subset);
            }
        }
        
        return output;
    }
};
