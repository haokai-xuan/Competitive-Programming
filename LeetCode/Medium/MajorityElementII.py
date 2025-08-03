class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cutoff = nums.size() / 3;
        vector<int> ans;

        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            int curr = nums[i];
            int j = i;
            while (j < nums.size() && nums[j] == curr)
                j++;
            int freq = j - i;
            if (freq > cutoff)
                ans.push_back(curr);
            i = j - 1;
        }
        
        return ans;
    }
};