class Solution {
    pair<int, int> getMinMaxIdx(vector<int>& nums) {
        int currMax = nums[0];
        int currMin = nums[0];
        int maxIdx = 0, minIdx = 0;

        for (int i = 0; i < nums.size(); i++) {
            int n = nums[i];
            if (n > currMax) {
                maxIdx = i;
                currMax = n;
            }
            else if (n < currMin) {
                minIdx = i;
                currMin = n;
            }
        }
        return {minIdx, maxIdx};
    }
public:
    int minimumDeletions(vector<int>& nums) {
        auto [minIdx, maxIdx] = getMinMaxIdx(nums);
        if (minIdx == maxIdx) return 1;

        int ans = nums.size();


        // case 1 delete both from left
        ans = min(ans, max(minIdx, maxIdx) + 1);

        // case 2 delete both from right
        ans = min(ans, static_cast<int>(nums.size()) - min(minIdx, maxIdx));

        // case 3 delete one from left, one from right
        int l = min(minIdx, maxIdx);
        int r = max(minIdx, maxIdx);
        ans = min(ans, (l + 1) + (static_cast<int>(nums.size()) - r));

        return ans;
    }
};