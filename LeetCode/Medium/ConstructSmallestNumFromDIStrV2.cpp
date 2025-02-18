class Solution {
public:
    string smallestNumber(string pattern) {
        stack<char> st;
        string ans = "";
        int len = pattern.size();

        for (int i = 0; i <= len; i++) {
            st.push((i + 1) + '0');

            if (i < len && pattern[i] == 'I') {
                while (!st.empty()) {
                    char c = st.top();
                    st.pop();
                    ans += c;
                }
            }
        }
        while (!st.empty()) {
            char c = st.top();
            st.pop();
            ans += c;
        }
        return ans;
    }
};