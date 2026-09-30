class Solution {
public:
    int numTilePossibilities(string tiles) {
        unordered_map<char, int> mp;

        for (const char &c : tiles) {
            mp[c]++;
        }
        int cnt = solve(mp);
        return cnt;
    }

private:
    int solve(unordered_map<char, int> &mp) {
        int cnt = 0;
        for (auto &p : mp) {
            if (p.second > 0) {
                cnt += 1;
                p.second--;
                cnt += solve(mp);
                p.second++;
            }
        }

        return cnt;
    }
};