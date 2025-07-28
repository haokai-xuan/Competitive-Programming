class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> mp;
        vector<vector<int>> times(nums.size() + 1); // a vector of vectors where the i-th vector are the elements that appear i times
        for (int& n : nums) {
            ++mp[n];
        }
        for (auto& [key, val] : mp) {
            times[val].push_back(key);
        }
        int cnt = 0;
        auto it = times.rbegin();
        vector<int> ans;
        while (cnt < k) {
            if (!it->empty()) {
                for (int& i : *it) {
                    ans.push_back(i);
                }
                cnt += it->size();
            }
            ++it;
        }
        return ans;
    }
};