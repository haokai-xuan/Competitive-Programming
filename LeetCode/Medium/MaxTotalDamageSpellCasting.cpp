class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        unordered_map<long long, long long> mp;
        for (int& p : power)
            mp[p] += p;
        vector<pair<long long, long long>> vals(mp.begin(), mp.end());
        sort(vals.begin(), vals.end());
        int n = vals.size();
        vector<int> dp(n);
        dp[0] = vals[0].second;
        for (int i = 1; i < n; i++) {
            int p = vals[i].second;
            int j = i - 1;
            while (j >= 0 && vals[i].first - vals[j].first <= 2) j--;
            if (j >= 0)
                p += dp[j];
            dp[i] = max(dp[i - 1], p);
        }

        return dp[n - 1];
    }
};