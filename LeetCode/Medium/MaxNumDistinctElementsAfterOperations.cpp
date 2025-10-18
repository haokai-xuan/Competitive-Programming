class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        int nextFree = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            int low = nums[i] - k;
            int high = nums[i] + k;
            if (nextFree < low)
                nextFree = low;
            if (nextFree <= high) {
                ans++;
                nextFree++;
            }
        }
        return ans;
    }
};