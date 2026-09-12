class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        vector<int> cnt(10, 0);

        for (int d : digits) {
            cnt[d]++;
        }

        int ans = 0;

        // Hundreds digit: cannot be 0
        for (int h = 1; h <= 9; h++) {
            if (cnt[h] == 0) continue;

            cnt[h]--;

            // Tens digit: anything
            for (int t = 0; t <= 9; t++) {
                if (cnt[t] == 0) continue;

                cnt[t]--;

                // Units digit: must be even
                for (int u = 0; u <= 8; u += 2) {
                    if (cnt[u] == 0) continue;

                    ans++;
                }

                cnt[t]++;
            }

            cnt[h]++;
        }

        return ans;
    }
};