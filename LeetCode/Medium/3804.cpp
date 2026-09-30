class Solution {
public:
    int centeredSubarrays(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            int currSum = 0;
            unordered_set<int> s;
            for (int j = i; j < nums.size(); j++) {
                s.insert(nums[j]);
                currSum += nums[j];
                if (s.count(currSum)) ans++;
            }
        }
        return ans;
    }
};