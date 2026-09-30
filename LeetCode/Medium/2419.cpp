class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int m = -1;
        for (int& i : nums)
            m = max(m, i);
        
        int ans = 0;
        int curr = 0;
        int j;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == m) {
                curr++;
                ans = max(ans, curr);
            }
            else
                curr = 0;
        }
        return ans;
    }
};