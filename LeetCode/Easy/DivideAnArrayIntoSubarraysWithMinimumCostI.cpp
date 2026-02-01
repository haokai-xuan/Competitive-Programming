class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int min = 51, min2 = 51;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < min) {
                min2 = min;
                min = nums[i];
            }
            else if (nums[i] < min2) min2 = nums[i];
        }
        return nums[0] + min + min2;
    }
};