class Solution {
    bool insideRect(vector<int>& tl, vector<int>& br, vector<int>& p) {
        return p[0] >= tl[0] && p[0] <= br[0] && p[1] <= tl[1] && p[1] >= br[1];
    }
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int ans = 0;
        for (auto& p1 : points) {
            for (auto& p2 : points) {
                if (p1 == p2) continue;
                
                if (!(p1[0] <= p2[0] && p1[1] >= p2[1])) continue;

                bool good = true;
                for (auto& p3 : points) {
                    if (p2 == p3 || p1 == p3) continue;
                    if (insideRect(p1, p2, p3)) {
                        good = false;
                        break;
                    }
                }
                if (good) ans++;
            }
        }
        return ans;
    }
};