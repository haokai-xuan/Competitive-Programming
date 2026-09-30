class Solution {
public:
    const int dx[4] = {0, 0, 1, -1};
    const int dy[4] = {1, -1, 0, 0};

    int rows;
    int cols;

    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        rows = grid.size();
        cols = grid[0].size();
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == '1') {
                    dfs(grid, i, j);
                    ans++;
                }
            }
        }
        return ans;
    }
private:
    void dfs(vector<vector<char>> &grid, int r, int c) {
        grid[r][c] = '#';
        for (int i = 0; i < 4; i++) {
            int nr = dx[i] + r;
            int nc = dy[i] + c;
            if (nr >= 0 && nr < rows && nc >= 0 &&  nc < cols) {
                if (grid[nr][nc] == '1') {
                    grid[nr][nc] = '#';
                    dfs(grid, nr, nc);
                }
            }
        }
    }
};