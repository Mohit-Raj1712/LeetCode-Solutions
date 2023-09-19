class Solution {
public:
    int findDuplicate(vector<int>& array) {
        
        int N = array.size();
        vector<bool> visited(N, false);
        
        for (int i = 0; i < N; i++)
        {
            int index = array[i] - 1;
            
            if (visited[index])
                return array[i];
            
            visited[index] = true;
        }
        
        return -1;
    }
};