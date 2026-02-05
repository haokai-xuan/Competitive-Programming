class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        vector<int> ans;
        int size = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            ans.push_back(nums[((i + nums[i]) % size + size) % size]);
        }
        return ans;
    }
};