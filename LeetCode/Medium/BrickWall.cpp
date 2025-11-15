class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<long long, int> mp;
        for (int i = 0; i < wall.size(); i++) {
            long long ps = 0;
            for (int j = 0; j < wall[i].size() - 1; j++) {
                ps += wall[i][j];
                mp[ps]++;
            }
        }
        int maxEdge = 0;
        for (auto& [l, freq] : mp) {
            if (freq > maxEdge) maxEdge = freq;
        }
        return wall.size() - maxEdge;
    }
};