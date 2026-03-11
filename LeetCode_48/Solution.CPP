class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        const int N = matrix.size();
        const int M = matrix[0].size();

        for (int i = 0; i < N; i++)
            for (int j = 0; j < i; j++)
                swap(matrix[i][j], matrix[j][i]);
        
        for (vector<int>& array : matrix)
            reverse(array.begin(), array.end());

        return;
    }
};