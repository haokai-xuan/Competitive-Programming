class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;
        }
        unordered_map<int, int> freq_freq;
        for (auto& [num, f] : freq) {
            freq_freq[f]++;
        }
        for (auto& x : nums) {
            if (freq_freq[freq[x]] == 1) return x;
        }
        return -1;
    }
};