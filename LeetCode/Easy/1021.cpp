class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        string curr = "";
        stack<char> st;

        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (c == '(')
                st.push(c);
            else
                st.pop();

            if (st.empty()) {
                ans += curr.substr(1);
                curr = "";
            } else
                curr += c;
        }

        return ans;
    }
};