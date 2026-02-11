class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> sorted(nums.begin(), nums.end());
        sort(sorted.begin(), sorted.end());
        unordered_map<int, int> mp;
        for (int i = nums.size() - 1; i >= 0; i--) {
            int j = i;
            while (j > 0 && sorted[j] == sorted[j - 1]) {
                j--;
            }
            mp[sorted[i]] = i == j ? i : j + 1;
        }
        for (int i = 0; i < nums.size(); i++) nums[i] = mp[nums[i]];
        return nums;
    }
};