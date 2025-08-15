class Solution {
public:
    bool isPowerOfFour(int n) {
        long long curr = 1;
        for (int i = 0; i <= 15; i++) {
            if (curr == n) return true;
            curr *= 4;
        }
        return false;
    }
};