class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;
        vector<int> prefix(nums.size() + 1, 1); // prefix[i] = product from nums[0] to nums[i - 1] inclusive
        vector<int> suffix(nums.size() + 1, 1); // suffix[i] = product from nums[i] to nums[nums.size() - 1] inclusive
        for (int i = 0; i < nums.size(); ++i) {
            prefix[i + 1] = prefix[i] * nums[i];
        }
        for (int i = nums.size() - 1; i >= 0; --i) {
            suffix[i] = suffix[i + 1] * nums[i];
        }

        for (int i = 0; i < nums.size(); ++i)
            ans.push_back(prefix[i] * suffix[i + 1]);

        return ans;
    }
};