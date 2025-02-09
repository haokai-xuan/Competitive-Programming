class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long n = nums.size();
        long long total = n * n;
        long long good_pairs = 0;

        unordered_map<int, int> mp;

        good_pairs += n * (n + 1) / 2;

        for (int i = 0; i < n; i++) {
            good_pairs += mp[i - nums[i]];
            mp[i - nums[i]]++;
        }

        return total - good_pairs;
    }
};