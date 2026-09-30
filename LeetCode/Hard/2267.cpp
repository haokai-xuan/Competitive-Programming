class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        if ((m + n - 1) % 2) return false;
        if (grid[0][0] == ')' || grid[m - 1][n - 1] == '(') return false;

        // dp[i][j][bal] denotes whether can get to grid[i][j] with balance bal
        vector<vector<vector<bool>>> dp(m, vector<vector<bool>>(n, vector<bool>(m + n, false)));

        dp[0][0][1] = true;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) continue;
                int change = grid[i][j] == '(' ? 1 : -1;

                for (int bal = 0; bal <= n + m - 1; bal++) {
                    bool reachable = false;

                    if (i > 0)
                        reachable |= dp[i - 1][j][bal];
                    if (j > 0)
                        reachable |= dp[i][j - 1][bal];

                    if (!reachable) continue;

                    int newBal = bal + change;
                if (newBal >= 0 && newBal <= n + m - 1)
                        dp[i][j][newBal] = true;
                }
            }
        }

        return dp[m - 1][n - 1][0];
    }
};