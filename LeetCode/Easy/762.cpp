class Solution {
    int isPrime(int x) {
        if (x == 1) return false;
        for (int i = 2; i * i <= x; i++) {
            if (x % i == 0) return false;
        }
        return true;
    }
    bool primeSetBits(int x) {
        int cnt = 0;
        while (x) {
            if (x & 1) cnt++;
            x >>= 1;
        }
        return isPrime(cnt);
    }
public:
    int countPrimeSetBits(int left, int right) {
        int ans = 0;
        for (int i = left; i <= right; i++) {
            if (primeSetBits(i)) ans++;
        }
        return ans;
    }
};