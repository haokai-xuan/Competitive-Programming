class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int prevOnePos = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i]) {
                if (prevOnePos == -1) {
                    prevOnePos = i;
                }
                else if (i - prevOnePos - 1 < k) return false;
                else prevOnePos = i;
            }
        }
        return true;
    }
};