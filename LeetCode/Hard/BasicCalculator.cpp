class Solution {
public:
    string infixToPostfix(string s) {
        stack<char> st;
        bool unary = true;
        string ans = "";

        for (int i = 0; i < s.size(); i++) {
            if (isdigit(s[i])) {
                string temp = "";
                while (isdigit(s[i])) {
                    temp += s[i];
                    i++;
                }
                --i;
                temp += ' ';
                ans += temp;
                unary = false;
            } else if (s[i] == '+' || s[i] == '-') {
                if (unary){
                    ans += "0 ";
                }
                while (!st.empty() && st.top() != '(') {
                    ans += st.top();
                    st.pop();
                }
                st.push(s[i]);
                unary = true;
            } else if (s[i] == '(') {
                st.push(s[i]);
                unary = true;
            } else if (s[i] == ')') {
                while (!st.empty() && st.top() != '(') {
                    ans += st.top();
                    st.pop();
                }
                st.pop();
            }
        }

        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        return ans;
    }

    int evaluatePostfix(string s) {
        stack<int> st;

        for (int i = 0; i < s.size(); i++) {
            if (isdigit(s[i])) {
                string temp = "";
                int j = i;
                while (s[j] != ' ' && isdigit(s[j])) {
                    temp += s[j];
                    j++;
                }
                st.push(stoi(temp));
                i = j - 1;
            } else if (s[i] == '+' || s[i] == '-') {
                int operand2 = st.top();
                st.pop();
                int operand1 = st.top();
                st.pop();

                switch (s[i]) {
                case '+':
                    st.push(operand1 + operand2);
                    break;
                case '-':
                    st.push(operand1 - operand2);
                    break;
                }
            }
        }
        return st.top();
    }

    int calculate(string s) {
        string postfix = infixToPostfix(s);
        return evaluatePostfix(postfix);
    }
};
