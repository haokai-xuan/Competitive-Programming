class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int left = 0;
        vector<int> ans;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int right = sum - left - nums[i];
            ans.push_back(abs(left - right));
            left += nums[i];
        }
        return ans;
    }
};