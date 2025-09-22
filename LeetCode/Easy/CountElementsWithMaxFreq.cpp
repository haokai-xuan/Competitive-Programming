class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (auto& i : nums)
            mp[i]++;
        int maxFreq;
        int ans = 0;
        for (auto& [i, j] : mp) {
            if (j > maxFreq) {
                maxFreq = j;
                ans = j;
            }
            else if (j == maxFreq)
                ans += j;
        }
        return ans;
    }
};