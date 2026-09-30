class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        const int MOD = 1e9 + 7;
        for (auto& q : queries) {
            int l = q[0], r = q[1], k = q[2], v = q[3];
            int idx = l;
            while (idx <= r) {
                nums[idx] = (static_cast<long long>(nums[idx]) * v) % MOD;
                idx += k;
            }
        }
        int ans = 0;
        for (int& i : nums) {
            ans ^= i;
        }
        return ans;
    }
};