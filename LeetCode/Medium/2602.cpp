class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int count1 = 0;
        int g = 0;
        for (int& i : nums) {
            if (i == 1) count1++;
            g = gcd(g, i);
        }
        if (count1 > 0) return n - count1;
        if (g > 1) return -1;

        int minLen = INT_MAX;
        for (int i = 0; i < n - 1; i++) {
            g = nums[i];
            int currLen = 1;
            for (int j = i + 1; j < n; j++) {
                currLen++;
                g = gcd(g, nums[j]);
                if (g == 1) minLen = min(minLen, currLen);
            }
        }

        return minLen + n - 2;
    }
};