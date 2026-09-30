class Solution {
    vector<vector<int>> dp;
    vector<int> nums;
    vector<int> solve(int index) {
        if (index == nums.size()) return {0, -1, -1};
        if (dp[index][0] != -1) return dp[index];

        vector<int> notPick = solve(index + 1);
        vector<int> pick(3, -1);
        for (int i = 0; i < 3; i++) {
            if (notPick[i] != -1) {
                int r = (notPick[i] + nums[index]) % 3;
                pick[r] = notPick[i] + nums[index];
            }
        }
        for (int i = 0; i < 3; i++) dp[index][i] = max(pick[i], notPick[i]);
        return dp[index];
    }
public:
    int maxSumDivThree(vector<int>& nums) {
        this->nums = nums;
        dp.assign(nums.size(), vector<int>(3, -1));
        vector<int> ans = solve(0);
        return ans[0];
    }
};