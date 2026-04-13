class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int currMin = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) {
                currMin = min(currMin, abs(i - start));
            }
        }
        return currMin;
    }
};