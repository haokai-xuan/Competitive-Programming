class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int run1 = 0;
        int run2 = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (run1 < k) {
                if (i >= 1 && nums[i] > nums[i - 1])
                    run1++;
                else
                    run1 = 1;
            }
            else {
                if (!run2 || nums[i] > nums[i - 1])
                    run2++;
                
                else if (nums[i - run2] > nums[i - run2 - 1]) {
                    run1 = k;
                    run2 = 1;
                }
                else {
                    run1 = 1;
                    run2 = 0;
                }
            }
            cout << run1 << ' ' << run2 << '\n';
            if (run1 == k && run2 == k) return true;
        }
        return false;
    }
};