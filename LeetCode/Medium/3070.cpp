class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> ps(rows, vector<int>(cols, 0));
        int ans = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int left = j > 0 ? ps[i][j - 1] : 0;
                int top = i > 0 ? ps[i - 1][j] : 0;
                int topLeft = i > 0 && j > 0 ? ps[i - 1][j - 1] : 0;
                ps[i][j] = grid[i][j] + left + top - topLeft;
            }
        }

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (ps[i][j] <= k) ans++;
                else break;
            }
        }
        
        return ans;
    }
};