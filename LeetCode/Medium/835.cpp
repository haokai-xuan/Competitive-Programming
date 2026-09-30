class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        vector<pair<int, int>> a, b;
        int n = img1.size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (img1[i][j]) a.push_back({i, j});
                if (img2[i][j]) b.push_back({i, j});
            }
        }

        vector<vector<int>> diff(2 * n, vector<int>(2 * n, 0));
        int ans = 0;

        for (int i = 0; i < a.size(); i++) {
            int ar = a[i].first;
            int ac = a[i].second;

            for (int j = 0; j < b.size(); j++) {
                int br = b[j].first;
                int bc = b[j].second;

                int dr = br - ar + n;
                int dc = bc - ac + n;

                diff[dr][dc]++;
                ans = max(ans, diff[dr][dc]);
            }
        }

        return ans;
    }
};