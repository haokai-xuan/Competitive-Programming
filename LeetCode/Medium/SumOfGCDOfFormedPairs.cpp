class Solution {
    int gcd(int a, int b) {
        if (a == 0 && b == 0) return 0;
        if (a == 0 || b == 0) return max(a, b);
        return gcd(b, a % b);
    }
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        int mx = nums[0];
        vector<int> prefixGcd(n);
        for (int i = 0; i < n; i++) {
            mx = max(mx, nums[i]);
            prefixGcd[i] = gcd(nums[i], mx);
        }

        sort(prefixGcd.begin(), prefixGcd.end());
        long long ans = 0;

        int l = 0, r = n - 1;
        while (l < r) {
            ans += gcd(prefixGcd[l++], prefixGcd[r--]);
        }

        return ans;
    }
};