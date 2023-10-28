class Solution {
private:
    int N;
    
public:
    int largestIsland(vector<vector<int>>& grid)  {
        
        this -> N = grid.size();
        
        unordered_map<int, int> map {{0, 0}};
        int grid_id = 2;
        
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (grid[i][j] == 1)
                {
                    int area = assign_area(grid, i, j, grid_id);
                    map[grid_id] = area;
                    grid_id ++;
                }
            }
        }
        
        int output = map[2];
        
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (grid[i][j] == 0)
                {
                    unordered_set<int> set;
                    
                    
                    if (i > 0) set.insert(grid[i - 1][j]);
                    if (j > 0) set.insert(grid[i][j - 1]);
                    if (i < N - 1) set.insert(grid[i + 1][j]);
                    if (j < N - 1) set.insert(grid[i][j + 1]);
                    
                    int total_area = 1;
                    
                    for (int id : set)
                        total_area += map[id];
                
                    output = max(output, total_area);
                }
            }
        }
        
        return output;
    }
    
private:
    int assign_area(vector<vector<int>>& grid, int x, int y, int id) {
        
        if (x < 0 || y < 0 || x >= N || y >= N || grid[x][y] != 1)
            return 0;
        
        grid[x][y] = id;
        
        return 1 + assign_area(grid, x + 1, y, id) + assign_area(grid, x - 1, y, id)
                 + assign_area(grid, x, y + 1, id) + assign_area(grid, x, y - 1, id);
    }
};