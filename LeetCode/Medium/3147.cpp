class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        vector<int> dp(n, 0);

        for (int i = n - 1; i >= 0; i--) {
            int next = i + k;
            int gain = energy[i];
            if (next < n) gain += dp[next];
            dp[i] = gain;
        }
        
        return *max_element(dp.begin(), dp.end());
    }
};