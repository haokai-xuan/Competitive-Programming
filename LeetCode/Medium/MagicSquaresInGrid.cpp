class Solution {
    bool isMagicSquare(int tlr, int tlc, vector<vector<int>>& grid) {
        unordered_set<int> s;
        int target = grid[tlr][tlc] + grid[tlr][tlc + 1] + grid[tlr][tlc + 2];
        for (int r = tlr; r < tlr + 3; r++) {
            int sum = 0;
            for (int c = tlc; c < tlc + 3; c++) {
                if (grid[r][c] > 9 || grid[r][c] == 0) return false;
                sum += grid[r][c];
                s.insert(grid[r][c]);
            }
            if (sum != target) return false;
        }
        for (int c = tlc; c < tlc + 3; c++) {
            int sum = 0;
            for (int r = tlr; r < tlr + 3; r++) {
                sum += grid[r][c];
            }
            if (sum != target) return false;
        }
        if (grid[tlr][tlc] + grid[tlr + 1][tlc + 1] + grid[tlr + 2][tlc + 2] != target) return false;
        if (grid[tlr + 2][tlc] + grid[tlr + 1][tlc + 1] + grid[tlr][tlc + 2] != target) return false;
        if (s.size() != 9) return false;
        return true;
    }
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int ans = 0;
        if (grid.size() < 3 || grid[0].size() < 3) return 0;
        for (int r = 0; r < grid.size() - 2; r++) {
            for (int c = 0; c < grid[0].size() - 2; c++) {
                if (isMagicSquare(r, c, grid)) ans++;
            }
        }
        return ans;
    }
};