class Solution {
    void backtrack(vector<int>& nums, int index, vector<int>& currSubset, vector<vector<int>>& subsets) {
        if (index >= nums.size()) {
            subsets.push_back(currSubset);
            return;
        }

        // Skip current index
        backtrack(nums, index + 1, currSubset, subsets);

        // Keep current index
        currSubset.push_back(nums[index]);
        backtrack(nums, index + 1, currSubset, subsets);

        currSubset.pop_back();
    }
    vector<vector<int>> getSubsets(vector<int>& nums) {
        vector<vector<int>> subsets;
        vector<int> currSubset;

        backtrack(nums, 0, currSubset, subsets);

        return subsets;
    }
public:
    int countMaxOrSubsets(vector<int>& nums) {
        vector<vector<int>> subsets = getSubsets(nums);
        map<int, int> mp;

        for (auto& s : subsets) {
            int curr = 0;
            for (int& i : s) {
                curr |= i;
            }
            ++mp[curr];
        }
        
        int ans = 0;
        for (auto& [bitwiseRes, freq] : mp)
            ans = max(ans, freq);

        return ans;
    }
};