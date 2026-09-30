class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        long long ps = 0;
        vector<long long> minSum(k, LONG_LONG_MAX / 2);
        minSum[0] = 0;
        long long ans = LONG_LONG_MIN;
        for (int i = 0; i < nums.size(); i++) {
            ps += nums[i];
            ans = max(ans, ps - minSum[(i + 1) % k]);
            minSum[(i + 1) % k] = min(minSum[(i + 1) % k], ps);
        }
        return ans;
    }
};