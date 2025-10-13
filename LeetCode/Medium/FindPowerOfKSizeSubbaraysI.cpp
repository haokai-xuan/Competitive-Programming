class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        int run = 0;
        for (int i = 0; i < n; i++) {
            if (i >= 1 && nums[i] - nums[i - 1] == 1)
                run++;
            else
                run = 1;
            
            if (i >= k - 1) {
                if (run >= k)
                    ans.push_back(nums[i]);
                else
                    ans.push_back(-1);
            }
        }
        return ans;
    }
};