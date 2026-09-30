class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int ans = 0;
        int full = numBottles;
        int empty = 0;

        while (full || empty >= numExchange) {
            if (full) {
                ans += full;
                empty += full;
                full = 0;
            }
            else {
                full++;
                empty -= numExchange;
                numExchange++;
            }
        }

        return ans;
    }
};