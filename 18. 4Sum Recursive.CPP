class Solution {
private:
    int N;
    vector<int> subset;
    vector<vector<int>> output;
    
public:
    vector<vector<int>> fourSum(vector<int>& array, int target, int k = 4) {
        
        this -> N = array.size();
        
        if (N < k)
            return output;
        
        sort(array.begin(), array.end());
        ksum(array, 0, k, target);
        
        return output;
    }
    
private:
    void ksum(vector<int>& array, int index, int k, long long int target) {
        
        if (k == 2)
        {
            int left_pointer = index, right_pointer = N - 1;
            
            while (left_pointer < right_pointer)
            {
                long long int sum = array[left_pointer] + array[right_pointer];
                
                if (sum == (long long int)target)
                {
                    subset.push_back(array[left_pointer]);
                    subset.push_back(array[right_pointer]);
                    
                    output.push_back(subset);
                    
                    subset.pop_back();
                    subset.pop_back();
                    
                    left_pointer ++;
                    right_pointer --;
                    
                    while (left_pointer < right_pointer && array[left_pointer] == array[left_pointer - 1])
                        left_pointer ++;
                    
                    while (left_pointer < right_pointer && array[right_pointer] == array[right_pointer + 1])
                        right_pointer --;
                }
                
                else if (sum < target)
                    left_pointer ++;
                
                else
                    right_pointer --;
            }
            
            return;
        }
        
        for (int i = index; i < N - k + 1; i++)
        {
            if (i == index || array[i] != array[i - 1])
            {
                subset.push_back(array[i]);
                ksum(array, i + 1, k - 1, target - array[i]);
                subset.pop_back();       
            }
        }
        
        return;
    }
};