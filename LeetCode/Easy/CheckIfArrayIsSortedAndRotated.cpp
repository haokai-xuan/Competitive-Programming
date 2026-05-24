class Solution {
public:
    bool check(vector<int>& nums) {
        if (nums.size() <= 2) return true;

        int cnt = 0; // Counts number of dips. cnt >= 2 -> not sorted
        for (int i = 0; i < nums.size() - 1; i++) {
            if (cnt >= 2) return false;
            if (nums[i] > nums[i + 1]) cnt++;
        }

        if (cnt >= 2) return false;

        return cnt == 0 || nums[0] >= nums[nums.size() - 1];
    }
};