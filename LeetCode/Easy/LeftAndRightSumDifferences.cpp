class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        int sum = 0;
        for (int i = 0; i < n; i++) {
            left[i] = sum;
            sum += nums[i];
        }
        sum = 0;
        for (int i = n - 1; i >= 0; i--) {
            right[i] = sum;
            sum += nums[i];
        }

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            ans.push_back(abs(left[i] - right[i]));
        }
        return ans;
    }
};