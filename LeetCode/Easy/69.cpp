
class Solution {
public:
    int mySqrt(int x) {
        int a = 0;
        int b = x;
        long long mid;

        while (a <= b) {
            mid = a + (b - a) / 2;

            if (mid * mid == x) {
                return mid;
            }

            if (mid * mid > x) {
                b = mid - 1;
            } else {
                a = mid + 1;
            }
        }
        return b;
    }
};
