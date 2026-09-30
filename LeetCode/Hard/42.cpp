class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();
        vector<int> left(n);
        vector<int> right(n);
        stack<int> st;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (st.empty())
            {
                st.push(height[i]);
                left[i] = 0;
            }
            else if (height[i] <= st.top())
            {
                left[i] = st.top();
            }
            else
            {
                left[i] = st.top();
                st.push(height[i]);
            }
        }
        st = {};
        for (int i = n - 1; i >= 0; i--)
        {
            if (st.empty())
            {
                st.push(height[i]);
                right[i] = 0;
            }
            else if (height[i] <= st.top())
            {
                right[i] = st.top();
            }
            else
            {
                right[i] = st.top();
                st.push(height[i]);
            }
        }

        for (int i = 0; i < n; i++)
        {
            int l = left[i], r = right[i];
            int h = min(l, r) - height[i];
            if (h > 0)
            {
                ans += h;
            }
        }
        return ans;
    }
};