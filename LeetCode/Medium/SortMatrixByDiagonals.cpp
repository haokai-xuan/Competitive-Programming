class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        // top cols excluding first and last
        for (int i = 1; i < n - 1; i++) {
            int r = 0;
            int c = i;
            vector<int> diag;
            while (r < n && c < n) {
                diag.push_back(grid[r][c]);
                r++;
                c++;
            }

            sort(diag.begin(), diag.end());

            r = 0;
            c = i;
            int num = 0;
            while (r < n && c < n) {
                grid[r][c] = diag[num];
                num++;
                r++;
                c++;
            }
        }

        // left rows excluding last
        for (int i = 0; i < n - 1; i++) {
            int r = i;
            int c = 0;
            vector<int> diag;
            while (r < n && c < n) {
                diag.push_back(grid[r][c]);
                r++;
                c++;
            }

            sort(diag.begin(), diag.end(), greater<>());

            r = i;
            c = 0;
            int num = 0;
            while (r < n && c < n) {
                grid[r][c] = diag[num];
                num++;
                r++;
                c++;
            }
        }
        
        return grid;
    }
};