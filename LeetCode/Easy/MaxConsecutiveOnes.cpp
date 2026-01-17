class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int left = 0;
        int ans = 0;
        for (int right = 0; right < nums.size(); right++) {
            while (right < nums.size() && nums[right] == 1) {
                if (right > 0 && nums[right - 1] == 0) left = right;
                right++;
            }
            if (right > 0 && nums[right - 1] == 1) ans = max(ans, right - left);
        }
        return ans;
    }
};