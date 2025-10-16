class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        vector<int> counts(value);
        for (int i = 0; i < nums.size(); i++) {
            counts[((nums[i] % value) + value) % value]++;
        }
        int ans = INT_MAX;
        for (int i = 0; i < value; i++) {
            ans = min(ans, i + counts[i] * value);
        }
        return ans;
    }
};