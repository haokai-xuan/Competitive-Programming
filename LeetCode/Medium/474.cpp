class Solution {
    int solve(vector<string>& strs, int m, int n, int i, vector<vector<vector<int>>>& dp) {
        if (i == strs.size()) return 0;
        if (m < 0 || n < 0) return INT_MIN;
        if (dp[i][m][n] != -1) return dp[i][m][n];

        int zeros = count(strs[i].begin(), strs[i].end(), '0');
        int ones = count(strs[i].begin(), strs[i].end(), '1');

        int notPick = solve(strs, m, n, i + 1, dp);
        int pick = INT_MIN;
        if (zeros <= m && ones <= n) pick = 1 + solve(strs, m - zeros, n - ones, i + 1, dp);
        
        dp[i][m][n] = max(notPick, pick);
        return dp[i][m][n];
    }
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<vector<int>>> dp(strs.size(), vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));
        return solve(strs, m, n, 0, dp);
    }
};