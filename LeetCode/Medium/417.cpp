class Solution {
    vector<pair<int, int>> getCandidates(vector<vector<int>>& heights, int r, int c) {
        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, 1, -1};
        vector<pair<int, int>> ans;
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr >= 0 && nr < heights.size() && nc >= 0 && nc < heights[0].size() && heights[r][c] <= heights[nr][nc])
                ans.push_back({nr, nc});
        }

        return ans;
    }
    void dfs(vector<vector<int>>& heights, int r, int c, vector<vector<pair<bool, bool>>>& v, bool isPacific, vector<vector<bool>>& visited) {
        if (visited[r][c]) return;
        visited[r][c] = true;

        if (isPacific) v[r][c].first = true;
        else v[r][c].second = true;

        for (auto& [nr, nc] : getCandidates(heights, r, c)) {
            dfs(heights, nr, nc, v, isPacific, visited);
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int r = heights.size();
        int c = heights[0].size();
        vector<vector<pair<bool, bool>>> v(r, vector<pair<bool, bool>>(c, {false, false})); // p.first denotes pacific, p.second denotes atlantic

        for (int i = 0; i < c; i++) {
            vector<vector<bool>> visited(r, vector<bool>(c, false));
            dfs(heights, 0, i, v, true, visited);
            visited = vector<vector<bool>>(r, vector<bool>(c, false));
            dfs(heights, r - 1, i, v, false, visited);
        }
        for (int i = 0; i < r; i++) {
            vector<vector<bool>> visited(r, vector<bool>(c, false));
            dfs(heights, i, 0, v, true, visited);
            visited = vector<vector<bool>>(r, vector<bool>(c, false));
            dfs(heights, i, c - 1, v, false, visited);
        }

        vector<vector<int>> ans;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (v[i][j].first && v[i][j].second) {
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};