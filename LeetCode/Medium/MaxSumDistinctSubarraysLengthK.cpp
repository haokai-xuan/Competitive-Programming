class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int left = 0;
        long long sum = 0;
        long long ans = 0;
        for (int right = 0; right < nums.size(); right++) {
            mp[nums[right]]++;
            sum += nums[right];
            while (mp[nums[right]] > 1) {
                mp[nums[left]]--;
                sum -= nums[left];
                left++;
            }
            if (right - left + 1 == k) {
                ans = max(ans, sum);
                mp[nums[left]]--;
                sum -= nums[left];
                left++;
            }
        }

        return ans;
    }
};