class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if (nums.size() < 4) return {};
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i <= nums.size() - 4; i++) {
            if (i > 0 && nums[i] ==  nums[i - 1]) continue;
            for (int j = i + 1; j <= nums.size() - 3; j++) {
                if (j > 0 && j - 1 != i && nums[j] ==  nums[j - 1]) continue;
                int sum = nums[i] + nums[j];
                long long newTarget = static_cast<long long>(target) - sum;
                int l = j + 1, r = nums.size() - 1;
                while (l < r) {
                    if (nums[l] + nums[r] > newTarget) r--;
                    else if (nums[l] + nums[r] < newTarget) l++;
                    else  {
                        ans.push_back({nums[i], nums[j], nums[l], nums[r]});
                        l++;
                        while (l < nums.size() && nums[l] == nums[l - 1]) l++;
                        r--;
                        while (r >= 0 && nums[r] == nums[r + 1]) r--;
                    }
                }
            }
        }
        return ans;
    }
};