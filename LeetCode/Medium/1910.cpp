class Solution {
public:
    string removeOccurrences(string s, string part) {
        stack<char> st;

        for (int i = 0; i < s.size(); i++) {
            st.push(s[i]);
            if (st.size() >= part.size() && check_match(st, part, part.length())) {
                for (int j = 0; j < part.length(); j++) {
                    st.pop();
                }              
            }
        }

        string ans = "";
        while (!st.empty()) {
            ans = st.top() + ans;
            st.pop();
        }

        return ans;
    }

private:
    bool check_match(stack<char> &st, string &part, int length) {
        stack<char> temp = st;

        for (int i = length - 1; i >= 0; i--) {
            if (temp.top() != part[i]) {
                return false;
            }

            temp.pop();
        }

        return true;
    }
};