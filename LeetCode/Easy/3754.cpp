class Solution {
public:
    long long sumAndMultiply(int n) {
        long long x = 0;
        long long sum = 0;
        int exp = 0;

        while (n) {
            int digit = n % 10;
            if (digit != 0) {
                x += digit * pow(10, exp);
                exp++;
            }
            n /= 10;
            sum += digit;
        }

        return x * sum;
    }
};