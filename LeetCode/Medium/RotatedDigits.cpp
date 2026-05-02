class Solution {
    bool isGood(int n) {
        int copy = n;
        int rotated = 0;
        int i = 0;
        while (n) {
            int x = n % 10;
            n /= 10;
            if (x != 0 && x != 1 && x != 8 && x != 2 && x != 5 && x != 6 && x != 9) return false;
            if (x == 0 || x == 1 || x == 8) rotated += pow(10, i) * x;
            else if (x == 5) rotated += pow(10, i) * 2;
            else if (x == 2) rotated += pow(10, i) * 5;
            else if (x == 6) rotated += pow(10, i) * 9;
            else if (x == 9) rotated += pow(10, i) * 6;
            i++;
        }
        // cout << "Rotated of " << copy << " = " << rotated << '\n';
        return rotated != copy;
    }
public:
    int rotatedDigits(int n) {
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (isGood(i)) {
                cnt++;
            }
        }
        return cnt;
    }
};