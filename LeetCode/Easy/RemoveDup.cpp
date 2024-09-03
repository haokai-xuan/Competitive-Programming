class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int prevNum = nums[0];
        int prevIndex = 0;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != prevNum) {
                nums[++prevIndex] = nums[i];
                prevNum = nums[i];
            }
        }
        return prevIndex + 1;
    }
};
