class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int& i : nums) mp[i]++;
        for (auto& [num, freq] : mp) {
            if (freq > 1) return num;
        }
        return 0;
    }
};