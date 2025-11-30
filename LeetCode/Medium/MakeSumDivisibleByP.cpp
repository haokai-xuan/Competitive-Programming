class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        unordered_map<int, int> mp;
        mp[0] = -1;
        int ps = 0;
        int minRemoveSize = nums.size();
        int totalSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            totalSum = (totalSum + nums[i]) % p;
        }
        int mod = totalSum % p;
        if (totalSum % p == 0) return 0;
        for (int i = 0; i < nums.size(); i++) {
            ps = (ps + nums[i]) % p;
            mp[ps] = i;
            int toRemove = (ps - mod + p) % p;
            if (mp.count(toRemove)) {
                minRemoveSize = min(minRemoveSize, i - mp[toRemove]);
            }
        }
        return (minRemoveSize == nums.size()) ? -1 : minRemoveSize;
    }
};