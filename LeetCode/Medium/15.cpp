class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int i = 0; i < nums.size(); i++) {
            int l = i + 1, r = nums.size() - 1;
            int target = -nums[i];
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            while (l < r) {
                if (i == l) {
                    l++;
                    continue;
                }
                if (i == r) {
                    r--;
                    continue;
                }
                int sum = nums[l] + nums[r];
                if (sum > target) r--;
                else if (sum < target) l++;
                else {
                    ans.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    while (l < nums.size() && nums[l] == nums[l - 1]) l++;
                    r--;
                    while (r >= 0 && nums[r] == nums[r + 1]) r--;
                }
            }
        }
        return ans;
    }
};