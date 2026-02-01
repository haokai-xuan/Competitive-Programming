class Solution {
public:
    int countMonobit(int n) {
        if (n == 0) return 1;
        else if (n == 1) return 2;
        int i = 2;
        int cnt = 2;
        while (i * 2 - 1 <= n) {
            cnt++;
            i *= 2;
        }
        return cnt;
    }
};