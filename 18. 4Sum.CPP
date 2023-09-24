class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& array, int target) {
        
        vector<vector<int>> output;
        int N = array.size();
        
        if (N < 4)
            return output;
        
        sort(array.begin(), array.end());
        
        for (int i = 0; i < N - 3; i ++)
        {
            if (i == 0 || array[i] != array[i - 1])
            {
                for (int j = i + 1; j < N - 2; j++)
                {
                    
                    if (j == i + 1 || array[j] != array[j - 1])
                    {
                        long long int a = array[i], b = array[j];
                        long long int new_target = target - (a + b);
                        
                        int left_pointer = j + 1, right_pointer = N - 1;
                        
                        while (left_pointer < right_pointer)
                        {
                            long long int c = array[left_pointer];
                            long long int d = array[right_pointer];
                            long long int sum = c + d;
                            
                            if (sum == new_target)
                            {
                                vector<int> fourlet = {array[i], array[j], array[left_pointer], array[right_pointer]};
                                output.push_back(fourlet);
                                
                                left_pointer ++;
                                right_pointer --;
                                
                                
                                while (left_pointer < right_pointer && array[left_pointer] == array[left_pointer - 1])
                                    left_pointer ++;
                                
                                while (left_pointer < right_pointer && array[right_pointer] == array[right_pointer + 1])
                                    right_pointer --;
                            }
                            
                            else if (sum < new_target)
                                left_pointer ++;
                            
                            else
                                right_pointer --;
                        }
                    }
                }
            }
        }
        
        return output;
    }
};