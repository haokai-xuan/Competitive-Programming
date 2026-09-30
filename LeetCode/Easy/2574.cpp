class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        int leftSum = 0;
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++) {
            int rightSum = total - nums[i] - leftSum;
            ans.push_back(abs(leftSum - rightSum));
            leftSum += nums[i];
        }
        return ans;
    }
};