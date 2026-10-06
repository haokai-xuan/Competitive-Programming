class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<int> st;
        int cnt = 0;
        for (auto& c : s) {
            if (c == '(') st.push(c);
            else {
                if (!st.empty()) st.pop();
                else cnt++;
            }
        }
        return cnt + st.size();
    }
};