class Solution {
public:
    bool isSubsequence(string s, string t) {
        string ans = "";
        int i = 0;
        for (int j = 0; j < t.size(); ++j) {
            if (s[i] == t[j]) {
                ans += s[i];
                ++i;
                if (ans == s) {
                    return true;
                }
            }
        }
        return (ans == s) ? true : false;
    }
};
