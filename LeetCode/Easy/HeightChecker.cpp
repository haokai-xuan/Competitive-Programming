class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int ans = 0;
        vector<int> copy = heights;
        sort(copy.begin(), copy.end());
        for (int i = 0; i < heights.size(); i++) {
            if (heights[i] != copy[i])
                ans++;
        }
        return ans;
    }
};