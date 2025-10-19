class Solution {
    bool onY(int r, int c, int n) {
        int mid = n / 2;
        if (r == c && r < mid)
            return true;
        if (r + c == n - 1 && r < mid)
            return true;
        if (r >= mid && c == mid)
            return true;
        return false;
    }
    int solve(int yVal, int notYVal, vector<vector<int>>& grid) {
        int n = grid.size();
        int yFails = 0, notYFails = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != yVal && onY(i, j, n))
                yFails++;
                else if (grid[i][j] != notYVal && !onY(i, j, n))
                    notYFails++;
            }
        }
        return yFails + notYFails;
    }
public:
    int minimumOperationsToWriteY(vector<vector<int>>& grid) {
        int ans = INT_MAX;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (i != j) {
                    ans = min(ans, solve(i, j, grid));
                }
            }
        }
        return ans;
    }
};