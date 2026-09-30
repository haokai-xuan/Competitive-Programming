class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int expectedSum = nums.size() * (nums.size() + 1) / 2, actualSum = 0;
        int dup;
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
            if (mp[nums[i]] == 2) dup = nums[i];
            actualSum += nums[i];
        }
        return {dup, dup + expectedSum - actualSum};
    }
};