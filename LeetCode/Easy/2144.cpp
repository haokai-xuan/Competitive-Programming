class Solution {
public:
    int minimumCost(vector<int>& cost) {
        if (cost.size() <= 2) return accumulate(cost.begin(), cost.end(), 0);
        int ans = 0;
        sort(cost.begin(), cost.end());
        for (int i = cost.size() - 1; i >= 2; i -= 3) {
            ans += cost[i] + cost[i - 1];
        }
        if (cost.size() % 3) {
            for (int i = 0; i < cost.size() % 3; i++) {
                ans += cost[i];
            }
        }

        return ans;
    }
};