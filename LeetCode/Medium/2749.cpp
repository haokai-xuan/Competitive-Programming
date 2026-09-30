class Solution {
    int getPopCount(long long i) {
        int cnt = 0;
        while (i > 0) {
            i &= (i - 1);
            cnt++;
        }
        return cnt;
    }
public:
    int makeTheIntegerZero(int num1, int num2) {
        for (int k = 1; k <= 60; k++) {
            long long target = num1 - (long long) k * num2;
            if (k >= getPopCount(target) && k <= target)
                return k;
        }
        return -1;
    }
};