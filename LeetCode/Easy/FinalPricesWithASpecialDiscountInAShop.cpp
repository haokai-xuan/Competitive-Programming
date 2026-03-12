class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int> st; // increasing stack
        vector<int> ans(prices.size());
        for (int i = 0; i < prices.size(); i++) {
            while (!st.empty() && prices[i] <= prices[st.top()]) {
                ans[st.top()] = prices[st.top()] - prices[i];
                st.pop();
            }
            st.push(i);
        }

        while (!st.empty()) {
            ans[st.top()] = prices[st.top()];
            st.pop();
        }
        return ans;
    }
};