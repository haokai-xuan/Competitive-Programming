class Solution {
public:
    string clearDigits(string s) {
        string ans = "";

        for (int i = 0; i < s.size(); i++) {
            if (isdigit(s[i]) && i != 0) {
                ans.pop_back();
            }
            else {
                ans.push_back(s[i]);
            }
        }

        return ans;
    }
};