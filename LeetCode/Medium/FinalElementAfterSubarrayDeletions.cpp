class Solution {
public:
    int finalElement(vector<int>& nums) {
        int biggest = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            biggest = max(biggest, nums[i]);
        }
        if (biggest == nums[0] || biggest == nums.back()) return biggest;
        return max(nums[0], nums.back());
    }
};