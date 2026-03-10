class Solution {
private:
    int N;
    vector<string> combinations;

public:
    vector<string> generateParenthesis(int N) {
        
        this -> N = N;

        generate_combinations(0, 0, "");

        return combinations;    
    }

private:
    void generate_combinations(int open_brackets, int close_brackets, string s) {

        if (open_brackets == close_brackets && close_brackets == N)
        {
            combinations.push_back(s);
            return;
        }

        if (open_brackets < N)
            generate_combinations(open_brackets + 1, close_brackets, s + "(");
        
        if (open_brackets > close_brackets)
            generate_combinations(open_brackets, close_brackets + 1, s + ")");

        return;
    }
};