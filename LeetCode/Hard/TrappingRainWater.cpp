class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> maxLeft(n);
        maxLeft[0] = 0;
        vector<int> maxRight(n);
        maxRight[n - 1] = 0;
        for (int i = 1; i < n; i++) {
            maxLeft[i] = max(maxLeft[i - 1], height[i - 1]);
            maxRight[n - i - 1] = max(maxRight[n - i], height[n - i]);
        }
        vector<int> minLR(n);
        for (int i = 0; i < n; i++)
            minLR[i] = min(maxLeft[i], maxRight[i]);

        int ans = 0;
        for (int i = 0; i < n; i++) {
            int trapped = minLR[i] - height[i];
            if (trapped > 0) ans += trapped;
        }

        return ans;
    }
};