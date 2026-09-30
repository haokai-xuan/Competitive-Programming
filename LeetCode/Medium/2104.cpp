class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            int currMin = INT_MAX, currMax = -INT_MAX;
            for (int j = i + 1; j < nums.size(); j++) {
                currMin = min(currMin, min(nums[j], nums[i]));
                currMax = max(currMax, max(nums[j], nums[i]));
                ans += currMax - currMin;
            }
        }

        return ans;
    }
};