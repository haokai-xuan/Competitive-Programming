class Solution {
public:
    int bitwiseComplement(int n) {
        if (!n) return 1;
        int ans = 0;
        int idx = 0;
        while (n) {
            if (!(n & 1)) {
                ans += pow(2, idx);
            }
            n /= 2;
            idx++;
        }
        return ans;
    }
};