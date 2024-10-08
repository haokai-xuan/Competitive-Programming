class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        vector<string> ans;

        for (int i = 0; i < n; i++) {
            int j = i;

            while (j + 1 < n && nums[j + 1] == nums[j] + 1) {
                j++;
            }

            if (j > i) {
                ans.push_back(to_string(nums[i]) + "->" + to_string(nums[j]));
            } else {
                ans.push_back(to_string(nums[i]));
            }
            i = j;
        }
        return ans;
    }
};
