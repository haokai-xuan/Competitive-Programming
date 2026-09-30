class Solution {
    int gcd(int a, int b) {
        if (a == 0 && b == 0) return 0;
        if (a == 0 || b == 0) return max(a, b);

        return gcd(b, a % b);
    }
public:
    int gcdOfOddEvenSums(int n) {
        int currOdd = 1;
        int currEven = 2;
        int sumOdd = 0;
        int sumEven = 0;
        for (int i = 0; i < n; i++) {
            sumOdd += currOdd;
            sumEven += currEven;
            currOdd += 2;
            currEven += 2;
        }
        return gcd(sumOdd, sumEven);
    }
};