class Solution {
public:
    int binaryGap(int n) {
        int ans = 0;
        int curr = 0;
        int prev = INT_MAX;
        while (n) {
            if (n & 1) {
                ans = max(curr - prev, ans);
                prev = curr;
            }
            curr++;
            n >>= 1;
        }
        return ans;
    }
};