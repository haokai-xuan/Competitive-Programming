class Solution {
    void replaceWithZero(vector<int>& nums, int num) {
        if (num == 0 || nums[num - 1] == 0) return;
        int next = nums[num - 1];
        nums[num - 1] = 0;
        replaceWithZero(nums, next);
    }
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        for (auto& n : nums) replaceWithZero(nums, n);
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) ans.push_back(i + 1);
        }
        return ans;
    }
};