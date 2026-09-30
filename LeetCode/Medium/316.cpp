class Solution {
public:
    string removeDuplicateLetters(string s) {
        stack<char> st;
        vector<int> lastOccPos(26, -1);
        vector<bool> used(26, false);
        for (int i = 0; i < s.size(); i++) {
            lastOccPos[s[i] - 'a'] = max(lastOccPos[s[i] - 'a'], i);
        }

        for (int i = 0; i < s.size(); i++) {
            if (!used[s[i] - 'a']) {
                while (!st.empty() && s[i] < st.top() && lastOccPos[st.top() - 'a'] > i) {
                    used[st.top() - 'a'] = false;
                    st.pop();
                }
                st.push(s[i]);
                used[s[i] - 'a'] = true;
            }
        }
        string ans = "";
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};