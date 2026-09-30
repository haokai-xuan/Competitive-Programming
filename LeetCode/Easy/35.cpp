class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left_pos = 0;
        int right_pos = nums.size() - 1;
        int mid;

        while (left_pos < right_pos) {
            mid = (left_pos + right_pos) / 2;
            if (nums[mid] < target) {
                left_pos = mid + 1;
            } else if (nums[mid] > target) {
                right_pos = mid - 1;
            }
            else{
                return mid;
            }
        }
        return (nums[left_pos] >= target) ? left_pos : left_pos + 1;
    }
};
