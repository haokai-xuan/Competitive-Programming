class Solution {
    vector<vector<int>> visited;
    int rows, cols;
    bool dfs(int r, int c, vector<vector<int>>& grid) {
        if (r < 0 || r >= rows || c < 0 || c >= cols)
            return false;
        if (visited[r][c] || grid[r][c])
            return true;

        bool good = (r >= 1 && r < rows - 1 && c >= 1 && c < cols - 1);
        visited[r][c] = true;

        for (const auto& [dr, dc] :
             vector<pair<int, int>>{{-1, 0}, {0, 1}, {1, 0}, {0, -1}}) {
            int nr = r + dr;
            int nc = c + dc;

            if (!((r >= 1 && r < rows - 1 && c >= 1 && c < cols - 1)))
                good = false;
            good = dfs(nr, nc, grid) && good;
        }

        return good;
    }

public:
    int closedIsland(vector<vector<int>>& grid) {
        int ans = 0;
        rows = grid.size();
        cols = grid[0].size();

        visited.resize(rows, vector<int>(cols));

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 0 && !visited[i][j]) {
                    if (dfs(i, j, grid))
                        ans++;
                }
            }
        }

        return ans;
    }
};