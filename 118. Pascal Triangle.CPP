class Solution {
public:
    vector<vector<int>> generate(int rows) {
        
        vector<vector<int>> pascal_triangle {{1}};

        if (rows == 1)
            return pascal_triangle;

        for (int i = 2; i <= rows; i++)
        {
            vector<int> list;
            list.push_back(1);

            if (i > 2)
            {
                vector<int> previous_row = pascal_triangle.back();
                int N = previous_row.size();
                
                for (int i = 0; i + 1 < N; i++)
                    list.push_back(previous_row[i] + previous_row[i + 1]);
            }

            list.push_back(1);

            pascal_triangle.push_back(list);
        }

        return pascal_triangle;
    }
};