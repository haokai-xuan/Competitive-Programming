class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (int i = 0; i < tokens.size(); i++) {
            const string& token = tokens[i];

            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int operand2 = st.top();
                st.pop();
                int operand1 = st.top();
                st.pop();

                if (token == "+") {
                    st.push(operand1 + operand2);
                } else if (token == "-") {
                    st.push(operand1 - operand2);
                } else if (token == "*") {
                    st.push(operand1 * operand2);
                } else if (token == "/") {
                    st.push(operand1 / operand2);
                }
            } else {
                int intgr = stoi(token);
                st.push(intgr);
            }
        }
        return st.top();
    }
};
