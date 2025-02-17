class Solution {
public:
    int numTilePossibilities(string tiles) {
        unordered_map<string, bool> mp;
        string curr = "";
        string rest = tiles;
        solve(mp, tiles, curr, rest);

        return mp.size();
    }

private:
    void solve(unordered_map<string, bool> &mp, string tiles, string curr, string rest) {
        if (!curr.empty() && !mp.count(curr)) {
            mp[curr] = true;
        }

        for (int i = 0; i < rest.size(); i++) {
            string temp = rest;
            temp.erase(i, 1);
            solve(mp, tiles, curr + rest[i], temp);
        }

        return;
    }
};