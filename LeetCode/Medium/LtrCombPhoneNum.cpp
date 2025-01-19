class Solution {
public:
    map<char, string> buttons = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"},
    };

    vector<string> ans;

    vector<string> letterCombinations(string digits) {
        solve(0, "", digits);        

        return ans;
    }

    void solve(int curr_index, string curr_str, string digits) {
        if (curr_str.length() == digits.length() && digits.length()){
            ans.push_back(curr_str);
            return;
        }

        string chars = buttons[digits[curr_index]];
        for (int i = 0; i < chars.length(); i++) {
            solve(curr_index + 1, curr_str + chars[i], digits);
        }
    }
};