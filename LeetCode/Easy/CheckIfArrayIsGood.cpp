class Solution {
public:
    bool isGood(vector<int>& nums) {
        int base = nums.size() - 1;
        unordered_map<int, int> mp;
        for (auto& a : nums) {
            mp[a]++;
        }
        for (int i = 1; i < base; i++) {
            if (mp[i] != 1) return false;
        }
        return mp[base] == 2;
    }
};