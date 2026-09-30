class Solution {
    void markGuarded(int r, int c, vector<vector<int>>& grid) {
        int nr = r - 1;
        int nc = c;
        while (nr >= 0 && nr < grid.size() && nc >= 0 && nc < grid[0].size()) {
            if (grid[nr][nc] != 1) grid[nr][nc] = -1;
            else break;
            nr--;
        }
        nr = r + 1;
        nc = c;
        while (nr >= 0 && nr < grid.size() && nc >= 0 && nc < grid[0].size()) {
            if (grid[nr][nc] != 1) grid[nr][nc] = -1;
            else break;
            nr++;
        }
        nr = r;
        nc = c - 1;
        while (nr >= 0 && nr < grid.size() && nc >= 0 && nc < grid[0].size()) {
            if (grid[nr][nc] != 1) grid[nr][nc] = -1;
            else break;
            nc--;
        }
        nr = r;
        nc = c + 1;
        while (nr >= 0 && nr < grid.size() && nc >= 0 && nc < grid[0].size()) {
            if (grid[nr][nc] != 1) grid[nr][nc] = -1;
            else break;
            nc++;
        }
    }
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, 0));
        for (int i = 0; i < guards.size(); i++) {
            grid[guards[i][0]][guards[i][1]] = 1;
        }
        for (int i = 0; i < walls.size(); i++) {
            grid[walls[i][0]][walls[i][1]] = 1;
        }
        for (int i = 0; i < guards.size(); i++) {
            markGuarded(guards[i][0], guards[i][1], grid);
        }
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!grid[i][j]) ans++;
            }
        }
        return ans;
    }
};