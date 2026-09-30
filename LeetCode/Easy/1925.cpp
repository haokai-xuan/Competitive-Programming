class Solution {
public:
    int countTriples(int n) {
        int ans = 0;
        for (int a = 1; a <= n; a++) {
            for (int b = 1; b <= n; b++) {
                int c_2 = a * a + b * b;
                int l = 1, r = n;
                while (l <= r) {
                    int mid = (l + r) / 2;
                    if (mid * mid == c_2) {
                        ans++;
                        break;
                    }
                    else if (mid * mid < c_2) l = mid + 1;
                    else r = mid - 1;
                }
            }
        }
        return ans;
    }
};