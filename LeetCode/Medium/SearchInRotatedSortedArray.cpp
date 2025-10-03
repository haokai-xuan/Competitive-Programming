class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0, right = n - 1;
        int pivot = 0;
        while (left < right) {
            int mid = (left + right) / 2;
            if (mid + 1 < n && nums[mid + 1] < nums[mid]) {
                pivot = mid + 1;
                break;
            }
            if (mid - 1 >= 0 && nums[mid - 1] > nums[mid]) {
                pivot = mid;
                break;
            }
            if (nums[n - 1] > nums[mid]) right = mid - 1;
            else left = mid + 1;
        }
        
        if (nums[pivot] > target || nums[pivot - 1 < 0 ? n - 1 : pivot - 1] < target) return -1;

        if (target <= nums[n - 1]) {
            left = pivot;
            right = n - 1;
        }
        else {
            left = 0;
            right = pivot - 1;
        }

        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) return mid;
            if (target < nums[mid]) right = mid - 1;
            else left = mid + 1;
        }

        return -1;
    }
};