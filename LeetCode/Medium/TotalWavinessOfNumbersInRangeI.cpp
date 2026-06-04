class Solution {
    int getWaviness(int n) {
        int ans = 0;
        int prev = n % 10;
        n /= 10;
        int curr = n % 10;
        n /= 10;

        while (n) {
            int next = n % 10;
            n /= 10;

            if (curr > next && curr > prev) ans++;
            else if (curr < next && curr < prev) ans++;

            prev = curr;
            curr = next;
        }

        return ans;
    }
public:
    int totalWaviness(int num1, int num2) {
        int ans = 0;
        for (int i = num1; i <= num2; i++) {
            ans += getWaviness(i);
        }
        return ans;
    }
};