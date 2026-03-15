class Solution {
public:
    long long countCommas(long long n) {
        map<pair<long long, long long>, long long> mp = {
            {{1, 999}, 0},
            {{1000, 999999}, 1},
            {{1000000, 999999999}, 2},
            {{1000000000, 999999999999}, 3},
            {{1000000000000, 999999999999999}, 4},
            {{1000000000000000, 1000000000000000}, 5},
        };
        long long ans = 0;
        for (auto& [p, m] : mp) {
            // cout << p.first << ' ' << p.second << ' ' << m << '\n';
            if (n < p.first) break;
            ans += m * (min(p.second, n) - p.first + 1);
        }
        return ans;
    }
};