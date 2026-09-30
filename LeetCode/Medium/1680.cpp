class Solution {
    int getBitLength(int x) {
        int ans = 0;
        while (x) {
            x /= 2;
            ans++;
        }
        return ans;
    }
public:
    int concatenatedBinary(int n) {
        int MOD = 1e9 + 7;
        long long ans = 0;
        for (int i = 1; i <= n; i++) {
            int len = getBitLength(i);
            ans <<= len;
            ans |= i;
            ans %= MOD;
        }
        return ans;
    }
};