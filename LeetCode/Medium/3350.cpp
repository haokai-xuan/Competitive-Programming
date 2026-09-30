class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> runs;
        int run = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1])
                run++;
            else {
                runs.push_back(run);
                run = 1;
            }
        }
        runs.push_back(run);

        int ans = 0;
        for (int i = 0; i < runs.size() - 1; i++) {
            ans = max(ans, min(runs[i], runs[i + 1]));
            ans = max(ans, runs[i] / 2);
        }
        ans = max(ans, runs.back() / 2);
        return ans;
    }
};