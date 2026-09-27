class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;

        for (int i = 0; i < s.size();) {
            st.push(s[i]);
            if (s[i] == ')') {
                st.pop();
                string curr = "";
                int start = i;
                while (st.top() != '(') {
                    curr += st.top();
                    st.pop();
                    start--;
                }
                st.pop();
                start--;
                s.replace(start, curr.size() + 2, curr);
                for (auto& c : curr) st.push(c);
                i = start + curr.size();
            }
            else i++;
        }

        return s;
    }
};