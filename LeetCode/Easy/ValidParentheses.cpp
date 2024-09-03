class Solution {
public:
    bool isValid(string s) {
        if (s.size() % 2) {
            return false;
        }
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                st.push(s[i]);
            } else if (!st.empty()) {
                if ((st.top() == '(' && s[i] == ')') ||
                    (st.top() == '[' && s[i] == ']') ||
                    (st.top() == '{' && s[i] == '}')) {
                    st.pop();
                }
                else {
                    return false;
                }
            } else if (st.empty() &&
                       (s[i] == ')' || s[i] == ']' || s[i] == '}')) {
                return false;
            }
        }
        return st.empty() ? true : false;
    }
};
