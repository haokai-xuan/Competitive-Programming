class Solution {
    bool containsZero(int n) {
        while (n > 0) {
            if (n % 10 == 0)
                return true;
            n /= 10;
        }
        return false;
    }
public:
    vector<int> getNoZeroIntegers(int n) {
        for (int i = 1; i < n; i++) {
            if (!containsZero(i) && !containsZero(n - i))
                return {i, n - i};
        }
        return {};
    }
};