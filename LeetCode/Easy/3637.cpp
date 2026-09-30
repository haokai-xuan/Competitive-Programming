class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        if (nums.size() == 3) return false;
        if (nums[0] >= nums[1]) return false;
        bool seg1End = false, seg2End = false;
        for (int i = 0; i < nums.size(); i++) {
            if (i == 0) continue;
            if (nums[i] == nums[i - 1]) return false;
            if (nums[i] < nums[i - 1]) {
                if (seg1End && seg2End) return false;
                seg1End = true;
            }
            else if (nums[i] > nums[i - 1]) {
                if (seg1End) seg2End = true;
            }
        }
        return nums[nums.size() - 1] > nums[nums.size() - 2] && seg2End;
    }
};