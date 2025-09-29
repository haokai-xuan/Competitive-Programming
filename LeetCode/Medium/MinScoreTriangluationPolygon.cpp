class Solution {
    vector<vector<int>> dp;
    int dfs(int i, int j, vector<int>& values) {
        if (i + 1 == j) return 0;
        if (j - i == 2)
            return values[i] * values[i + 1] * values[j];
        if (dp[i][j] != -1) return dp[i][j];
        int ans = INT_MAX;
        for (int k = i + 1; k < j; k++) {
            int weight = values[i] * values[k] * values[j];
            int left = dfs(i, k, values);
            int right = dfs(k, j, values);
            int curr = weight + left + right;
            if (curr < ans) {
                ans = curr;
                dp[i][j] = ans;
            }
        }

        return ans;
    }
public:
    int minScoreTriangulation(vector<int>& values) {
        dp.assign(values.size(), vector<int>(values.size(), -1));
        return dfs(0, values.size() - 1, values);
    }
};