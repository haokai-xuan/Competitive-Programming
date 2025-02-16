class Solution {
public:
    long long maxWeight(vector<int>& pizzas) {
        sort(pizzas.begin(), pizzas.end());
        
        long long ans = 0;
        int len = pizzas.size() / 4;
        
        int odd_days = ceil((double)len / 2);
        for (int i = 0; i < odd_days; i++) {
            // pizzas.erase(pizzas.begin());
            // pizzas.erase(pizzas.begin());
            // pizzas.erase(pizzas.begin());
            ans += pizzas.back();
            pizzas.pop_back();
        }

        len -= odd_days;
        for (int i = 0; i < len; i++) {
            // pizzas.erase(pizzas.begin());
            // pizzas.erase(pizzas.begin());
            pizzas.pop_back();
            ans += pizzas.back();
            pizzas.pop_back();
        }

        return ans;
    }
};
