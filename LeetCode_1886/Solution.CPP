class Solution {
public:
    bool are_matrices_equal(vector<vector<int>>& matrix, vector<vector<int>>& target) {

        const int N = matrix.size();
        const int M = matrix[0].size();

        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                if (matrix[i][j] != target[i][j])
                    return false;
        
        return true;
    }

public:
    bool findRotation(vector<vector<int>>& matrix, vector<vector<int>>& target) {
        
        for (int i = 0; i < 4; i++)
        {
            if (are_matrices_equal(matrix, target))
                return true;

            rotate_matrix(matrix);
        }

        return false;
    }
private:
    void rotate_matrix(vector<vector<int>>& matrix) {

        const int N = matrix.size();
        const int M = matrix[0].size();

        for (int i = 0; i < N; i++)
            for (int j = 0; j < i; j ++)
                swap(matrix[i][j], matrix[j][i]);
        
        for (int i = 0; i < N; i++)
        {
            int left_index = 0, right_index = M - 1;

            while (left_index < right_index)
            {
                swap(matrix[i][left_index], matrix[i][right_index]);
                left_index ++;
                right_index --;
            }
        }

        return;
    }
};