class Solution {
    int rows, cols;
    vector<pair<int, int>> d = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
    bool dfs(int r, int c, int sf, vector<vector<int>>& distToThief, vector<vector<bool>>& visited) {
        if (r == rows - 1 && c == cols - 1) return true;
        visited[r][c] = true;
        for (int i = 0; i < d.size(); i++) {
            int dr = d[i].first, dc = d[i].second;
            int nr = r + dr, nc = c+ dc;
            if (nr >= 0 && nr < rows && nc >= 0 && nc < cols) {
                if (distToThief[nr][nc] >= sf && !visited[nr][nc] && dfs(nr, nc, sf, distToThief, visited)) {
                    return true;
                }
            }
        }
        return false;
    }
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        vector<vector<int>> distToThief(rows, vector<int>(cols, INT_MAX)); // dist to nearest thief
        queue<pair<int, int>> q;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j]) {
                    q.push({i, j});
                    distToThief[i][j] = 0;
                }
            }
        }

        // vector<pair<int, int>> d = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
        while (!q.empty()) {
            pair<int, int> p = q.front();
            q.pop();
            for (int i = 0; i < d.size(); i++) {
                int dr = d[i].first, dc = d[i].second;
                int r = p.first, c = p.second;
                int nr = r + dr, nc = c+ dc;
                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols) {
                    if (distToThief[nr][nc] == INT_MAX) {
                        distToThief[nr][nc] = distToThief[r][c] + 1;
                        q.push({nr, nc});
                    }
                }
            }
        }

        // for (auto& v : distToThief) {
        //     for (int& i : v) {
        //         cout << i << ' ';
        //     }
        //     cout << '\n';
        // }
        int lo = 0, hi = distToThief[0][0]; // range of possible safety factors
        while (lo < hi) 
        {
            vector<vector<bool>> visited(rows, vector<bool>(cols, false));
            int mid = (lo + hi + 1) / 2;
            if (distToThief[0][0] < mid) {
                hi = mid - 1;
                continue;
            }

            if (dfs(0, 0, mid, distToThief, visited)) lo = mid;
            else hi = mid - 1;
        }

        return lo;
    }
};