class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int placed = 0;
        for (int& fruit : fruits) {
            for (int& basket : baskets) {
                if (basket >= fruit) {
                    basket = 0;
                    placed++;
                    break;
                }
            }
        }

        return fruits.size() - placed;
    }
};