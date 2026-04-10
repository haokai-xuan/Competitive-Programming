class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int ans = INT_MAX;
        unordered_map<int, vector<int>> mp;

        // formula = 2 * (k - i)
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]].push_back(i);
        }

        for (auto& [el, positions] : mp) {
            if (positions.size() < 3) continue;
            for (int i = 0; i < positions.size() - 2; i++) {
                ans = min(ans, 2 * (positions[i + 2] - positions[i]));
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};