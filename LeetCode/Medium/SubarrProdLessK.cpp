class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1)
            return 0;

        int left = 0;
        int right = 0;
        
        int len = nums.size();
        int curr = 1;
        int ans = 0;
        for (right = 0; right < len; right++) {
            curr *= nums[right];

            while (curr >= k) {
                curr /= nums[left];
                left++;
            }
            ans += right - left + 1;
        }

        return ans;
    }
};