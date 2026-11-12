class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int prevDecIdx = 0;
        int prevIncIdx = 0;
        int ans = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) {
                prevDecIdx = i;
                prevIncIdx = i;
            }
            else if (nums[i] < nums[i - 1]) {
                prevIncIdx = i;
                ans = max(ans, i - prevDecIdx + 1);
            }
            else {
                prevDecIdx = i;
                ans = max(ans, i - prevIncIdx + 1);
            }
        }

        return ans;
    }
};