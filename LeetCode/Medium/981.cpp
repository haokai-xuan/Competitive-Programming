class TimeMap {
    int bisectRight(const vector<pair<int, string>>& v, int timestamp) {
        int left = 0, right = v.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (v[mid].first <= timestamp)
                left = mid + 1;
            else
                right = mid;
        }
        return left;
    }
public:
    unordered_map<string, vector<pair<int, string>>> mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        string ans = "";
        int index = bisectRight(mp[key], timestamp) - 1;
        if (index >= 0 && index < mp[key].size())
            ans = mp[key][index].second;

        return ans;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */