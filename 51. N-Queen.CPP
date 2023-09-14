class NQueens {
private:
    int queens;
    vector<vector<char>> board;
    vector<vector<string>> arrangements;
    
public:
    NQueens(int queens) {
        
        this -> queens = queens;
        board.resize(queens, vector<char>(queens, '.'));
        
    }
    
    vector<vector<string>> branch_bound() {
        
        int n = this -> queens;
        vector<bool> columns(n, false);
        vector<bool> primary_diagonal(2*n - 1, false);
        vector<bool> secondary_diagonal(2*n - 1, false);
        
        branch_bound(columns, primary_diagonal, secondary_diagonal, 0);
        
        return arrangements;
    }
    
private:
    void branch_bound(vector<bool>& columns, vector<bool>& primary_diagonal, vector<bool>& secondary_diagonal, int row) {
        
        int n = this -> queens;
        if (row == n)
        {
            vector<string> arrangement;
            
            for (int i = 0; i < n; i++)
            {
                string s;
                for (int j = 0; j < n; j++)
                    s.push_back(board[i][j]);
                
                arrangement.push_back(s);
            }
            
            this -> arrangements.push_back(arrangement);
        }
        
        for (int i = 0; i < n; i++)
        {
            if (!columns[i] && !primary_diagonal[row + i] && !secondary_diagonal[row - i + n - 1])
            {
                columns[i] = primary_diagonal[row + i] = secondary_diagonal[row - i + n - 1] = true;
                board[row][i] = 'Q';
                
                branch_bound(columns, primary_diagonal, secondary_diagonal, row + 1);
                
                columns[i] = primary_diagonal[row + i] = secondary_diagonal[row - i + n - 1] = false;
                board[row][i] = '.';
            }
        }
        
        return;
    }
};

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        
        return (new NQueens(n)) -> branch_bound();
    }
};