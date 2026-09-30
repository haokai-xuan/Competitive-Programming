class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        bool prev_odd = false;
        int even_cnt = 0;
        int odd_cnt = 0;

        const int MOD = 1e9 + 7;

        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (i == 0) {
                if (arr[i] % 2 == 1) {
                    odd_cnt++;
                    ans++;
                    prev_odd = true;
                } else {
                    even_cnt++;
                    prev_odd = false;
                }
            } else {
                prev_odd =
                    (prev_odd && arr[i] % 2 == 0) || (!prev_odd && arr[i] % 2);
                if (prev_odd) {
                    odd_cnt++;
                    ans = (ans + even_cnt + 1) % MOD;
                }
                else {
                    even_cnt++;
                    ans = (ans + odd_cnt) % MOD;
                }
            }
        }

        return ans;
    }
};