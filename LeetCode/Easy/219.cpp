class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> seen;
        int left = 0;
        for (int right = 0; right < nums.size(); right++) {
            if (seen.count(nums[right])) return true;
            seen.insert(nums[right]);

            if (right - left + 1 > k) {
                seen.erase(nums[left]);
                left++;
            }
        }
        return false;
    }
};