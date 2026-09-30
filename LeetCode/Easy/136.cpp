class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int& i : nums) mp[i]++;
        for (auto& [key, freq] : mp)
            if (freq == 1) return key;
        return 0;
    }
};