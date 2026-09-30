class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ans = INT_MAX;
        int right = 0;
        int n = nums.size();
        for (int left = 0; left < n; left++) {
            while (right < n && nums[right] <= static_cast<long long>(nums[left]) * k) right++;
            ans = min(ans, n - (right - left));
        }
        return ans;
    }
};