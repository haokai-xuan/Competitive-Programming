class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int F_0 = 0;
        int numSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            F_0 += i * nums[i];
            numSum += nums[i];
        }
        int ans = F_0;
        int F_prev = F_0;
        int n = nums.size();

        for (int i = 1; i < nums.size(); i++) {
            int F_i = F_prev + numSum - n * nums[n - i];
            ans = max(ans, F_i);
            F_prev = F_i;
        }

        return ans;
    }
};