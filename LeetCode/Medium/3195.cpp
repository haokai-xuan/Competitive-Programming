class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int top = INT_MAX, left = INT_MAX, right = 0, bottom = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j]) {
                    top = min(top, i);
                    left = min(left, j);
                    bottom = max(top, i);
                    right = max(right, j);
                }
            }
        }
        return (bottom - top + 1) * (right - left + 1);
    }
};