class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int mid = n / 2;

        if (n == 1) {
            return 0;
        }
        
        while (true) {
            int left = mid - 1;
            int right = mid + 1;
            
            if (left < 0) {
                if (nums[mid] > nums[right]) {
                    return mid;
                }
                mid++;
            }
            else if (right >= n) {
                if (nums[mid] > nums[left]) {
                    return mid;
                }
                mid--;
            }
            else if (nums[mid] > nums[left] && nums[mid] > nums[right]) {
                return mid;
            }
            else if (nums[left] > nums[mid]) {
                mid = left;
            }
            else {
                mid = right;
            }
        }
    }
};