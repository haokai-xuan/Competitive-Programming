class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n - 1;
        while (left < right) {
            int mid = (left + right) / 2;
            if (mid + 1 < n && nums[mid + 1] < nums[mid]) return nums[mid + 1];
            if (mid - 1 >= 0 && nums[mid] < nums[mid - 1]) return nums[mid];
            if (nums[n - 1] > nums[mid]) right = mid - 1;
            else if (nums[0] < nums[mid]) left = mid + 1;
        }
        return nums[left];
    }
};