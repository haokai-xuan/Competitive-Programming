class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0];
        int prev_max = ans;

        for (int i = 1; i < nums.size(); i++) {
            prev_max = max(nums[i], prev_max + nums[i]);
            ans = max(prev_max, ans);
        }

        return ans;
    }
};