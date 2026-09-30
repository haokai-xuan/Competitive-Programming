class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int r = 0, c = grid[0].size() - 1;
        int ans = 0;
        while (r < grid.size()) {
            while (c >= 0 && grid[r][c] < 0) c--;
            if (c < 0) ans += grid[0].size();
            else ans += grid[0].size() - c - 1;
            r++;
        }
        return ans;
    }
};