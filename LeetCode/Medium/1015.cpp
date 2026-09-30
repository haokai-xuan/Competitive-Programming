class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if (k % 2 == 0 || k % 5 == 0) return -1;
        int i = 1;
        int ans = 1;
        while (i % k) {
            i = (i * 10 + 1) % k;
            ans++;
        }
        return ans;
    }
};