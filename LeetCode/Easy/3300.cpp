class Solution {
    int sumDigits(int x) {
        int s = 0;
        while (x) {
            s += x % 10;
            x /= 10;
        }
        return s;
    }
public:
    int minElement(vector<int>& nums) {
        int ans = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            nums[i] = sumDigits(nums[i]);
            ans = min(ans, nums[i]);
        }
        return ans;
    }
};