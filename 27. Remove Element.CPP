class Solution {
public:
    int removeElement(vector<int>& array, int val) {
        
        int N = array.size();
        
        if (N == 0)
            return 0;
        
        int j = 0;
        
        for (int i = 0; i < N; i++)
        {
            if (array[i] != val)
            {
                array[j] = array[i];
                j ++;
            }
        }
        
        return j;
    }
};