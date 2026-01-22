class Solution {
    int getSmallestPairIndex(vector<int>& nums) {
        int index = 0;
        int smallest = INT_MAX;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] + nums[i + 1] < smallest) {
                smallest = nums[i] + nums[i + 1];
                index = i;
            }
        }
        return index;
    }
public:
    int minimumPairRemoval(vector<int>& nums) {
        int ans = 0;
        while (!is_sorted(nums.begin(), nums.end())) {
            int smallestIndex = getSmallestPairIndex(nums);
            nums[smallestIndex] = nums[smallestIndex] + nums[smallestIndex + 1];
            for (int j = smallestIndex + 1; j < nums.size() - 1; j++) nums[j] = nums[j + 1];
            nums.pop_back();
            ans++;
        }
        return ans;
    }
};