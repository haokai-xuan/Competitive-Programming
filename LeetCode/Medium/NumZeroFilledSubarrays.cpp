class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            int len = 0;
            while (i < nums.size() && nums[i] == 0) {
                len++;
                i++;
            }
            if (len != 0) {
                ans += static_cast<long long>(len) * (len + 1) / 2;
                i--;
            }
        }
        return ans;
    }
};