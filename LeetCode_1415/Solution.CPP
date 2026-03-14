class Solution {
    string res;
    int count;

public:
    string getHappyString(int n, int k) {
        count = 0;
        res = "";
        string cur = "";
        backtrack(n, k, cur);
        return res;
    }

    bool backtrack(int n, int k, string& cur) {
        if (cur.length() == n) {
            count++;
            if (count == k) {
                res = cur;
                return true;
            }
            return false;
        }

        for (char ch = 'a'; ch <= 'c'; ch++) {
            if (!cur.empty() && cur.back() == ch) continue;

            cur.push_back(ch);
            if (backtrack(n, k, cur)) {
                return true;
            }
            cur.pop_back();
        }
        return false;
    }
};