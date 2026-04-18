class Solution {
public:
    int mirrorDistance(int n) {
        int copy = n;
        int reverse = 0;
        while (n) {
            reverse *= 10;
            reverse += n % 10;
            n /= 10;
        }

        return abs(copy - reverse);
    }
};