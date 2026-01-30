class Solution {
public:
    int numSub(string s) {
        int MOD = 1e9 + 7;
        int left = -1;
        int ans = 0;
        for (int right = 0; right < s.size(); right++) {
            while (right < s.size() && s[right] == '1') {
                if (left < 0) left = right;
                right++;
            }
            if (left >= 0) {
                ans += (static_cast<long long>(right - left) * (right - left + 1) / 2) % MOD;
                ans %= MOD;
                left = -1;
            }
        }
        return ans;
    }
};