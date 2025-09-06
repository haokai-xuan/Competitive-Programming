class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int newPtr = 0;
        for (int origPtr = 0; origPtr < nums.size(); origPtr++) {
             if (nums[newPtr] != nums[origPtr]) {
                nums[++newPtr] = nums[origPtr];
             }
        }
        return newPtr + 1;
    }
};