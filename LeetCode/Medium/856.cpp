class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        st.push(0);
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                st.push(0);
            }
            else {
                int curr = st.top();
                st.pop();
                int score = curr == 0 ? 1 : curr * 2;
                st.top() += score;
            }
        }
        return st.top();
    }
};