class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        stack<int> st;
        int ans = 0;
        for (int i = 0; i < heights.size(); i++) {
            while (!st.empty() && heights[i] < heights[st.top()]) {       
                int index = st.top();
                st.pop();
                int width = st.empty() ? i : i - (st.top() + 1);
                ans = max(ans, width * heights[index]);
            }
            st.push(i);
            
        }

        return ans;
    }
};