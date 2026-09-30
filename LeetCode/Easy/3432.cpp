class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int mod = 0;
        for (int i = 0; i < nums.size(); i++) {
            mod = (mod + nums[i]) % 2;
        }
        return !mod ? nums.size() - 1 : 0;
    }
};