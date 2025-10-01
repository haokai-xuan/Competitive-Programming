class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int full = numBottles;
        int empty = 0;
        int ans = 0;
        while (full || empty >= numExchange) {
            cout << full << ' ' <<  empty << '\n';
            if (full) {
                empty += full;
                ans += full;
                full = 0;
            }
            else {
                full += empty / numExchange;
                empty -= full * numExchange;
            }
        }

        return ans;
    }
};