class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            int n = nums[i];
            while (n >= 1 && n <= nums.size() && n != nums[n - 1]) {
                int other = nums[n - 1];
                nums[n - 1] = n;
                nums[i] = other;
                n = other;
            }
        }

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != i + 1) return i + 1;
        }

        return nums.size() + 1;
    }
};