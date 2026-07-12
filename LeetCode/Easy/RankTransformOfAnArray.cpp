class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> copy = arr;
        sort(copy.begin(), copy.end());
        unordered_map<int, int> mp;
        int pos = 1;
        for (int i = 0; i < copy.size(); i++) {
            if (mp.count(copy[i])) continue;
            mp[copy[i]] = pos++;
        }
        for (int i = 0; i < arr.size(); i++) {
            arr[i] = mp[arr[i]];
        }
        return arr;
    }
};