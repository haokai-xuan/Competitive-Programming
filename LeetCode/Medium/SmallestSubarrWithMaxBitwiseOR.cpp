class Solution {
    vector<int> getSetIndices(int x) {
        vector<int> ans;
        for (int i = 0; i < 31; i++) {
            if (x & (1 << i))
                ans.push_back(i);
        }
        return ans;
    }
    vector<int> getUnsetIndices(int goal, int curr) {
        vector<int> ans;
        for (int i = 0; i < 31; i++) {
            if ((goal & (1 << i)) && !(curr & (1 << i)))
                ans.push_back(i);
        }
        return ans;
    }
    void updateSetIndices(vector<int>& v, vector<int>& indices, int index) {
        for (int& i : indices) {
            v[i] = min(v[i], index);
        }
    }
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int maxOr = 0;
        vector<int> ans(nums.size());
        vector<int> v(31, INT_MAX); // v[i] represents lowest index in nums vector where the i-th bit of nums[v[i]] is set to 1
        for (int i = nums.size() - 1; i >= 0; --i) {
            maxOr |= nums[i];
            int currOr = nums[i];
            vector<int> newSetIndices = getSetIndices(nums[i]);
            if (currOr == maxOr) {
                ans[i] = 1;
            }
            else {
                int maxIndex = -1;
                vector<int> unsetIndices = getUnsetIndices(maxOr, currOr);
                for (int& i : unsetIndices)
                    maxIndex = max(maxIndex, v[i]);
                ans[i] = maxIndex - i + 1;
            }
            updateSetIndices(v, newSetIndices, i);
        }

        return ans;
    }
};