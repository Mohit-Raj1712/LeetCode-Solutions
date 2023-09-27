class Solution {
private:
    int N, M;
    
public:
    int numIslands(vector<vector<char>>& grid) {
        
        int output = 0;
        this -> N = grid.size();
        this -> M = grid[0].size();
        
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (grid[i][j] == '1')
                {
                    output ++;
                    countIslands(grid, i, j);
                }
            }
        }
        
        return output;
    }
    
private:
    void countIslands(vector<vector<char>>& grid, int x, int y) {
        
        if (x < 0 || y < 0 || x >= N || y >= M)
            return;
        
        if (grid[x][y] == '#' || grid[x][y] == '0')
            return;
        
        grid[x][y] = '#';
        
        countIslands(grid, x + 1, y);
        countIslands(grid, x - 1, y);
        countIslands(grid, x, y - 1);
        countIslands(grid, x, y + 1);
        
        return;
    }
};