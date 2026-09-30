class Solution {
public:
    int residuePrefixes(string s) {
        unordered_map<char, int> mp;
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            mp[s[i]]++;
            if (mp.size() == (i + 1) % 3) ans++;
        }
        return ans;
    }
};