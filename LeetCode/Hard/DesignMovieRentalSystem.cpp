class MovieRentingSystem {
    struct Triple {
        int first, second, third;
        bool operator<(const Triple& other) const {
            if (first != other.first) return first < other.first;
            else if (second != other.second) return second < other.second;
            return third < other.third;
        }
    };
    set<Triple> rented;
    unordered_map<int, set<pair<int, int>>> unrented;
    unordered_map<int, unordered_map<int, int>> price;
public:
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for (auto& v : entries) {
            int shop = v[0];
            int movie = v[1];
            int p = v[2];
            unrented[movie].insert({p, shop});
            price[shop][movie] = p;
        }
    }
    
    vector<int> search(int movie) {
        vector<int> ans;
        if (unrented.count(movie)) {
            for (auto& p : unrented[movie]) {
                ans.push_back(p.second);
                if (ans.size() >= 5) break;
            }
        }
        return ans;
    }
    
    void rent(int shop, int movie) {
        int p = price[shop][movie];
        rented.insert({p, shop, movie});
        unrented[movie].erase({p, shop});
    }
    
    void drop(int shop, int movie) {
        int p = price[shop][movie];
        rented.erase({p, shop, movie});
        unrented[movie].insert({p, shop});
    }
    
    vector<vector<int>> report() {
        vector<vector<int>> ans;
        for (auto&p : rented) {
            ans.push_back({p.second, p.third});
            if (ans.size() >= 5) break;
        }

        return ans;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */