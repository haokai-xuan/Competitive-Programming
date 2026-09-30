class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        const int MOD = 1e9 + 7;
        vector<long long> day(n + 1, 0); // day[i] = number of people that learned secret on day i
        day[1] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = i + delay; j <= min(n, i + forget - 1); j++) {
                day[j] = (day[j] + day[i]) % MOD;
            }
        }
        
        int ans = 0;
        for (int i = n - forget + 1; i <= n; i++) {
            ans = (ans + day[i]) % MOD;
        }
        return ans;
    }
};