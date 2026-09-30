class FoodRatings {
    unordered_map<string, string> foodToCuisine;
    unordered_map<string, int> foodToRating;
    unordered_map<string, set<pair<int, string>>> cuisineToFoods;
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for (int i = 0; i < n; i++) {
            foodToCuisine[foods[i]] = cuisines[i];
            foodToRating[foods[i]] = ratings[i];
            cuisineToFoods[cuisines[i]].insert({-ratings[i], foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        int oldRating = foodToRating[food];
        string cuisine = foodToCuisine[food];
        string oldFood = cuisineToFoods[cuisine].begin()->second;

        cuisineToFoods[cuisine].erase({-oldRating, food});

        cuisineToFoods[cuisine].insert({-newRating, food});

        foodToRating[food] = newRating;
    }
    
    string highestRated(string cuisine) {
        return cuisineToFoods[cuisine].begin()->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */