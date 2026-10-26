class Solution {
    vector<vector<bool>> visited;
    int rows, cols;

    int dfs(int r, int c, int k, vector<vector<int>>& grid) {
        if (r < 0 || r >= rows || c < 0 || c >= cols) return 0;
        if (grid[r][c] == 0) return 0;

        visited[r][c] = true;

        int ans = grid[r][c] % k;

        for (const auto& [dr, dc] : vector<pair<int, int>>{{-1, 0}, {0, 1}, {1, 0}, {0, -1}}) {
            int nr = r + dr;
            int nc = c + dc;

            if (nr < 0 || nr >= rows || nc < 0 || nc >= cols) continue;
            if (visited[nr][nc]) continue;
            ans = (ans + dfs(nr, nc, k, grid)) % k;
        }

        return ans;
    }
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        rows = grid.size();
        cols = grid[0].size();
        visited.resize(rows, vector<bool>(cols, false));

        int ans = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (!visited[i][j] && grid[i][j] != 0) {
                    int res = dfs(i, j, k, grid);
                    if (res == 0) ans++;
                }
            }
        }

        return ans;
    }
};