class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int prefix_sum = 0;
        int pre_max = 0;
        int pre_min = 0;
        int res = 0;

        int len = nums.size();
        for (int i = 0; i < len; i++) {
            prefix_sum += nums[i];

            res = max(res, max(abs(prefix_sum - pre_min), abs(prefix_sum - pre_max)));

            pre_max = max(pre_max, prefix_sum);
            pre_min = min(pre_min, prefix_sum);

        }

        return res;
    }
};