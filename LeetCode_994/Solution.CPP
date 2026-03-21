vector<vector<int>> directions { { -1, 0}, {1, 0}, {0, 1}, {0, -1} };
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        const int N = grid.size();
        const int M = grid[0].size();

        int fresh_oranges = 0, rotten_oranges = 0, total_oranges = 0;
        queue<pair<int, int>> Queue;

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (grid[i][j] == 2)
                {
                    Queue.push({ i, j });
                    rotten_oranges ++;
                }
                else if (grid[i][j] == 1)
                    fresh_oranges ++;
            }
        }

        total_oranges = fresh_oranges + rotten_oranges;

        if (fresh_oranges == 0)
            return 0;
        
        int min_minutes = 0, oranges = 0;

        while (!Queue.empty())
        {
            int size = Queue.size();

            oranges += size;

            if (oranges == total_oranges)
                return min_minutes;
            
            for (int i = 0; i < size; i++)
            {
                pair<int, int> p = Queue.front(); Queue.pop();
                int x = p.first, y = p.second;

                for (vector<int>& direction : directions)
                {
                    int new_x = x + direction[0];
                    int new_y = y + direction[1];

                    if (new_x < 0 || new_y < 0 || new_x == N || new_y == M)
                        continue;
                    
                    if (grid[new_x][new_y] == 0 || grid[new_x][new_y] == 2)
                        continue;
                    
                    grid[new_x][new_y] = 2;
                    Queue.push({ new_x, new_y });
                }
            }

            min_minutes ++;
        }

        return -1;
    }
};