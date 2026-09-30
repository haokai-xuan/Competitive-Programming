class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        unordered_map<int, int> mp;
        vector<int> ans;
        for (auto& i : nums) {
            if (mp[i])
                ans.push_back(i);
            mp[i]++;
        }
        return ans;
    }
};