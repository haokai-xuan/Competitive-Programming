class Solution {
public:
    int totalMoney(int n) {
        int numFullWeeks = n / 7;
        int ans = 0;
        int nextMonday = 1;
        for (int i = 0; i < numFullWeeks; i++) {
            int a1 = i + 1;
            int a7 = a1 + 6;
            ans += 7 * (a1 + a7) / 2;
            nextMonday = a1 + 1;
        }
        int rest = n - numFullWeeks * 7;
        while (rest) {
            ans += nextMonday++;
            rest--;
        }
        return ans;
    }
};