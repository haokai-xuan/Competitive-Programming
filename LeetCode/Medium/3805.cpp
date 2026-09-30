class Solution {
    string normalize(const string& s) {
        string key;
        int dist = s[0] - 'a';
        for (const char& c : s) {
            char newC = 'a' + (c - 'a' - dist + 26) % 26;
            key += newC;
        }
        return key;
    }
public:
    long long countPairs(vector<string>& words) {
        long long ans = 0;
        unordered_map<string, long long> mp;
        for (string& w : words) {
            string norm = normalize(w);
            mp[norm]++;
            if (mp[norm] > 1) ans += mp[norm] - 1;
        }
        return ans;
    }
};