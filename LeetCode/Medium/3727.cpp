class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long ans = 0;
        for (auto& n : nums) {
            if (n < 0) n = -n;
        }
        sort(nums.begin(), nums.end());
        int l = 0, r = nums.size() - 1;
        bool add = true;
        while (l <= r) {
            if (!add) {
                ans -= nums[l] * nums[l];
                l++;
            }
            else {
                ans += nums[r] * nums[r];
                r--;
            }
            add = !add;
        }
        return ans;
    }
};