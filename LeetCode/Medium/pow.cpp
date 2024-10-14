class Solution {
public:
    double myPow(double x, int n) {
        double result = helper(x, n);

        return ((n < 0) ? (1 / result) : (result));
    }

    double helper(double x, int n) {
        if (x == 0) {
            return 0;
        } else if (n == 0) {
            return 1;
        }

        double result = helper(x, n/2);
        result *= result;

        return ((n % 2) ? (result * x) : result);
    }
};
