class Solution {
    int solve(int num) {
        if (num < 10)
            return num;
        int newNum = 0;
        while (num) {
            newNum += num % 10;
            num /= 10;
        }
        return solve(newNum);
    }
public:
    int addDigits(int num) {
        return solve(num);
    }
};