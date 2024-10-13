class Solution {
public:
    int trailingZeroes(int n) {
        int cnt = 0;
        int i = 1;
        while (n / pow(5, i) >= 1) {
            cnt += n / pow(5, i);
            i++;
        }
        return cnt;
    }
};
