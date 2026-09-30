class Solution {
    vector<string> allowed;
    unordered_map<string, vector<char>> mp;
    void getAllRows(string bottom, string curr, vector<string>& rows) {
        if (curr.size() == bottom.size() - 1) {
            rows.push_back(curr);
            return;
        }
        int index = curr.size();
        string base;
        base.push_back(bottom[index]);
        base.push_back(bottom[index + 1]);
        for (char& option : mp[base]) {
            curr += option;
            getAllRows(bottom, curr, rows);
            curr.pop_back();
        }
    }
    bool dfs(string row, unordered_map<string, bool>& memo) {
        if (row.size() == 1) return true;
        if (memo.count(row)) return memo[row];
        vector<string> nextRows;
        getAllRows(row, "", nextRows);
        for (string& nextRow : nextRows) {
            if (dfs(nextRow, memo)) {
                memo[row] = true;
                return true;
            }
        }
        memo[row] = false;
        return false;
    }
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        this->allowed = allowed;
        for (string& s : allowed) {
            mp[s.substr(0, 2)].push_back(s[2]);
        }
        
        unordered_map<string, bool> memo;
        return dfs(bottom, memo);
    }
};