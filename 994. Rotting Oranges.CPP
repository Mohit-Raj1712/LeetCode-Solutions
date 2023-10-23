class Solution {
private:
    vector<vector<int>> directions {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int time = 0;
        int N = grid.size(), M = grid[0].size();
        int rotten_oranges = 0, fresh_oranges = 0;
        queue<pair<int, int>> Queue;
        
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (grid[i][j] == 1)
                {
                    fresh_oranges ++;
                }
                else if (grid[i][j] == 2)
                {
                    rotten_oranges ++;
                    Queue.push({i, j});
                }
            }
        }
        
        if (fresh_oranges == 0)
            return 0;
        
        if (rotten_oranges == 0)
            return -1;
        
        int total_oranges = fresh_oranges + rotten_oranges;
        int oranges = 0;
        
        while (!Queue.empty())
        {
            int size = Queue.size();
            
            oranges += size;
            
            if (oranges == total_oranges)
                return time;
                
            for (int i = 0; i < size; i++)
            {
                pair<int, int> p = Queue.front(); Queue.pop();
                
                int x = p.first;
                int y = p.second;
                
                for (vector<int> direction : directions)
                {
                    int new_x = x + direction[0];
                    int new_y = y + direction[1];
                    
                    if (new_x >= 0 && new_y >= 0 && new_x < N && new_y < M)
                    {
                        if (grid[new_x][new_y] == 1)
                        {
                            grid[new_x][new_y] = 2;
                            Queue.push({new_x, new_y});
                        }
                    }
                }
            }
            
            time ++;
        }
        
        return -1;
    }
};