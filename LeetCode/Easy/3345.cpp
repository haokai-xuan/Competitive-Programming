class Solution {
    int digitProduct(int n) {
        int ans = 1;
        while (n) {
            ans *= n % 10;
            n /= 10;
        }
        return ans;
    }
public:
    int smallestNumber(int n, int t) {
        while (true) {
            if (digitProduct(n) % t == 0) return n;
            n++;
        }
    }
};