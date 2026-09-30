class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int cnt = 0;
        int start = 0;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) cnt++;
            while (cnt > 1) {
                if (nums[start] == 0)
                    cnt--;
                start++;
            }
            ans = max(ans, i - start);
        }
        return ans;
    }
};