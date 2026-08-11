class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int i = 1;
        int sum = nums[0];
        unordered_set<int> s;
        s.insert(nums[0]);
        while (i < nums.size() && nums[i] == nums[i - 1] + 1) {
            sum += nums[i];
            i++;
        }

        int x = sum;
        for (int j = i; j < nums.size(); j++) {
            s.insert(nums[j]);
            if (nums[j] == x) x++;
        }

        while (s.count(x)) x++;

        return x;
    }
};