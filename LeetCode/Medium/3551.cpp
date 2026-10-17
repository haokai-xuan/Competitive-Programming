class Solution {
    int digitSum(int x) {
        int sum = 0;

        while (x) {
            sum += x % 10;
            x /= 10;
        }

        return sum;
    }
public:
    int minSwaps(vector<int>& nums) {
        vector<int> target = nums;
        sort(target.begin(), target.end(), [&](int a, int b) {
            int sa = digitSum(a);
            int sb = digitSum(b);
            return sa == sb ? a < b : sa < sb;
        });

        unordered_map<int, int> pos; // where each num is
        for (int i = 0; i < nums.size(); i++) {
            pos[nums[i]] = i;
        }

        int swaps = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (target[i] == nums[i]) continue;

            int j = pos[target[i]]; // where the needed number at i currenty is

            swap(nums[i], nums[j]);

            pos[nums[i]] = i;
            pos[nums[j]] = j;

            swaps++;
        }

        return swaps;
    }
};