class Solution {
public:
    string getHint(string secret, string guess) {
        
        vector<int> secret_frequency(10);
        vector<int> guess_frequency(10);
        
        int l = secret.length();
        int bulls = 0, cows = 0;
        
        for (int i = 0; i < l; i++)
        {
            if (secret[i] == guess[i])
                bulls ++;
            
            else {
                
                secret_frequency[secret[i] - '0'] ++;
                guess_frequency[guess[i] - '0'] ++;
            }
        }
        
        for (int i = 0; i < 10; i++)
            cows += fmin(secret_frequency[i], guess_frequency[i]);
        
        string output = to_string(bulls) + "A" + to_string(cows) + "B";
        return output;
    }
};