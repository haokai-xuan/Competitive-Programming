class Solution {
public:
    int maxProduct(int n) {
        int max1 = -1, max2 = -1;
        while (n) {
            int digit = n % 10;
            n /= 10;

            if (digit > max1) {
                max2 = max1;
                max1 = digit;
            }
            else if (digit == max1) max2 = max1;
            else max2 = max(max2, digit);
        }
        return max1 * max2;
    }
};