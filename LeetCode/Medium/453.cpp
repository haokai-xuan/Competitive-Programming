class Solution {
public:
    int minMoves(vector<int>& nums) {
        int smallest = INT_MAX;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            smallest = min(smallest, nums[i]);
        }
        for (int i = 0; i < nums.size(); i++) {
            ans += nums[i] - smallest;
        }
        return ans;
    }
};