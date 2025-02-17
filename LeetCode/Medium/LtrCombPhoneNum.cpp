class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty())
            return {};
        vector<string> ans;
        solve(digits, digits, "", ans);
        return ans;
    }

private:
    unordered_map<char, string> mp = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"},
    };

    void solve(string digits, string curr_digits, string curr, vector<string> &ans) {
        if (digits.size() == curr.size()) {
            ans.push_back(curr);
            return;
        }
        for (auto &c : mp[curr_digits[0]]) {
            string temp_digits = curr_digits;
            temp_digits.erase(0, 1);
            solve(digits, temp_digits, curr + c, ans);
        }
    }
};