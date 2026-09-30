class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;

        for (int i = 0; i < path.size(); i++) {
            if (path[i] == '/') {
                string temp = "";
                int j = i + 1;
                while (path[j] != '/' && j < path.size()) {
                    temp += path[j];
                    j++;
                }
                i = j - 1;

                if (!temp.empty()) {
                    if (temp == "..") {
                        if (!st.empty()) {
                            st.pop();
                        }
                    } else if (temp == ".") {
                        continue;
                    } else {
                        st.push(temp);
                    }
                }
            }
        }

        string ans = "";

        while (!st.empty()) {
            ans = "/" + st.top() + ans;
            st.pop();
        }

        return ans[0] == '/' ? ans : "/";
    }
};