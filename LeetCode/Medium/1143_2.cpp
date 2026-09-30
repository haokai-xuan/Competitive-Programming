class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        return solve(text1, text2);
    }

private:
    int solve(string &s1, string &s2) {
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (s1[i] == s2[j]) {
                    dp[i + 1][j + 1] = 1 + dp[i][j];
                }
                else
                    dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
            }
        }

        return dp[n][m];
    }
};