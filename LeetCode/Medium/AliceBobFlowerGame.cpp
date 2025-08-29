class Solution {
public:
    long long flowerGame(int n, int m) {
        long long aliceOdds = n % 2 ? n / 2 + 1 : n / 2;
        long long aliceEvens = n - aliceOdds;

        long long bobOdds = m % 2 ? m / 2 + 1 : m / 2;
        long long bobEvens = m - bobOdds;

        return aliceOdds * bobEvens + aliceEvens * bobOdds;
    }
};