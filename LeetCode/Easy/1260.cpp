class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> lastCol(m);

        for (int i = 0; i < k; i++) {
            for (int j = 0; j < m; j++) lastCol[j] = grid[j][n - 1];

            for (int j = n - 1; j >= 1; j--) {
                for (int l = 0; l < m; l++) grid[l][j] = grid[l][j - 1];
            }

            for (int j = 0; j < m - 1; j++) grid[j + 1][0] = lastCol[j];
            grid[0][0] = lastCol[m - 1];
        }

        return grid;
    }
};