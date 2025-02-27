class Solution {
public:
    int subarraySum(vector<int>& nums) {
        vector<int> ps;
        ps.push_back(nums[0]);
        int ans = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            ps.push_back(ps[i - 1] + nums[i]);
            ans += get_sum(max(0, i - nums[i]), i, ps);
        }

        return ans;
    }

private:
    int get_sum(int left, int right, vector<int> &ps) {
        if (left == 0)
            return ps[right];
        return ps[right] - ps[left - 1];
    }
};