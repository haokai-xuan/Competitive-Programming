class Solution {
    vector<vector<int>> memo;
    string s;
    bool solve(int i, int open) {
        if (i == s.size()) return open == 0;
        
        if (memo[i][open] != -1) return memo[i][open];

        bool ans = false;

        if (s[i] == '(') {
            ans = solve(i + 1, open + 1);
        }
        else if (s[i] == ')') {
            if (open > 0) ans = solve(i + 1, open - 1);
        }
        else {
            ans = solve(i + 1, open) || solve(i + 1, open + 1);
            if (open > 0) ans |= solve(i + 1, open - 1);
        }

        return memo[i][open] = ans;
    }
public:
    bool checkValidString(string s) {
        this->s = s;
        memo.resize(101, vector<int>(101, -1));

        return solve(0, 0);
    }
};