class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int curr_max = 0;
        int left = 0, right = 1;

        while (right < prices.size()) {
            if (prices[right] < prices[left]) {
                left = right;
            }
            else {
                curr_max = max(curr_max, prices[right] - prices[left]);
            }
            right++;
        }

        return curr_max;
    }
};