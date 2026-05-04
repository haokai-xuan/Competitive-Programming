class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // transpose
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // reverse rows
        for (int i = 0; i < n; i++) {
            int c = 0;
            while (c < n / 2) {
                swap(matrix[i][c], matrix[i][n - c - 1]);
                c++;
            }
        }
    }
};