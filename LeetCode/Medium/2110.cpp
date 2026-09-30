aclass Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int left = 0;
        long long ans = 0;
        for (int right = 0; right < prices.size(); right++) {
            while (right + 1 < prices.size() && prices[right] - prices[right + 1] == 1) {
                right++;
            }
            ans += static_cast<long long>(right - left + 1) * (right - left + 2) / 2;
            left = right + 1;
        }
        return ans;
    }
};